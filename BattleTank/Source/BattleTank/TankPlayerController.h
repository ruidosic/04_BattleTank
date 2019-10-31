// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	ATankPlayerController(const FObjectInitializer& ObjectInitializer);
	virtual void BeginPlay() override;

private:
	void AddPlayerWidgetToViewport();
	class UUserWidget* PlayerUI;
	TSubclassOf<class UUserWidget> PlayerUIClass = nullptr;
	class ATank* GetControlledTank() const;

};
