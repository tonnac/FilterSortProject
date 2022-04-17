#pragma once

#include "CoreMinimal.h"
#include "AObject.h"
#include "FilterSortModule.h"
#include "Sort/SortBase.h"
#include "AObjectSort.generated.h"

UCLASS()
class F_S_API UAObjectIDSort : public USortBase
{
	GENERATED_BODY()

	IMPLEMENT_COMMON_PROPERTY(UAObject, 0)
	IMPLEMENT_SORT(UAObject, ID)

	virtual FText GetSortName() override;
};

UCLASS()
class F_S_API UAObjectLevelSort : public USortBase
{
	GENERATED_BODY()

	IMPLEMENT_COMMON_PROPERTY(UAObject, 1)
	IMPLEMENT_SORT(UAObject, Level)

	virtual FText GetSortName() override;
};

UCLASS()
class F_S_API UAObjectStatSort : public USortBase
{
	GENERATED_BODY()

	IMPLEMENT_COMMON_PROPERTY(UAObject, 2)
	IMPLEMENT_SORT(UAObject, Stat)

	virtual FText GetSortName() override;
};

UCLASS()
class F_S_API UAObjectUsingSort : public USortBase
{
	GENERATED_BODY()

	IMPLEMENT_COMMON_PROPERTY(UAObject, 3)
	IMPLEMENT_SORT(UAObject, IsUsing)

	virtual FText GetSortName() override;
};
