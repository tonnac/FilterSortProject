#include "AObjectFilter.h"

void UAObjectLevelFilterElement::Initialize(int32 InIndex, void* Src)
{
	Super::Initialize(InIndex, Src);
	Level = *static_cast<int32*>(Src);
	oo.KK = FText::FromString(FString::Format(TEXT("Lv.{0}"), { Level }));
}

bool UAObjectLevelFilterElement::operator()(const UAObject* _pData)
{
	return _pData->Level == Level;
}

void UAObjectIDFilterElement::Initialize(int32 InIndex, void* Src)
{
	Super::Initialize(InIndex, Src);
	ID = *static_cast<int32*>(Src);
}

bool UAObjectIDFilterElement::operator()(const UAObject* _pData)
{
	return _pData->ID == ID;
}

void UAObjectStatFilterElement::Initialize(int32 InIndex, void* Src)
{
	Super::Initialize(InIndex, Src);
	Stat = *static_cast<int32*>(Src);
	oo.KK = FText::FromString(FString::Format(TEXT("Stat.{0}"), { Stat }));
}

bool UAObjectStatFilterElement::operator()(const UAObject* _pData)
{
	return _pData->Stat == Stat;
}

void UAObjectUsingFilterElement::Initialize(int32 InIndex, void* Src)
{
	Super::Initialize(InIndex, Src);
	bIsUsing = *static_cast<bool*>(Src);
}

bool UAObjectUsingFilterElement::operator()(const UAObject* _pData)
{
	return _pData->IsUsing == bIsUsing;
}