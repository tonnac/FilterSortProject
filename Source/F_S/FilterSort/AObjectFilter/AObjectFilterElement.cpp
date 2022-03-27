#include "AObjectFilterElement.h"

void UAObjectLevelFilterElement::Initialize(void* Src)
{
	Level = *static_cast<int32*>(Src);
	oo.KK = FText::FromString(FString::Format(TEXT("Lv.{0}"), { Level }));
}

bool UAObjectLevelFilterElement::IsSatisfied(const UAObject* _pData)
{
	return _pData->Level == Level;
}

void UAObjectIDFilterElement::Initialize(void* Src)
{
	ID = *static_cast<int32*>(Src);
}

bool UAObjectIDFilterElement::IsSatisfied(const UAObject* _pData)
{
	return _pData->ID == ID;
}

void UAObjectStatFilterElement::Initialize(void* Src)
{
	Stat = *static_cast<int32*>(Src);
	oo.KK = FText::FromString(FString::Format(TEXT("Stat.{0}"), { Stat }));
}

bool UAObjectStatFilterElement::IsSatisfied(const UAObject* _pData)
{
	return _pData->Stat == Stat;
}

void UAObjectUsingFilterElement::Initialize(void* Src)
{
	bIsUsing = *static_cast<bool*>(Src);
}

bool UAObjectUsingFilterElement::IsSatisfied(const UAObject* _pData)
{
	return _pData->IsUsing == bIsUsing;
}

void UAObjectOptionFilterElement::Initialize(void* Src)
{
	bOption = *static_cast<bool*>(Src);
}

bool UAObjectOptionFilterElement::IsSatisfied(const UAObject* _pData)
{
	return _pData->Option == bOption;
}