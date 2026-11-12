// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckBuilderClass.h"
#include "CardButtonClass.h"
#include "IContentBrowserSingleton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void UDeckBuilderClass::PopulateLeaderGrid(const int32 NumColumns)
{
	if (SaveButton)
	{
		SaveButton->SetIsEnabled(false);
	}
	
	if (!CardGrid || !CardButton || NumColumns <= 0)
	{
		return;
	}

	CardGrid->ClearChildren();

	const UMopolisGameInstance* GameInstance =
		Cast<UMopolisGameInstance>(GetGameInstance());

	if (!GameInstance)
	{
		return;
	}

	const TArray<FCardData>& Cards = GameInstance->GlobalCardList.Cards;

	int32 CurRow = 0;
	int32 CurCol = 0;

	for (int32 i = 0; i < Cards.Num(); ++i)
	{
		if (!Cards[i].Class.Equals(TEXT("Leader")))
		{
			continue;
		}

		UCardButtonClass* CardWidget = CreateWidget<UCardButtonClass>(this, CardButton);
		if (!CardWidget)
		{
			continue;
		}

		CardWidget->SetCardData(Cards[i]);
		CardGrid->AddChildToUniformGrid(CardWidget, CurRow, CurCol);
		++i;
		++CurCol;
		if (CurCol >= NumColumns)
		{
			CurCol = 0;
			++CurRow;
		}
	}
}

void UDeckBuilderClass::SetLeaderIndex(const int32 InLeaderIndex)
{
	LeaderIndex = InLeaderIndex;
	UpdatePostLeaderWidget();
}

void UDeckBuilderClass::UpdatePostLeaderWidget()
{
	if (SaveButton)
	{
		SaveButton->SetIsEnabled(true);
	}
	
	const UMopolisGameInstance* GameInstance =
		Cast<UMopolisGameInstance>(GetGameInstance());

	if (!GameInstance)
	{
		return;
	}

	Leader = GameInstance->GlobalCardList.Cards[LeaderIndex];
	LeaderBack = GameInstance->GlobalCardList.Cards[LeaderIndex + 1];
	
	CardCount = 1;
	if (DeckNumCount)
	{
		DeckNumCount->SetText(FText::FromString(FString::Printf(TEXT("%d/60"), CardCount)));
	}
	
	if (BuilderAdvice)
	{
		BuilderAdvice->SetText(FText::FromString(TEXT("Pick your remaining cards")));
	}
	
	if (LeaderDetails)
	{
		if (Leader.Aspect.Equals(LeaderBack.Aspect))
		{
			LeaderDetails->SetText(FText::FromString(FString::Printf(TEXT("%s/%s \n%s"), *Leader.Name, *LeaderBack.Name, *Leader.Aspect)));
		}
		else
		{
			LeaderDetails->SetText(FText::FromString(FString::Printf(TEXT("%s/%s \n%s/%s"), *Leader.Name, *LeaderBack.Name, *Leader.Aspect, *LeaderBack.Aspect)));
		}
		
	}
	
	PopulateCardGrid(6);

}

void UDeckBuilderClass::PopulateCardGrid(const int32 NumColumns)
{
	if (!CardGrid || !CardButton || NumColumns <= 0)
	{
		return;
	}

	CardGrid->ClearChildren();

	const UMopolisGameInstance* GameInstance =
		Cast<UMopolisGameInstance>(GetGameInstance());

	if (!GameInstance)
	{
		return;
	}

	const TArray<FCardData>& Cards = GameInstance->GlobalCardList.Cards;
	
	int32 CurRow = 0;
	int32 CurCol = 0;

	for (int32 i = 0; i < Cards.Num(); ++i)
	{
		if (Cards[i].Class.Equals(TEXT("Leader")))
		{
			++i;
			continue;
		}
		if (!(Cards[i].Aspect.Equals(Leader.Aspect) || Cards[i].Aspect.Equals(LeaderBack.Aspect) 
			|| Cards[i].Aspect.Equals("Colorless(White)")))
		{
			continue;
		}
		
		

		UCardButtonClass* CardWidget = CreateWidget<UCardButtonClass>(this, CardButton);
		if (!CardWidget)
		{
			continue;
		}

		UE_LOG(LogTemp, Log, TEXT("%s logged"), *Cards[i].Name);
		CardWidget->SetCardData(Cards[i]);
		CardGrid->AddChildToUniformGrid(CardWidget, CurRow, CurCol);
		++CurCol;
		if (CurCol >= NumColumns)
		{
			CurCol = 0;
			++CurRow;
		}
	}
}
