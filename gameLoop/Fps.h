#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../setup/init.h"

using namespace std;

void CalcFps(void);
void drawFpsText(void);

void CalcFps(void) {
    float currentTime = fpsClock.getElapsedTime().asSeconds();
    int fps = 1.f / (currentTime - fpsClockLastTime);
    if (floor(currentTime) != floor(fpsClockLastTime)) {
        fpsText.setString("FPS: " + to_string(fps));
    }
    fpsClockLastTime = currentTime;
}