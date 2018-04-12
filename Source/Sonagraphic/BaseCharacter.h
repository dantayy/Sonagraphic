// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class SONAGRAPHIC_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	//make a health property
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
		float health = 100;

	//make a death property
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BaseCharacter")
		bool isDead = false;

	//calculate death function
	virtual void CalculateDead();

	//calculate health function
	UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	//code related to changing properties in the unreal editor
	virtual void PostEditChangeProperty(FPropertyChangedEvent& propertyChangedEvent)
		override;
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
