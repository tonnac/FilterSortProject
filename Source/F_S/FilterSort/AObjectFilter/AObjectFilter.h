#pragma once
#include "AObject.h"
#include "FilterInterface.h"

class FLevelFilter : public TFilterInterface<UAObject>
{
public:
	explicit FLevelFilter(int32 Level)
		: Level(Level)
	{
	}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 Level = 0;
};


class FIDFilter : public TFilterInterface<UAObject>
{
public:
	explicit FIDFilter(int32 ID)
		: ID(ID)
	{
	}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 ID = 0;
};

class FStatFilter : public TFilterInterface<UAObject>
{
public:
	explicit FStatFilter(int32 Stat)
		: Stat(Stat)
	{
	}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	int32 Stat = 0;
};

class FUsingFilter : public TFilterInterface<UAObject>
{
public:
	explicit FUsingFilter(bool IsUsing)
		: IsUsing(IsUsing)
	{
	}

	virtual bool Is_Satisfied(const UAObject* _pData) override;
	bool IsUsing = false;
};