// Fill out your copyright notice in the Description page of Project Settings.


#include "HighHPPotion.h"

UHighHPPotion::UHighHPPotion() : HealAmount(50)
{
	ItemID = FName(TEXT("102"));
	ItemName = TEXT("상급 체력 포션");
	Description = TEXT("체력을 50 회복합니다. \n칭호\"PotionAddict\" 필요");
	RequiredTitle = FName(TEXT("PotionAddict"));
	Count = 5;
}

void UHighHPPotion::UseItem(AInventoryManager* InventoryManager)
{
	if (!CanUse(InventoryManager)) {
		FString msg = FString::Printf(TEXT("%s 사용 실패"), *ItemName);
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, msg);
		return;
	}

	Count--;
	FString msg = FString::Printf(TEXT("%s 사용 성공 / 회복량 %.1f / 남은 개수: %d"), *ItemName, HealAmount, Count);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, msg);
}
