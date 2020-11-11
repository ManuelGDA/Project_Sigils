// Fill out your copyright notice in the Description page of Project Settings.


#include "PerlinIsland.h"

#include "EngineUtils.h"
#include "Landscape.h"
#include "LandscapeInfo.h"
#include "LandscapeEditor/Public/LandscapeEditorUtils.h"

#include <DTL.hpp>

bool UPerlinIsland::perlinIsland(const UObject* worldContextObject_, float frequency, int32 octaves, int32 max_value, int32 min_value) {

	dtl::shape::PerlinIsland<uint16> generator(
		static_cast<double>(frequency),
		static_cast<size_t>(octaves),
		static_cast<uint16>(max_value),
		static_cast<uint16>(min_value));

	::UWorld* world{ worldContextObject_->GetWorld() };
	for (TActorIterator<ALandscape> actorItr(world); actorItr; ++actorItr) {
		::ALandscape* landscape{ *actorItr };
		if (landscape == nullptr) continue;
		::ULandscapeInfo::RecreateLandscapeInfo(world, false);

		::FIntRect rect{ landscape->GetBoundingRect() };
		const int32 w{ rect.Width() + 1 };
		const int32 h{ rect.Height() + 1 };

		::TArray<uint16> Data;
		Data.Init(0, w * h);
		generator.draw(Data, w, h);
		LandscapeEditorUtils::SetHeightmapData(landscape, Data);
		return true;
	}
	return false;
}