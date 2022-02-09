// Fill out your copyright notice in the Description page of Project Settings.


#include "AObjectUsingFilter.h"

#include "AObjectFilter.h"

void UAObjectUsingFilter::Initialize(const FOnUpdateFilter& _Delegate)
{
	Super::Initialize(_Delegate);
	if (UAObjectUsingFilterElement* NewFilterElement = NewObject<UAObjectUsingFilterElement>(this))
	{
		bool bCondition = true;
		NewFilterElement->Initialize(GetIndex(), &bCondition);
		UsingFilter = NewFilterElement;
	}
}
