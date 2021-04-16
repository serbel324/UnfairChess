#include "pch.h"
#include "Engine.h"

#include "Assets.h"
#include "Game.h"

Engine::Engine()
{
    Assets assets("assets/");
    Game game(assets);

    std::cout << "terminated" << std::endl;
    std::cout << "terminated" << std::endl;
}

