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
#include "Game\Public\Debug.h"
#include "Game\Public\World.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\SymbolTable.h"
#include "Game\Public\HashMap.h"
#include "Game\Public\GameObjectHandle.h"
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

	mWorld->Initialize();

	SymbolTable<std::string, float> ST;
	ST.Put("Hello", 8.0f);
	ST.Put("Hi", 15.0f);
	Debug::exOutputLine(ST.Get("Hello"));
	ST.Put("Waddup", 9.0f);
	Debug::exOutputLine(ST.Remove("Hi"));
	Debug::exOutputLine(ST.Get("Hello"));
	ST.Put("Hello", 14.0f);
	Debug::exOutputLine(ST.Get("Hello"));

	HashMap<std::string, float, 256> hM;
	hM.Put("World", 77.0f);
	Debug::exOutputLine(hM.Get("World"));
	hM.Remove("World");
	Debug::exOutputLine(hM.Get("World"));

	GameObject* someGO = new GameObject(mWorld, std::hash<std::string>{} ("Hello"));
	GameObjectHandle someGOHandle = someGO->GetHandle();

	if (someGOHandle.IsValid())
	{
		Debug::exOutputLine(42);
	}

	delete someGO;

	if (!someGOHandle.IsValid())
	{
		Debug::exOutputLine(23);
	}

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