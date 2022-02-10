// Fill out your copyright notice in the Description page of Project Settings.


#include "AObjectUsingFilter.h"

#include "AObjectFilter.h"

void UAObjectUsingFilter::Initialize(const FOnUpdateFilter& _Delegate)
{
	Super::Initialize(_Delegate);
	Filter = NewObject<UAObjectUsingFilterElement>(this);
	if (IsValid(Filter))
	{
		bool bCondition = true;
		Filter->Initialize(GetIndex(), &bCondition);
	}
}
