// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardClass.h"
#include "CardButtonClass.generated.h"

class UTextBlock;

/**
 * 
 */
UCLASS()
class MOPOLIS_API UCardButtonClass : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetCardData(const FCardData& Card);
	
	UFUNCTION(BlueprintCallable)
	void OnCardButtonClick();

protected:
	// Name must match the Text widget in WBP_CardButton.
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CardIDText;
	
private:
	int32 CurCardID;
};
