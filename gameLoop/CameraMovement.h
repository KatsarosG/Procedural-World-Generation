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
        if (cameraView.getRotation() == 45) {
            cameraView.move(-1.f*speed, -1.f*speed);
        } else {cameraView.move(-1.f*speed, 0.f);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (cameraView.getRotation() == 45) {
            cameraView.move(1.f*speed, 1.f*speed);
        } else {cameraView.move(1.f*speed, 0.f);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (cameraView.getRotation() == 45) {
            cameraView.move(1.f*speed, -1.f*speed);
        } else {cameraView.move(0.f, -1.f*speed);}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (cameraView.getRotation() == 45) {
            cameraView.move(-1.f*speed, 1.f*speed);
        } else {cameraView.move(0.f, 1.f*speed);}
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