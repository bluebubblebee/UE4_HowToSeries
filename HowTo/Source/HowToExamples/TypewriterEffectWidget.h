// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TypewriterEffectWidget.generated.h"

/**
 * 
 */
UCLASS()
class HOWTOEXAMPLES_API UTypewriterEffectWidget : public UUserWidget
{
	GENERATED_BODY()
private:
	virtual bool Initialize() override;

protected:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* MessageText;


	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:

	UFUNCTION(BlueprintCallable, Category = "TypewriterEffect")
		void ShowMessage(const FString& Text);

protected:

	UPROPERTY(EditAnywhere, Category = "TypewriterEffect")
		float DelayBetweenLetters = 0.5f;

private:

	bool bUpdateMessage;

	FString CurrentMessage;

	int32 LetterIndex;

	FString MessageToShow;

	float CurrentTimeBetweenLetters = 0.0f;
};


