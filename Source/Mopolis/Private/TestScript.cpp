// Fill out your copyright notice in the Description page of Project Settings.


#include "TestScript.h"
#include "CardClass.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

// Sets default values
ATestScript::ATestScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestScript::BeginPlay()
{
	Super::BeginPlay();

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
		for (const FCardData& Card : LoadedCardList.Cards)
		{
			UE_LOG(LogTemp, Verbose, TEXT("%d. Name: %s | Class: %s | Description : %s"),
			Card.ID,
			*Card.Name,
			*Card.Class,
			*Card.Description);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card JSON load test failed for %s. File read: %s, parsed cards: %d."),
			*CardsJsonPath,
			bReadFile ? TEXT("true") : TEXT("false"),
			LoadedCardList.Cards.Num());
	}

	ensureMsgf(bValidResult, TEXT("Could not load the expected card data from Content/Data/cards.json."));
}

// Called every frame
void ATestScript::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
