// Fill out your copyright notice in the Description page of Project Settings.

#include "Grabber.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();


	UE_LOG(LogTemp, Warning, TEXT("Grabber here!"));

	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandler) {

	}
	else {
		UE_LOG(LogTemp, Error, TEXT("PhysicsEngine not found for: %s"), *(GetOwner()->GetName()));
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("InputComponent not found for: %s"), *(GetOwner()->GetName()));
	}
	
}

void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));
}

void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("Grab released"));
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);
	///UE_LOG(LogTemp, Warning, TEXT("Grabber at Position: %s and Roatation: %s"), *PlayerViewPointLocation.ToString(), *PlayerViewPointRotation.ToString());

	///Draw red trace to visualize
	FVector LinetraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerViewPointLocation,
		LinetraceEnd,
		FColor(255,0,0),
		false,
		0.f,
		0.f,
		10.0f
		);

	///Setup Quesry Params
	FCollisionQueryParams TraceParameters(
		FName(TEXT("")),
		false, ///Simple trace instead of complex (Chunky objects vs detailed)
		GetOwner() ///Object to ignore
	);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation, ///The Players Location
		LinetraceEnd,			///The end of the line
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), ///Which collision channel is being checked
		TraceParameters
	);

	AActor* ActorHit = Hit.GetActor(); 
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Tracer Collision: %s"), *(ActorHit->GetName()));
	}
	
}

