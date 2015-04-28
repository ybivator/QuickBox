#ifdef _WIN32
#include "stdafx.h"
#include <Windows.h>
#endif

#include <Game.h>

Game& Game::game()
{
   static Game instance;
   return instance;
}

Game::Game():window(NULL), gamePad(NULL)
{
}
