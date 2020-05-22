// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	Kills = 0;

	BossKills = 0;

	FoesAlive = 0;

	FoesDefeated = 0;

	bLevelCleared = false;

	bEasy = false;
	bMedium = false;
	bHard = false;
}
void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//MyController->bEnableClickEvents = true;
	//MyController->bShowMouseCursor = true;
	//MyController->bEnableMouseOverEvents = true;

	if (HUDOverlayAsset)
	{
		HUDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}
	HUDOverlay->AddToViewport();
	HUDOverlay->SetVisibility(ESlateVisibility::Visible);

	if (HUDOverlayTalentTree)
	{
		HUDTalentTree = CreateWidget<UUserWidget>(this, HUDOverlayTalentTree);
	}
	HUDTalentTree->AddToViewport();
	HUDTalentTree->SetVisibility(ESlateVisibility::Hidden);
}

void AMyPlayerController::OpenSkillMenu()
{
		UE_LOG(LogTemp, Warning, TEXT("SKILL MENU"));

		if (bIsVisible)
		{
			if (HUDTalentTree)
			{
				HUDTalentTree->SetVisibility(ESlateVisibility::Visible);
			}
		}
		if (!bIsVisible)
		{
			if (HUDTalentTree)
			{
				HUDTalentTree->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	bIsVisible = !bIsVisible;
}

void AMyPlayerController::KillCount(float Amount)
{
	Kills += Amount;
	UE_LOG(LogTemp, Warning, TEXT("The amount of kills are %f"), Kills);

	FoesDefeatedCount(Amount);

	//put if statements here.
}

void AMyPlayerController::BossKillCount(float Amount)
{
	BossKills += Amount;
	UE_LOG(LogTemp, Warning, TEXT("The amount of boss-kills arer %f"), BossKills);
}

void AMyPlayerController::FoesAliveCount(float Amount)
{
	FoesAlive += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Enemies alive: %f"), FoesAlive - FoesDefeated);
}

void AMyPlayerController::FoesDefeatedCount(float Amount)
{
	FoesDefeated += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Enemies Defeated: %f"), FoesDefeated);
	UE_LOG(LogTemp, Warning, TEXT("Enemies alive: %f"), FoesAlive - FoesDefeated);
}

bool AMyPlayerController::bIsLevelCleared()
{
	if (FoesAlive == FoesDefeated)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Enemies Defeated"));
		bLevelCleared = true;
	}
	return bLevelCleared;
}

bool AMyPlayerController::bGetGameDifficulty()
{
	switch (GameDifficulty)
	{
	case EGameDifficultyStatus::GDS_Easy:
		bEasy = true;
		break;
	case EGameDifficultyStatus::GDS_Medium:
		bMedium = true;
		break;
	case EGameDifficultyStatus::GDS_Hard:
		bHard = true;
		break;
	case EGameDifficultyStatus::GDS_MAX:
		break;
	}
	return bEasy, bMedium, bHard;
}

