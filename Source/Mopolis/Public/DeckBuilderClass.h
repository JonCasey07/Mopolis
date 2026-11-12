// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/UniformGridPanel.h"
#include "MopolisGameInstance.h"
#include "DeckBuilderClass.generated.h"

/**
 * 
 */

class UUniformGridPanel;
class UButton;
class UEditableText;
class UTextBlock;
class UCardButtonClass;

UCLASS()
class MOPOLIS_API UDeckBuilderClass : public UUserWidget
{
	GENERATED_BODY()
public:
	// Call this at runtime to populate the leader grid
	UFUNCTION(BlueprintCallable, Category = "UI|Grid")
	void PopulateLeaderGrid(const int32 NumColumns);
	
	// Call this at runtime to populate the leader grid
	UFUNCTION(BlueprintCallable, Category = "UI|Grid")
	void UpdatePostLeaderWidget();

	// Sets the leader index for the deck
	UFUNCTION(BlueprintCallable)
	void SetLeaderIndex(const int32 InLeaderIndex);
	
	// Call this after leader is picked to populate the card grid
	UFUNCTION(BlueprintCallable, Category = "UI|Grid")
	void PopulateCardGrid(const int32 NumColumns);

protected:
	// Name must match the GridPanel in your Widget Blueprint designer
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UUniformGridPanel> CardGrid;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> SaveButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableText> DeckName;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> DeckNumCount;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> BuilderAdvice;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> LeaderDetails;

	// Assign your child item Widget Blueprint (e.g., WBP_GridSlot) in the Details panel
	UPROPERTY(EditDefaultsOnly, Category = "UI|Grid")
	TSubclassOf<UCardButtonClass> CardButton;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI|Grid")
	int32 LeaderIndex;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI|Grid")
	FCardData Leader;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI|Grid")
	FCardData LeaderBack;
	
	UPROPERTY(EditDefaultsOnly, Category = "UI|Grid")
	int32 CardCount;
};
