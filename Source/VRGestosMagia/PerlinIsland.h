// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PerlinIsland.generated.h"

/**
 * 
 */
UCLASS()
class VRGESTOSMAGIA_API UPerlinIsland : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		UFUNCTION(BlueprintCallable, Category = DTL, meta = (HidePin = "worldContextObject_", DefaultToSelf = "worldContextObject_"))
		static bool perlinIsland(const UObject* worldContextObject_, float frequency, int32 octaves, int32 max_value, int32 min_value);
};
