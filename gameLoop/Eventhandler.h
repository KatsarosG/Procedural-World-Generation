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
    }
}

#endif