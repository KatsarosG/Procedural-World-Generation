#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "fastNoise/FastNoise.h"
#include "fastNoise/FastNoise.cpp"

// basic classes
class MouseClass {
    public:
        sf::Vector2i screenPos;
        sf::Vector2f worldPos;
        sf::Vector2i chunk;
        sf::Vector2i inChunkPos;
};
MouseClass mouse;

const int tileSize = 50;
int renderedChunks;
class Tile {
private:
    double height;
public:
    double getHeight(void){
        //std::cout << height << std::endl;
        return height;
    }
    void setHeight(double h) {
        //std::cout << h << std::endl;
        height = h;
    }
};

const int chunkSize = 16;
class Chunk {
private:
    Tile tiles[chunkSize][chunkSize];
public:
    Tile *tile(int x, int y) {
        return &tiles[x][y];
    }
};

//screen
int screenWidth = 800; int screenHeight = 600;

//tiles
int visibleTilesX = ceil(screenWidth/tileSize);
int visibleTilesY = ceil(screenHeight/tileSize);

//chunks 
const int nOfChunks = 64;
Chunk chunkArray[nOfChunks][nOfChunks];

//world
int seed = 1337;
float waterLevel = 0.5;

//moveSpeed
int speed = 10;

//Debug
bool toggleDebug = true;

//Key change states;
bool lastStateF3 = false;

//window
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Game");
sf::ContextSettings settings;

sf::Event event;

//noise
FastNoise heightNoiseLand;
FastNoise noiseForNoise2;
FastNoise heightNoise2;
FastNoise noiseForNoise3;
FastNoise heightNoise3;

//sprites
sf::Sprite tile;
sf::Sprite shipSprite;

//views
sf::View cameraView(sf::FloatRect(0.f, 0.f, screenWidth,screenHeight));
sf::View gui(sf::FloatRect(0.f, 0.f, screenWidth,screenHeight));
sf::View minimapView(sf::FloatRect(0.f, 0.f, 200,100));

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

//fonts
sf::Font mainFont;

//Texts
sf::Text fpsText;
sf::Text loadingText;
sf::Text mousePosText;
sf::Text cameraViewPosText;
sf::Text renderedChunksText;
sf::Text selectedHeightText;

//clocks
sf::Clock fpsClock;
float fpsClockLastTime = 0;

sf::Clock DtClock;
float mainDt;
int multiplier = 16;

//HeightMap
struct HeightMap {
    static const int size = 2000; 
    double h[size][size];

    double getHeight(int iX, int iY) {
        return h[iX][iY];
    }

    void setHeight(int iX, int iY, double height){
        h[iX][iY] = height;
    }
};
HeightMap heightMap;

//functions
extern sf::Vector2f screenToWorld(sf::Vector2i screenPos) {
    window.setView(cameraView);
    sf::Vector2f worldPos = window.mapPixelToCoords(screenPos);
    worldPos.x = floor(worldPos.x/tileSize);
    worldPos.y = floor(worldPos.y/tileSize);
    return worldPos;
}
extern sf::Vector2i worldToScreen(sf::Vector2f worldPos) {
    window.setView(cameraView);
    sf::Vector2i screenPos = window.mapCoordsToPixel(worldPos);
    screenPos.x *= tileSize;
    screenPos.y *= tileSize;
    return screenPos;
}
extern sf::Vector2i worldToChunk(sf::Vector2f worldPos) {
    window.setView(cameraView);
    sf::Vector2i chunk = sf::Vector2i(floor(worldPos.x/chunkSize), floor(worldPos.y/chunkSize));
    return chunk;    
}
