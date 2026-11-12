// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CardClass.h"
#include "MopolisGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MOPOLIS_API UMopolisGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	public:
	
	// Standard lifecycle override
	virtual void Init() override;
	
	void InitializeCardList (FCardList& OutCardList) const;
	
	// Persistent global data 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Card Data")
	FCardList GlobalCardList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data")
	FDeckList GlobalDeckList;
	
};
