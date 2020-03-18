// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"


UCLASS()
class GROUPPROJECT_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* FollowCamera;

	float WalkSpeed;
	float RunSpeed;
	bool bCasting;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//UFUNCTION()
		//void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
			//UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
			//bool bFromSweep, const FHitResult& SweepResult);

	void MoveSideways(float Value);
	void MoveForward(float Value);
	FVector CurrentVelocity;


	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Shoot") //Bullet Spawning offset
	float SpellForwardOffset = 200.f;
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Shoot") //Bullet Spawning offset
	float SpellHeightOffset = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* FireballSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	class USoundCue* WaterWaveSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float FireCooldown = 1;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float FireTimeSinceSpell;
	float FireSpellCD;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float WaterCooldown;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float WaterTimeSinceSpell;
	float WaterSpellCD;

	float EarthCooldown;
	float EarthTimeSinceSpell;
	float EarthSpellCD;

	float AirCooldown;
	float AirTimeSinceSpell;
	float AirSpellCD;

	float DashCooldown;
	float DashDuration;
	float DashTime;
	float TimeSinceDash;
	bool bDash;


	UPROPERTY(EditAnywhere, Category = "FireBall | Stage 1")
	TSubclassOf<class AFireball> Fireball_BP;
	UPROPERTY(EditAnywhere, Category = "WaterWave | Stage 1")
	TSubclassOf<class AWaterWave> WaterWave_BP;

	//Mouse
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mouse Setup")
	UDecalComponent* CursorToWorld;
	FVector NewDirectionToCursor;
	FVector TempLocation;



	//Spells:
	float SpellChoosen;

	void CastSpell();
	void StartSpell();
	void StopSpell();
	void Dash();

	void SpellOne();
	void SpellTwo();

	//Taking Damage
	void FireDamage(float Damage);
	void WaterDamage(float Damage);
	void EarthDamage(float Damage);
	void AirDamage(float Damage);
	void Dead();

	//--------------------------Stats----------------------------

	//Health
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float Health;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Stats")
	float MaxHealth;

	//Defence
	float FireResistance;
	float WaterResistance;
	float EarthResistance;
	float AirResistance;

	//Movement
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxSpeed;
	//-----------------------------------------------------------



	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
