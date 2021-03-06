//-----------------------------------------------------------
// File: LevelStartState.cpp
//-----------------------------------------------------------

#include "LevelStartState.h"

#include "GameStateManager.h"
#include "GameLogic.h"
#include "MainGameState.h"
#include "../Graphics/GraphicsDeviceManager.h"

#include "Globals.h"

const float LevelStartState::INTRO_TIME = 3.0f;

LevelStartState::LevelStartState(const Content& content, GameStateManager* parent) :
	GameState(parent),
	background(content.Textures(), "transparent"),
	font(content.Graphics())
{
	// Set the initial text
	onScreenText = "Level Starts In";
	countDownText = "3";

	// calculate the position of the text on screen
	Vector2 size = font.GetTextSize(onScreenText);
	textPosition = Vector2((WINDOW_WIDTH / 2) - (size.x / 2),
	                       (WINDOW_HEIGHT / 2) - (size.y / 2) - 50);
	size = font.GetTextSize(countDownText);
	countDownPos = Vector2((WINDOW_WIDTH / 2) - (size.x / 2),
	                       (WINDOW_HEIGHT / 2) - (size.y / 2) - 20);
}

void LevelStartState::Enter()
{
	// Begin the countdown before the level starts
	clock.Start();
}

void LevelStartState::Update(float dt, const KeyboardState& /*keyboardState*/)
{
	clock.Tick(dt);

	// Check the time until the level starts
	const float delta = clock.GetDeltaTime();
	if(delta >= INTRO_TIME)
	{
		// Begin the level
		parent->SetState<MainGameState>();
	}
	else
	{
		// Set the onscreen text
		countDownText = std::to_string(static_cast<int>(INTRO_TIME - delta + 1));
	}
}

void LevelStartState::Exit()
{}

void LevelStartState::Render()
{
	parent->GetGameLogic().Render();

	// Darken the level using the transparent sprite
	background.Draw(Vector2(0, 0), 0.6f);

	// Draw the text onto the window
	font.DrawString(onScreenText, textPosition);
	font.DrawString(countDownText, countDownPos);
}
