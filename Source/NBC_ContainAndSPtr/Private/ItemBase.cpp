// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "InventoryManager.h"

UItemBase::UItemBase() 
	: ItemID(NAME_None)
	, ItemName(TEXT(""))
	, Description(TEXT(""))
	, RequiredTitle(NAME_None)
	, Count(0)
{
}

bool UItemBase::CanUse(AInventoryManager* inventoryManager) const
{
	if (Count <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, TEXT("아이템 개수가 너무 적습니다"));
		return false;
	}
	if (!inventoryManager) {

		return false;
	}
	if (!RequiredTitle.IsNone() && !inventoryManager->HasTitle(RequiredTitle)) {
		FString msg = FString::Printf(TEXT("요구하는 Title 미보유: %s"), *RequiredTitle.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, msg);
		return false;
	}

	return true;
}

void UItemBase::UseItem(AInventoryManager* inventoryManager)
{
}
