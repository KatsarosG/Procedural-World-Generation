#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../gameLoop/Eventhandler.h"
#include "LoadTextures.h"
#include "GenerateNoise.h"
#include "init.h"

using namespace std;

void setup(void);
void loadFonts(void);
void setUpTexts(void);
void loadHeightMap(void);

void setup(void) {
    window.setFramerateLimit(60);
    loadFonts();
    loadTextures();
    
    //set random seed;
    srand((unsigned) time(NULL));
    seed = rand();

    generateNoises();

    setUpTexts();
    loadHeightMap();
}

void loadFonts(void) {
    if (!mainFont.loadFromFile("assets/fonts/Pixeled.ttf"))
    {
        cout << "Font Load Failed" <<  endl;
    }
}

void setUpTexts(void) {
    loadingText.setFont(mainFont);
    loadingText.setCharacterSize(12);
    loadingText.setFillColor(sf::Color::White);
    loadingText.setPosition(window.getSize().x/2-125, window.getSize().y/2);

    fpsText.setFont(mainFont);
    fpsText.setCharacterSize(12);
    fpsText.setFillColor(sf::Color::White);
    fpsText.setPosition(10, 10);

    mousePosText.setFont(mainFont);
    mousePosText.setCharacterSize(12);
    mousePosText.setFillColor(sf::Color::White);

    selectedHeightText.setFont(mainFont);
    selectedHeightText.setCharacterSize(12);
    selectedHeightText.setFillColor(sf::Color::White);
    selectedHeightText.setPosition(10, 90);

    cameraViewPosText.setFont(mainFont);
    cameraViewPosText.setCharacterSize(12);
    cameraViewPosText.setFillColor(sf::Color::White);
    cameraViewPosText.setPosition(10, 110);

    renderedChunksText.setFont(mainFont);
    renderedChunksText.setCharacterSize(12);
    renderedChunksText.setFillColor(sf::Color::White);
    renderedChunksText.setPosition(10, 130);

}

void loadHeightMap(void) {
    int loadedChunks = 0;
    window.setView(gui);
    /*
    for(int x = -heightMap.size/2; x < heightMap.size/2; x++) {
        for(int y = -heightMap.size/2; y < heightMap.size/2; y++) {
            double h = getFinalNoise(x, y);
            heightMap.setHeight(x+heightMap.size/2, y+heightMap.size/2, h);
            loadedTiles += 1;
            //Display Loading
            if (loadedTiles % 100000 == 0) {
                eventHandler();
                window.clear(sf::Color::Black);
                loadingText.setString("Loading Height Map: " + to_string(int((float(loadedTiles)/(heightMap.size*heightMap.size))*10)) + " / 10");
                window.draw(loadingText);
                window.display();
            }
        }
    }
    */
    for (int cx = -nOfChunks/2; cx < nOfChunks/2; cx++){
        for (int cy = -nOfChunks/2; cy < nOfChunks/2; cy++) {
            for (int tx = 0; tx < chunkSize; tx++) {
                for (int ty = 0; ty < chunkSize; ty++) {
                    double height = getFinalNoise(cx*chunkSize+tx, cy*chunkSize+ty);
                    chunkArray[cx+nOfChunks/2][cy+nOfChunks/2].tile(tx,ty)->setHeight(height);
                }
            }
            loadedChunks += 1;
            //Display Loading
            if (loadedChunks % 10 == 0) {
                eventHandler();
                window.clear(sf::Color::Black);
                loadingText.setString("Loading Chunks " + to_string(int((float(loadedChunks)/(nOfChunks*nOfChunks))*100)) + " / 100");
                window.draw(loadingText);
                window.display();
            }   
        }
    }
}