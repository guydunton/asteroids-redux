//-----------------------------------------------------------
// File: LevelCompleteState.h
// Description: Implements GameState. Enters just as the game
//				ends and continues running the game for a couple
//				of seconds before starting a new level
//-----------------------------------------------------------

#ifndef LEVEL_COMPLETE_STATE_H
#define LEVEL_COMPLETE_STATE_H

#include "GameState.h"
#include "..\EventManager\AnimationClock.h"

class LevelCompleteState : public GameState
{
private:
	AnimationClock clock;

	const static float EXIT_TIME;

public:
	LevelCompleteState( GameStateManager* _parent );

	// Virtual functions from GameState
	void Enter();
	void Update( float dt );
	void Exit();

	void Render();
};

#endif