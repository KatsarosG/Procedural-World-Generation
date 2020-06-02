#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../setup/init.h"

using namespace std;

void frameSetup(void);
void frameSetup(void) {
    //window.clear(sf::Color::Black);
    //screenWidth = window.getSize().x;
    //screenHeight = window.getSize().y;

    visibleTilesX = ceil(cameraView.getSize().x/tileSize);
    visibleTilesY = ceil(cameraView.getSize().y/tileSize);
    
    //visibleTilesX = ceil(screenWidth/tileSize);
    //visibleTilesY = ceil(screenHeight/tileSize);

    sf::Vector2i tempxy = sf::Mouse::getPosition(window);
    mouse.screenX = tempxy.x;    mouse.screenY = tempxy.y;
    mouse.worldX = screenToWorldX(mouse.screenX);
    mouse.worldY = screenToWorldY(mouse.screenY);

    //offsetX = cameraView.getCenter().x;
    //offsetY = cameraView.getCenter().y;

    mainDt = DtClock.restart().asMilliseconds();
}
