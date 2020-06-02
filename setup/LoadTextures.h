#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "init.h"

using namespace std;

void loadTextures(void);
void loadTextures(void) {
    if (!blank.loadFromFile("assets/textures/textures.png", sf::IntRect(0, 0, tileSize, tileSize))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!selected.loadFromFile("assets/textures/textures.png", sf::IntRect(50, 0, tileSize, tileSize))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!grass.loadFromFile("assets/textures/textures.png", sf::IntRect(100, 0, tileSize, tileSize))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!sand.loadFromFile("assets/textures/textures.png", sf::IntRect(150, 0, tileSize, tileSize))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!water.loadFromFile("assets/textures/textures.png", sf::IntRect(0, tileSize, tileSize, tileSize))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }

    selected.setSmooth(true);
    grass.setSmooth(true);
    sand.setSmooth(true);
    water.setSmooth(true);
}