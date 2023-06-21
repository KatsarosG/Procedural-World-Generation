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

    if (!shipTextureSide.loadFromFile("assets/textures/shipall.png", sf::IntRect(0, 0, 200, 200))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!shipTextureFront.loadFromFile("assets/textures/shipall.png", sf::IntRect(200, 0, 200, 200))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!shipTextureBack.loadFromFile("assets/textures/shipall.png", sf::IntRect(400, 0, 200, 200))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!shipTextureSideFront.loadFromFile("assets/textures/shipall.png", sf::IntRect(0, 200, 200, 200))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }
    if (!shipTextureSideBack.loadFromFile("assets/textures/shipall.png", sf::IntRect(200, 200, 200, 200))) {
        cout << "Texture Load Failed" <<  endl;
        system("pause");
    }

    selected.setSmooth(true);
    grass.setSmooth(true);
    sand.setSmooth(true);
    water.setSmooth(true);
}