// Fill out your copyright notice in the Description page of Project Settings.


#include "AObject.h"

void UAObject::Initialize()
{
	ID = FMath::RandRange(1, 5);
	Level = FMath::RandRange(1, 5);
	Stat = FMath::RandRange(1, 5);
}
