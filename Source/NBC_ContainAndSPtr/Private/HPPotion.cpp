// Fill out your copyright notice in the Description page of Project Settings.


#include "HPPotion.h"
#include "HighHPPotion.h"
#include "InventoryManager.h"

UHPPotion::UHPPotion() : HealAmount(30)
{
	ItemID = FName(TEXT("101"));
	ItemName = TEXT("체력 포션");
	Description = TEXT("체력을 30 회복합니다.");
	Count = 5;
}

void UHPPotion::UseItem(AInventoryManager* InventoryManager)
{
	FString msg;
	// 사용할 수 없을 때
	if (!CanUse(InventoryManager)) {
		msg = FString::Printf(TEXT("%s 사용 실패"), * ItemName);
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, msg);
		return;
	}

	// 사용 성공
	Count--;
	msg = FString::Printf(TEXT("%s 사용 성공 / 회복량 %.1f / 남은 개수: %d"), *ItemName, HealAmount, Count);
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, msg);

	// 포션의 개수가 3개가 될 때 상급 포션 생성
	if (Count == 3) {
		UHighHPPotion* HighPotion = NewObject<UHighHPPotion>(this);

		if (HighPotion == nullptr) {
			GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Green, TEXT("상급 체력 포션 생성 실패"));
			return;
		}

		InventoryManager->AddItem(HighPotion);
		msg = FString::Printf(TEXT("상급 체력 포션 생성 / 개수=%d"), HighPotion->Count);
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, msg);
	}

	// high Potion 사용을 위한 title 추가
	if (Count == 0) {
		InventoryManager->AddTitle("PotionAddict");
		GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Yellow, TEXT("Title 'PotionAddict' 획득"));
	}
}
