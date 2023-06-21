#include <iostream>

#include "../setup/init.h"

void makeWorld(void);

void makeWorld(void) {
    renderedChunks = 0;
    window.setView(cameraView);
    int firstX = (cameraView.getCenter().x - cameraView.getSize().x/2)/chunkSize/tileSize-1;
    int lastX = (cameraView.getCenter().x + cameraView.getSize().x/2)/chunkSize/tileSize+1;
    int firstY = (cameraView.getCenter().y - cameraView.getSize().y/2)/chunkSize/tileSize-1;
    int lastY = (cameraView.getCenter().y + cameraView.getSize().y/2)/chunkSize/tileSize+1;

    for (int cx = firstX; cx < lastX; cx++){
        if (firstX < 0) {firstX = 0;}
        for (int cy = firstY; cy < lastY; cy++) {
            if (cx >= -nOfChunks/2 && cy >= -nOfChunks/2 && cx < nOfChunks/2 && cy < nOfChunks/2) {
                renderedChunks +=1;
                for (int tx = 0; tx < chunkSize; tx++) {
                    for (int ty = 0; ty < chunkSize; ty++) {
                            double tileHeight = chunkArray[cx+nOfChunks/2][cy+nOfChunks/2].tile(tx, ty)->getHeight();
                            if (tileHeight < waterLevel) {
                                tile.setTexture(water);
                            } else if (tileHeight <= waterLevel+0.01){
                                tile.setTexture(sand);
                            } else {
                                tile.setTexture(grass);
                            }
                            
                            tile.setPosition(cx*chunkSize*tileSize+tx*tileSize, cy*chunkSize*tileSize+ty*tileSize);

                            tileHeight = -abs(tileHeight - waterLevel);
                            double dark = 1.5; //[0.5-...]
                            int incriments = 8; // [1-255]
                            tileHeight = (floor((tileHeight+dark)*incriments))*((255/dark)/incriments);

                            tile.setColor(sf::Color(tileHeight,tileHeight,tileHeight));
                            window.draw(tile);
                        }
                    }  
            }
        }
    }
}