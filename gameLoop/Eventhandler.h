#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../setup/init.h"

using namespace std;

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

void eventHandler(void);
void eventHandler(void) {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::Resized) {
            // update the view to the new size of the window
            cameraView.setSize(event.size.width, event.size.height);
            gui.setSize(event.size.width, event.size.height);
            gui.setCenter(event.size.width/2,event.size.height/2);
            screenWidth = window.getSize().x;
            screenHeight = window.getSize().y;
        }
    }
}

#endif