// Fill out your copyright notice in the Description page of Project Settings.


#include "AObjectUsingFilter.h"

#include "AObjectFilter.h"

void UAObjectUsingFilter::Initialize()
{
	UsingFilter = MakePimpl<FUsingFilter>(true);
	CurrentFilter = UsingFilter.Get();
}
