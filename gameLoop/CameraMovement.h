#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../setup/init.h"

void moveCamera(void);
void moveCamera(void) { 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        offsetX += 10.f * mainDt / multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        offsetX += -10.f * mainDt / multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        offsetY += 10.f * mainDt / multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        offsetY += -10.f * mainDt / multiplier;
    }

    if (event.mouseWheelScroll.delta == 1) {
        event.mouseWheelScroll.delta = 0;
        cameraView.zoom(0.9);
    }
    if (event.mouseWheelScroll.delta == -1) {
        event.mouseWheelScroll.delta = 0;
        cameraView.zoom(1.1);
    }

}