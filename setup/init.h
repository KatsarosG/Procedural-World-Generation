#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "fastNoise/FastNoise.h"
#include "fastNoise/FastNoise.cpp"

// basic classes
class MouseClass {
    public: 
        int screenX;
        int screenY;
        int worldX;
        int worldY;
};
MouseClass mouse;

//screen
int screenWidth = 800; int screenHeight = 600;

//tiles
int tileSize = 50;

int visibleTilesX = ceil(screenWidth/tileSize);
int visibleTilesY = ceil(screenHeight/tileSize);

//world
int seed = 1337;
float waterLevel = 1.2;

//window
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
sf::ContextSettings settings;

sf::Event event;

//noise
FastNoise heightNoise;
FastNoise heightNoise2;

//sprites
sf::Sprite tile;
sf::Sprite shipSprite;

//views
sf::View cameraView(sf::FloatRect(0.f, 0.f, screenWidth,screenHeight));
sf::View gui(sf::FloatRect(0.f, 0.f, screenWidth,screenHeight));

//textures
sf::Texture blank;
sf::Texture selected;
sf::Texture grass;
sf::Texture sand;
sf::Texture water;
sf::Texture shipTextureSide;
sf::Texture shipTextureFront;
sf::Texture shipTextureBack;
sf::Texture shipTextureSideFront;
sf::Texture shipTextureSideBack;

//clocks
sf::Clock fpsClock;
float fpsClockLastTime = 0;

sf::Clock DtClock;
float mainDt;
int multiplier = 16;

float offsetX = 0;  float offsetY = 0;

//functions
extern float screenToWorldX(int i) {
    float j = (i - offsetX)/tileSize;
    return j;
}
extern float screenToWorldY(int i) {
    float j = (i - offsetY)/(tileSize);
    return j;
}
extern float worldToScreenX(int i) {
    float j = offsetX+(tileSize*i);
    return j;
}
extern float worldToScreenY(int i) {
    float j = offsetY+(tileSize*i);
    return j;
}
