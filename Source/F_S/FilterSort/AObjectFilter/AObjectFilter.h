#pragma once
#include "CoreMinimal.h"
#include "AObject.h"
#include "FilterElement.h"
#include "AObjectFilter.generated.h"

UCLASS()
class F_S_API UAObjectLevelFilterElement : public UFilterElement
{
	GENERATED_BODY()
public:
	virtual void Initialize(void* Src) override;
	virtual bool operator()(const UAObject* _pData) override;
	
private:
	int32 Level = 0;
};

UCLASS()
class F_S_API UAObjectIDFilterElement : public UFilterElement
{
	GENERATED_BODY()
public:
	virtual void Initialize(void* Src) override;
	virtual bool operator()(const UAObject* _pData) override;

private:
	int32 ID = 0;
};

UCLASS()
class F_S_API UAObjectStatFilterElement : public UFilterElement
{
	GENERATED_BODY()
public:
	virtual void Initialize(void* Src) override;
	virtual bool operator()(const UAObject* _pData) override;

private:
	int32 Stat = 0;
};

UCLASS()
class F_S_API UAObjectUsingFilterElement : public UFilterElement
{
	GENERATED_BODY()
public:
	virtual void Initialize(void* Src) override;
	virtual bool operator()(const UAObject* _pData) override;

private:
	bool bIsUsing = false;
};