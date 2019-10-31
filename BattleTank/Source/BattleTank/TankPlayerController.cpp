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


void ATankPlayerController::AddPlayerWidgetToViewport()
{
	PlayerUI = CreateWidget<UUserWidget>(this, PlayerUIClass, NAME_None);
	PlayerUI->AddToViewport(0);
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); 
	AddPlayerWidgetToViewport();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PC possessing the tank: %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PC not possessing the tank"));
	}
}


ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
