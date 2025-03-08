// Fill out your copyright notice in the Description page of Project Settings.


#include "DestroyActors.h"

void UDestroyActors::OnActivated()
{
	Super::OnActivated();

	bool bHasDestroyedAnyActor = false;

	for (TSoftObjectPtr<AActor>& Actor : Actors)
	{
		if (APawn* Pawn = Cast<APawn>(Actor.LoadSynchronous()))
		{
			Pawn->Destroy();

			bHasDestroyedAnyActor = true;
		}
	}

	if (bHasDestroyedAnyActor)
	{
		CompleteAction();
	}
	else
	{
		EndAction();
		NoActorDestroyed.Broadcast();
	}
}
