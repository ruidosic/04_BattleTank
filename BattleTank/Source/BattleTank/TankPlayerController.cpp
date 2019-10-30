// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Tank.h"

ATankPlayerController::ATankPlayerController(const FObjectInitializer& ObjectInitializer) : APlayerController(ObjectInitializer)
{
	//  get Player UI Class
	static ConstructorHelpers::FClassFinder<UUserWidget> PlayerUIClassBP(TEXT("/Game/UI/WBP_PlayerUI"));
	if (PlayerUIClassBP.Class)
	{
		PlayerUIClass = PlayerUIClassBP.Class;
	}
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PlayerUI = CreateWidget<UUserWidget>(this, PlayerUIClass, NAME_None);
	PlayerUI->AddToViewport(0);
}

ATank * ATankPlayerController::GetControlledTank() const
{
	
	return Cast<ATank>(GetPawn());
}
