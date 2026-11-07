// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardClass.generated.h"

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

USTRUCT(BlueprintType)
struct MOPOLIS_API FCardList
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FCardData> Cards;
};

class MOPOLIS_API FCardJson
{
public:
	static bool LoadFromJson(const FString& JsonString, FCardList& OutCardList);
};
