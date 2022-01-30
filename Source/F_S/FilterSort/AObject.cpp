// Fill out your copyright notice in the Description page of Project Settings.


#include "AObject.h"

void UAObject::Initialize()
{
	ID = FMath::RandRange(1, 5);
	Level = FMath::RandRange(1, 5);
	Stat = FMath::RandRange(1, 5);
	IsUsing = static_cast<bool>(FMath::RandRange(0, 1));
}

void UAObject::Initialize(int32 InID, int32 InLevel, int32 InStat, bool InIsUsing)
{
	ID = InID;
	Level = InLevel;
	Stat = InStat;
	IsUsing = InIsUsing;
}
