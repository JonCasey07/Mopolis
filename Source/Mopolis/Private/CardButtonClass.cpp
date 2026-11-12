// Fill out your copyright notice in the Description page of Project Settings.


#include "CardButtonClass.h"
#include "Components/TextBlock.h"
#include "DeckBuilderClass.h"
#include "MopolisGameInstance.h"

void UCardButtonClass::SetCardData(const FCardData& Card)
{
	CurCardID = Card.ID;
	
	if (CardIDText)
	{
		CardIDText->SetText(FText::AsNumber(Card.ID));
	}
}

void UCardButtonClass::OnCardButtonClick()
{
	const UMopolisGameInstance* GameInstance = Cast<UMopolisGameInstance>(GetGameInstance());
	
	bool bIsLeader = GameInstance->GlobalCardList.Cards[CurCardID].Class.Equals("Leader");
	
	if (UDeckBuilderClass* DeckBuilder = GetTypedOuter<UDeckBuilderClass>())
	{
		if (bIsLeader)
		{
			DeckBuilder->SetLeaderIndex(CurCardID);
		}
	}
	
}


