// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "GameSaver.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float MaxHealth;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float Health;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float SkillPoints;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float FireLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float WaterLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float EarthLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float AirLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float RegenLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float ManaRegenLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float Kills;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float FireMana;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float WaterMana;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float EarthMana;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float AirMana;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FVector Location;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FRotator Rotation;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float BossKills;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float LevelsCleared;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float Xpoints;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float FoesDefeated;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float FoesAlive;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float PlayerLevel;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	float HealthRegenLvl;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	FName NextLevel;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	bool bEasy;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	bool bMedium;
	UPROPERTY(VisibleAnywhere, Category = "SaveData")
	bool bHard;
};
UCLASS()
class GROUPPROJECT_API UGameSaver : public USaveGame
{
	GENERATED_BODY()
public:
		UGameSaver();

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;
	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FCharacterStats CharacterStats;
	
};
