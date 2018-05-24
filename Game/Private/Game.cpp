//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"
#include "Engine/Public/EngineInterface.h"
#include "Engine/Public/SDL.h"
#include "Game\Public\InputManager.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObjectFactory.h"
#include <string>

// Game singleton
MyGame* Singleton<MyGame>::mSingleton = nullptr;

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Sample EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mFontID(-1)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
	mWorld = new World(pEngine);

	mFontID = pEngine->LoadFont("04B_20.ttf", 32);

	GameObjectFactory::Instance()->CreateMissile(mWorld);

	mWorld->Initialize();

}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor(exColor& color) const
{
	color.mColor[0] = 0;
	color.mColor[1] = 0;
	color.mColor[2] = 0;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent(SDL_Event* pEvent)
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run(float fDeltaT)
{
	// Update the input manager
	InputManager::Instance()->Update();

	// Update the world
	mWorld->Update(fDeltaT);

	// This will cause the delay and keep outdated versions of current mouse buttons' states inside prev mouse buttons' states
	InputManager::Instance()->LateUpdate();
}