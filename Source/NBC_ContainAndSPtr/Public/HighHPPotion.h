// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "HighHPPotion.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CONTAINANDSPTR_API UHighHPPotion : public UItemBase
{
	GENERATED_BODY()
	
public:
	UHighHPPotion();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealAmount;

	virtual void UseItem(AInventoryManager* InventoryManager) override;
};
