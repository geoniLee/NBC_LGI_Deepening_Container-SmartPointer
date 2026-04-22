// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryManager.h"
#include "ItemBase.h"

// Sets default values
AInventoryManager::AInventoryManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AInventoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInventoryManager::AddItem(UItemBase* NewItem)
{
	if (NewItem == nullptr) return;

	Inventory.Add(NewItem);
	ItemMap.Add(NewItem->ItemID, NewItem);
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
	if (FoundItem == nullptr) return;
	if (!FoundItem->CanUse(this)) return;

	FoundItem->UseItem(this);
}