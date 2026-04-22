// Fill out your copyright notice in the Description page of Project Settings.


#include "HPPotion.h"

UHPPotion::UHPPotion() : HealAmount(30)
{
	ItemID = FName(TEXT("101"));
	ItemName = TEXT("HPPotion");
	Description = TEXT("체력을 30 회복합니다. \n칭호\"Starter\" 필요");
	RequiredTitle = FName(TEXT("Starter"));
	Count = 5;
}

void UHPPotion::UseItem(AInventoryManager* InventoryManager)
{
	if (!CanUse(InventoryManager)) return;

	// 플레이어 회복

	Count--;

	// 결과 로그
}
