// Fill out your copyright notice in the Description page of Project Settings.


#include "TypewriterEffectWidget.h"
#include "Components/TextBlock.h"

bool UTypewriterEffectWidget::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	bUpdateMessage = false;

	return true;

}

void UTypewriterEffectWidget::ShowMessage(const FString& Text)
{
	MessageToShow = Text;

	LetterIndex = 0;

	CurrentMessage = "";

	CurrentTimeBetweenLetters = 0.0f;

	MessageText->SetText(FText::FromString(CurrentMessage));

	bUpdateMessage = true;
}


void UTypewriterEffectWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::Tick(MyGeometry, InDeltaTime);

	if (!bUpdateMessage) return;

	CurrentTimeBetweenLetters += InDeltaTime;

	if (CurrentTimeBetweenLetters >= DelayBetweenLetters)
	{
		CurrentMessage += MessageToShow[LetterIndex];

		MessageText->SetText(FText::FromString(CurrentMessage));

		LetterIndex += 1;

		if (LetterIndex >= MessageToShow.Len())
		{
			CurrentTimeBetweenLetters = 0.0f;

			bUpdateMessage = false;
		}
		else
		{
			CurrentTimeBetweenLetters = 0.0f;
		}
	}
}