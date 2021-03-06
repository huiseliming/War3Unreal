// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FogOfWarDissolveStrategy.h"
#include "Components/SceneComponent.h"
#include "FogOfWarAgentComponent.generated.h"

class IFogOfWarDissolveStrategy;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RTSUNREAL_API UFogOfWarAgentComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFogOfWarAgentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void Activate(bool bReset) override;
	virtual void Deactivate() override;
	
public:
	float GetSightRadius() const { return VisionRadius; }
	bool IsIgnoresHeightLevels() const { return bIgnoreHeight; }

private:

	TArray<int32> VisibleTiles;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|FogOfWarAgentComponent")
	bool bAgentEnabled;
	
	// VisionRadius Unreal Unit(cm)
	UPROPERTY(EditDefaultsOnly, Category="RTS|FogOfWarAgentComponent")
	float VisionRadius = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "RTS|FogOfWarAgentComponent")
	int32 HeightLevel;
	
	UPROPERTY(EditDefaultsOnly, Category="RTS|FogOfWarAgentComponent")
	bool bIgnoreHeight = false;


	UPROPERTY(EditDefaultsOnly, Category="RTS|FogOfWarAgentComponent")
	EFogOfWarDissolveStrategy FogOfWarDissolveStrategy;

};
