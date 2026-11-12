// Fill out your copyright notice in the Description page of Project Settings.


#include "MopolisGameInstance.h"

void UMopolisGameInstance::Init()
{
	Super::Init();
	
	// initializes GlobalCardList declared in header file
	InitializeCardList(GlobalCardList);
	
}

void UMopolisGameInstance::InitializeCardList (FCardList& OutCardList) const
{
	const FString CardsJsonPath = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Data/cards.json"));
	FString CardsJson;
	const bool bReadFile = FFileHelper::LoadFileToString(CardsJson, *CardsJsonPath);

	const bool bLoaded = bReadFile && FCardClass::LoadFromJson(CardsJson, OutCardList);
	const bool bValidResult =
		bLoaded &&
		OutCardList.Cards.Num() > 0 &&
		OutCardList.Cards[0].Name == TEXT("Vegeta") &&
		OutCardList.Cards[0].ID == 0;

	if (bValidResult)
	{
		UE_LOG(LogTemp, Log, TEXT("Card JSON load test passed. Loaded %d cards from %s."),
			OutCardList.Cards.Num(),
			*CardsJsonPath);
	}

	ensureMsgf(bValidResult, TEXT("Could not load the expected card data from Content/Data/cards.json."));
	
}

