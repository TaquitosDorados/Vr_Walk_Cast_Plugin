// Copyright 2024, Paulo Reyes. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Components/ActorComponent.h"
#include "MotionControllerComponent.h"
#include "VrWalkCast_Component.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VRWALKCAST_API UVrWalkCast_Component : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVrWalkCast_Component();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACharacter> CharacterToSpawn;
	
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void SpawnCharacter(UMotionControllerComponent* _LeftController, UMotionControllerComponent* _RightController);
	UFUNCTION(BlueprintCallable)
	void CharacterMoveTo(const FVector& NewLocation);
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMotionControllerComponent* getRightHand();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UMotionControllerComponent* getLeftHand();

private:
	ACharacter* SpawnedCharacter;
	AAIController* AIController;
	UMotionControllerComponent* LeftController;
	UMotionControllerComponent* RightController;
};
