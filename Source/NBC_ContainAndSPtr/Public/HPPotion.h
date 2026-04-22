// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "HPPotion.generated.h"

/**
 * 
 */
UCLASS()
class NBC_CONTAINANDSPTR_API UHPPotion : public UItemBase
{
	GENERATED_BODY()
	
public:
	UHPPotion();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealAmount;

	virtual void UseItem(AInventoryManager* InventoryManager) override;
};
