// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"
#include "ItemBase.h"
#include "HPPotion.h"

// Sets default values
AInventoryManager::AInventoryManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AInventoryManager::BeginPlay()
{
	Super::BeginPlay();

	UHPPotion* Potion = NewObject<UHPPotion>(this);
	if (Potion == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("체력 포션 생성 실패"));
		return;
	}

	AddItem(Potion);
	FString msg = FString::Printf(TEXT("체력 포션 생성 / 개수=%d"), Potion->Count);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, msg);
}

void AInventoryManager::AddItem(UItemBase* NewItem)
{
	if (NewItem == nullptr) return;

	Inventory.Add(NewItem);
	ItemMap.Add(NewItem->ItemID, NewItem);
}

void AInventoryManager::RemoveItem(UItemBase* RItem)
{
	if (RItem == nullptr) return;

	Inventory.Remove(RItem);

	if (!RItem->ItemID.IsNone()) {
		ItemMap.Remove(RItem->ItemID);
	}
}

void AInventoryManager::BuildItemMap()
{
	ItemMap.Empty();

	for (UItemBase* Item : Inventory) {
		if (Item == nullptr || Item->ItemID.IsNone()) continue;

		ItemMap.Add(Item->ItemID, Item);
	}
}

UItemBase* AInventoryManager::FindItemByID(FName ItemID) const
{
	if (ItemID.IsNone()) return nullptr;

	UItemBase* const* FoundItem = ItemMap.Find(ItemID);
	if (FoundItem == nullptr) return nullptr;

	return *FoundItem;
}

void AInventoryManager::AddTitle(FName NewTitle)
{
	if (NewTitle.IsNone()) return;

	OwnedTitles.Add(NewTitle);
}

bool AInventoryManager::HasTitle(FName Title)
{
	return OwnedTitles.Contains(Title);
}

bool AInventoryManager::CanUseItem(FName ItemID)
{
	UItemBase* FoundItem = FindItemByID(ItemID);
	if(FoundItem == nullptr) return false;

	return FoundItem->CanUse(this);
}

void AInventoryManager::UseItemByID(FName ItemID)
{
	UItemBase* FoundItem = FindItemByID(ItemID);
	if (FoundItem == nullptr) {
		FString msg = FString::Printf(TEXT("아이템을 찾지 못함: %s"), *ItemID.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, msg);
		return;
	}
	if (!FoundItem->CanUse(this)) return;

	FoundItem->UseItem(this);

	if (FoundItem->Count <= 0) {
		RemoveItem(FoundItem);
	}
}