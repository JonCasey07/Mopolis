// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardClass.generated.h"

// struct for each individual card
USTRUCT(BlueprintType)
struct MOPOLIS_API FCardData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Aspect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Class;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ID = 0;
};

// struct for a list of cards
USTRUCT(BlueprintType)
struct MOPOLIS_API FCardList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCardData> Cards;
};

USTRUCT(BlueprintType)
struct MOPOLIS_API FDeck
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> CardFreqArray;
};

USTRUCT(BlueprintType)
struct MOPOLIS_API FDeckList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDeck> Decks;
};

class MOPOLIS_API FCardClass
{
public:
	static bool LoadFromJson(const FString& JsonString, FCardList& OutCardList);
};
