// Copyright 2024, Paulo Reyes. All rights reserved.


#include "VrWalkCast_Component.h"

#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"

UVrWalkCast_Component::UVrWalkCast_Component()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UVrWalkCast_Component::BeginPlay()
{
	Super::BeginPlay();
}

void UVrWalkCast_Component::SpawnCharacter(UMotionControllerComponent* _LeftController, UMotionControllerComponent* _RightController)
{
	if(!CharacterToSpawn || !GetOwner())
	{
		return;
	}

	//Set Controllers
	LeftController = _LeftController;
	RightController = _RightController;
	
	//Spawn Character
	FTransform OwnerTransform = GetOwner()->GetTransform();

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParameters.Instigator = GetOwner()->GetInstigator();
		
	SpawnedCharacter = GetWorld()->SpawnActor<ACharacter>(CharacterToSpawn, OwnerTransform, SpawnParameters);

	AIController = UAIBlueprintHelperLibrary::GetAIController(SpawnedCharacter);
		
	/*TArray<UStaticMeshComponent*> meshes;
	chara->GetComponents<UStaticMeshComponent>(meshes);

	for(UStaticMeshComponent* mesh : meshes)
	{
		mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
		mesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
		mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	}

	TArray<UCapsuleComponent*> collisions;
	chara->GetComponents<UCapsuleComponent>(collisions);

	for(UCapsuleComponent* collision : collisions)
	{
		collision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
		collision->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
		collision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	}*/
	
}

void UVrWalkCast_Component::CharacterMoveTo(const FVector& NewLocation)
{
	if(AIController)
	{
		AIController->MoveToLocation(NewLocation);
	}
}

UMotionControllerComponent* UVrWalkCast_Component::getRightHand()
{
	return RightController;
}

UMotionControllerComponent* UVrWalkCast_Component::getLeftHand()
{
	return LeftController;
}

