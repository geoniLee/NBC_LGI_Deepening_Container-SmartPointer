// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.generated.h"

class AInventoryManager;

UCLASS()
class NBC_CONTAINANDSPTR_API UItemBase : public UObject
{
	GENERATED_BODY()
public:
	UItemBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName RequiredTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 Count;


	UFUNCTION(BlueprintCallable, Category = "Item")
	virtual bool CanUse(AInventoryManager* inventoryManager) const;

	UFUNCTION(BlueprintCallable, Category = "Item")
	virtual void UseItem(AInventoryManager* inventoryManager);
};
