#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../setup/init.h"

using namespace std;

void showFps(void);
void showFps(void) {
    float currentTime = fpsClock.getElapsedTime().asSeconds();
    int fps = 1.f / (currentTime - fpsClockLastTime);
    fpsClockLastTime = currentTime;

    //cout << fmod(currentTime, 1000) << endl;

    window.setTitle("fps: " + to_string(fps));
    
}