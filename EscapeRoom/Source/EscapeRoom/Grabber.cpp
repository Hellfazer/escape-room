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
	FindPhysicsHandleComponent();
	SetupInputComponent();
}

// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PhysicsHandler->GrabbedComponent) {
		PhysicsHandler->SetTargetLocation(GetReachLineEnd());
	}
}

void UGrabber::Grab() {
	//UE_LOG(LogTemp, Warning, TEXT("Grab pressed"));

	//LINE TRACE and reach any actors with physics collision channel set
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	//if we hit something then atttach a physics handle
	if (ActorHit != nullptr) {
		PhysicsHandler->GrabComponent(
			ComponentToGrab,
			NAME_None, //no bones needed
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true //allow rotation
		);
	}

}

void UGrabber::Release() {
	PhysicsHandler->ReleaseComponent();
}

void UGrabber::FindPhysicsHandleComponent()
{
	PhysicsHandler = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandler == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("PhysicsEngine not found for: %s"), *(GetOwner()->GetName()));
	}
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("InputComponent not found for: %s"), *(GetOwner()->GetName()));
	}
}

const FHitResult UGrabber::GetFirstPhysicsBodyInReach()
{

	//DrawDebugLine(
	//	GetWorld(),
	//	PlayerViewPointLocation,
	//	LinetraceEnd,
	//	FColor(255,0,0),
	//	false,
	//	0.f,
	//	0.f,
	//	10.0f
	//	);

	///Setup Quesry Params
	FCollisionQueryParams TraceParameters(
		FName(TEXT("")),
		false, ///Simple trace instead of complex (Chunky objects vs detailed)
		GetOwner() ///Object to ignore
	);

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		GetReachLineStart(), ///The Players Location
		GetReachLineEnd(),			///The end of the line
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), ///Which collision channel is being checked
		TraceParameters
	);

	AActor* ActorHit = HitResult.GetActor(); 
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Tracer Collision: %s"), *(ActorHit->GetName()));
	}
	return HitResult;
}

const FVector UGrabber::GetReachLineEnd()
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

const FVector UGrabber::GetReachLineStart()
{
		FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	return PlayerViewPointLocation + PlayerViewPointRotation.Vector();
	return FVector();
}
