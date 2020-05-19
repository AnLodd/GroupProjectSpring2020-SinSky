// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"

AMyPlayerController::AMyPlayerController()
{
	Kills = 0;
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

	//put if statements here.
}

void AMyPlayerController::BossKillCount(float Amount)
{
	BossKills += Amount;
	UE_LOG(LogTemp, Warning, TEXT("The amount of boss-kills arer %f"), BossKills);
}

