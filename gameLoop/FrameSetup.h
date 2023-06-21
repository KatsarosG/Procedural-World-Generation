#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../setup/init.h"
#include "Fps.h"

using namespace std;

void frameSetup(void);

void frameSetup(void) {
    window.clear(sf::Color::Black);

    visibleTilesX = ceil(cameraView.getSize().x/tileSize);
    visibleTilesY = ceil(cameraView.getSize().y/tileSize);
    
    //get mouse pos
    mouse.screenPos = sf::Mouse::getPosition(window);
    mouse.worldPos = screenToWorld(mouse.screenPos);
    mouse.chunk = worldToChunk(mouse.worldPos);

    mainDt = DtClock.restart().asMilliseconds();
    CalcFps();
}
