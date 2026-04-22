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
	if (Count <= 0) return false;
	if (!inventoryManager) return false;
	if (!RequiredTitle.IsNone() && !inventoryManager->HasTitle(RequiredTitle)) return false;

	return true;
}

void UItemBase::UseItem(AInventoryManager* inventoryManager)
{
}
