// Fill out your copyright notice in the Description page of Project Settings.


#include "MopolisGameInstance.h"

void UMopolisGameInstance::Init()
{
	Super::Init();
	
	FCardList GlobalCardList;
	InitializeCardList(GlobalCardList);
	
	
	
}

void InitializeCardList(FCardList& OutCardList)
{
	const FString CardsJsonPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Data/cards.json"));
	FString CardsJson;
	const bool bReadFile = FFileHelper::LoadFileToString(CardsJson, *CardsJsonPath);

	FCardList LoadedCardList;
	const bool bLoaded = bReadFile && FCardClass::LoadFromJson(CardsJson, LoadedCardList);
	const bool bValidResult =
		bLoaded &&
		LoadedCardList.Cards.Num() > 0 &&
		LoadedCardList.Cards[0].Name == TEXT("Vegeta") &&
		LoadedCardList.Cards[0].ID == 0;

	if (bValidResult)
	{
		UE_LOG(LogTemp, Log, TEXT("Card JSON load test passed. Loaded %d cards from %s."),
			LoadedCardList.Cards.Num(),
			*CardsJsonPath);
	}

	ensureMsgf(bValidResult, TEXT("Could not load the expected card data from Content/Data/cards.json."));
	
}

