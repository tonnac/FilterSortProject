#include "AObjectFilter.h"
#include "AObjectFilterElement.h"

void UStatFilter::Initialize()
{
	Super::Initialize();
	for (int32 i = 0; i < 5; ++i)
	{
		if (UAObjectStatFilterElement* NewFilterElement = NewObject<UAObjectStatFilterElement>(this))
		{
			int32 Stat = i + 1;
			NewFilterElement->Initialize(&Stat);
			FilterElements.Emplace(NewFilterElement);
		}
	}
}

void ULevelFilter::Initialize()
{
	Super::Initialize();
	for (int32 i = 0; i < 5; ++i)
	{
		if (UAObjectLevelFilterElement* NewFilterElement = NewObject<UAObjectLevelFilterElement>(this))
		{
			int32 Level = i + 1;
			NewFilterElement->Initialize(&Level);
			FilterElements.Emplace(NewFilterElement);
		}
	}
}

void UAObjectUsingFilter::Initialize()
{
	UAObjectUsingFilterElement* Filter = NewObject<UAObjectUsingFilterElement>(this);
	if (IsValid(Filter))
	{
		bool bCondition = true;
		Filter->Initialize(&bCondition);
		FilterElements.Emplace(Filter);
	}
}

void UAObjectOptionFilter::Initialize()
{
	UAObjectOptionFilterElement* Filter = NewObject<UAObjectOptionFilterElement>(this);
	if (IsValid(Filter))
	{
		bool bCondition = true;
		Filter->Initialize(&bCondition);
		FilterElements.Emplace(Filter);
	}
}
