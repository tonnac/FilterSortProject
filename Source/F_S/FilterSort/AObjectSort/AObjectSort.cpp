#include "AObjectSort.h"

FText UAObjectIDSort::GetSortName()
{
	return FText::FromString(TEXT("ID"));
}

FText UAObjectLevelSort::GetSortName()
{
	return FText::FromString(TEXT("Level"));
}

FText UAObjectStatSort::GetSortName()
{
	return FText::FromString(TEXT("Stat"));
}

FText UAObjectUsingSort::GetSortName()
{
	return FText::FromString(TEXT("Using"));
}
