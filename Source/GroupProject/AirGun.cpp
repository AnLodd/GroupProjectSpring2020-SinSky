// Fill out your copyright notice in the Description page of Project Settings.


#include "AirGun.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MainCharacter.h"
#include "Enemy.h"
#include "Boss.h"
#include "Wall.h"

// Sets default values
AAirGun::AAirGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collider = CreateDefaultSubobject<UBoxComponent>(TEXT("Collider"));
	Collider->OnComponentBeginOverlap.AddDynamic(this, &AAirGun::OnOverlapBegin);
	//Collider->SetSphereRadius(50.f);

	RootComponent = Collider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AirGun Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	IdleParticlesComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticlesComponent"));
	IdleParticlesComponent->SetupAttachment(GetRootComponent());

	SpellDuration = 2;
	Speed = { 3500.f, 0.f, 0.f };
	Damage = 50;
}

// Called when the game starts or when spawned
void AAirGun::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void AAirGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Speed += { 1000.f * DeltaTime, 0.f, 0.f };


	//Location.Y += (Direction.Y * DeltaTime) * Speed;
	//Location.X += (Direction.X * DeltaTime) * Speed;

	//Improved:

	AddActorLocalOffset(Speed * DeltaTime);

	TimeSinceSpawned += DeltaTime;

	if (TimeSinceSpawned >= SpellDuration)
	{
		Destroy();
	}
}

void AAirGun::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor)
	{
		//AMainCharacter* Main = Cast<AMainCharacter>(OtherActor); //Sender til Main. Om det ikke er main sender den NULL
		//if (Main) //Om det er Main:
		//{
			//Main->FireDamage(Damage);
			//if (OverlapParticles)
			//{
			//	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator(0.f), true);
			//}
			//Destroy();
		//}

		AEnemy* Enemy = Cast<AEnemy>(OtherActor);
		if (Enemy)
		{
			Enemy->TakeAirDamage(Damage);
			if (OverlapParticles)
			{
				UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator(0.f), true);
			}
			Destroy();
		}

		ABoss* Boss = Cast<ABoss>(OtherActor);
		if (Boss)
		{
			Boss->TakeAirDamage(Damage);
			Destroy();
		}
		AWall* Wall = Cast<AWall>(OtherActor);
		if (Wall)
		{
			Destroy();
		}
	}
}