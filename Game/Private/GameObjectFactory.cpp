#include "..\Public\GameObjectFactory.h"
#include "Game\Public\GameObject.h"
#include "Game\Public\Vector2.h"
#include "Game\Public\COGPhysics.h"
#include "Game\Public\COGTransform.h"
#include "Game\Public\COGBoxShape.h"
#include "Game\Public\COGCircleShape.h"
#include "Game\Public\COGAIController.h"
#include "Game\Public\COGPlayerController.h"
#include "Game\Public\COGBounce.h"
#include "Game\Public\COGReset.h"
#include "Game\Public\COGScorer.h"
#include "Game\Public\World.h"

// Singleton
GameObjectFactory* Singleton<GameObjectFactory>::mSingleton = nullptr;
