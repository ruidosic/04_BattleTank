// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTankGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Tank.h"
#include "TankPlayerController.h"

ABattleTankGameModeBase::ABattleTankGameModeBase()
{
	static ConstructorHelpers::FClassFinder<ATank> TankBP(TEXT("/Game/Tank/BP_Tank"));
	if (TankBP.Class)
		DefaultPawnClass = TankBP.Class;
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant find PlayerPawn"));
	
	static ConstructorHelpers::FClassFinder<ATankPlayerController> TankPlayerControllerBP(TEXT("/Game/Tank/BP_TankPlayerController"));
	if (TankPlayerControllerBP.Class)
		PlayerControllerClass = TankPlayerControllerBP.Class;
	else
		UE_LOG(LogTemp, Warning, TEXT("Cant find PlayerController"));
}