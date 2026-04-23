// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryManager.generated.h"

class UItemBase;

UCLASS()
class NBC_CONTAINANDSPTR_API AInventoryManager : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AInventoryManager();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<UItemBase*> Inventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TMap<FName, UItemBase*> ItemMap;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TSet<FName> OwnedTitles;

	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UItemBase* NewItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UItemBase* NewItem);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void BuildItemMap();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	UItemBase* FindItemByID(FName ItemID) const;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddTitle(FName  NewTitle);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool HasTitle(FName Title);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool CanUseItem(FName ItemID);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void UseItemByID(FName ItemID);
};
