// Fill out your copyright notice in the Description page of Project Settings.


#include "CardClass.h"
#include "JsonObjectConverter.h"

bool FCardJson::LoadFromJson(
	const FString& JsonString,
	FCardList& OutCardList)
{
	if (!FJsonObjectConverter::JsonObjectStringToUStruct(
		JsonString,
		&OutCardList,
		0,
		0))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to parse card list JSON."));
		return false;
	}

	return true;
}
