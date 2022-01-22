#include "AObjectFilter.h"

bool FLevelFilter::Is_Satisfied(const UAObject* _pData)
{
	return _pData->Level == Level;
}

bool FIDFilter::Is_Satisfied(const UAObject* _pData)
{
	return _pData->ID == ID;
}

bool FStatFilter::Is_Satisfied(const UAObject* _pData)
{
	return _pData->Stat == Stat;
}
