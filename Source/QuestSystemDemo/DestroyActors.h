// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestAction.h"
#include "DestroyActors.generated.h"


UCLASS(meta = (MakeTrigger, MakeEvent))
class QUESTSYSTEMDEMO_API UDestroyActors : public UQuestAction
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, Category = "DestroyActor", meta = (NotebookBindable, ExposeAsInput))
	TArray<TSoftObjectPtr<AActor>> Actors;

	UPROPERTY(meta = (ActionExec))
	FQuestActionDelegate NoActorDestroyed;

protected:

	virtual void OnActivated() override;

};
