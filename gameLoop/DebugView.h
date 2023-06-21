#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "../setup/init.h"

using namespace std;

void drawDebug(void);

void drawFpsText(void);
void drawMousePosText(void);
void drawCameraViewPosText(void);
void drawRenderedTilesText(void);
void drawSelectedHeightText(void);

void drawDebug() {
    if (lastStateF3 != sf::Keyboard::isKeyPressed(sf::Keyboard::F3)) {
        if (lastStateF3) {
            toggleDebug = !toggleDebug;
        }
        lastStateF3 = sf::Keyboard::isKeyPressed(sf::Keyboard::F3);
    }
    //toggleDebug = !toggleDebug;
    if (toggleDebug) {;
        window.setView(gui);
        drawFpsText();
        drawMousePosText();
        drawCameraViewPosText();
        drawRenderedTilesText();
        drawSelectedHeightText();
    }
}

void drawFpsText() {
    window.draw(fpsText);
}

void drawMousePosText() {
    mousePosText.setPosition(10, 30);
    mousePosText.setString("Mouse Screen Position X/Y: " + to_string(int(mouse.screenPos.x)) + " / " + to_string(int(mouse.screenPos.y)));
    window.draw(mousePosText);
    mousePosText.setPosition(10, 50);
    mousePosText.setString("Mouse World Position X/Y: " + to_string(int(mouse.worldPos.x)) + " / " + to_string(int(mouse.worldPos.y)));
    window.draw(mousePosText);
    mousePosText.setPosition(10, 70);
    mousePosText.setString("Mouse Chunk X/Y: " + to_string(int(mouse.chunk.x)) + " / " + to_string(int(mouse.chunk.y)));
    window.draw(mousePosText);
}

void drawCameraViewPosText() {
    cameraViewPosText.setString("Camera View Position X/Y: " + to_string(int(cameraView.getCenter().x/chunkSize/tileSize)) + " / " + to_string(int(cameraView.getCenter().y/chunkSize/tileSize)));
    window.draw(cameraViewPosText);
}

void drawRenderedTilesText() {
    renderedChunksText.setString("Rendered Chunks: " + to_string(renderedChunks));
    window.draw(renderedChunksText);
}

void drawSelectedHeightText() {
    selectedHeightText.setString("Mouse Height: " + to_string(chunkArray[mouse.chunk.x+nOfChunks/2][mouse.chunk.y+nOfChunks/2].tile(0, 0)->getHeight()));
    window.draw(selectedHeightText);
}
