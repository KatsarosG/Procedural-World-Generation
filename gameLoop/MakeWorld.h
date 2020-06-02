#include <iostream>

#include "../setup/init.h"

void makeWorld(void);
void makeWorld(void) {
    window.clear(sf::Color::Black);
    for (int x = -offsetX/tileSize - cameraView.getSize().x/tileSize/2 + 1; x < visibleTilesX - offsetX/tileSize + cameraView.getSize().x/tileSize/2 + 1; x++) {
        for (int y = -offsetY/tileSize - cameraView.getSize().y/tileSize/2 + 1; y < visibleTilesY - offsetY/tileSize + cameraView.getSize().y/tileSize/2 + 1; y++) {
            float tileHeight = heightNoise.GetNoise(x, y);
            tileHeight += 1;
			if (tileHeight > waterLevel && tileHeight < waterLevel + 0.05) {
				tile.setTexture(sand);
			} else if (tileHeight > waterLevel) {
                tile.setTexture(grass);
            } else {
                tile.setTexture(water);
            }
            tile.setPosition(worldToScreenX(x),worldToScreenY(y));

            tileHeight = -abs(tileHeight - waterLevel);
            tileHeight += 1;
            tileHeight *= 10;
            tileHeight = floor(tileHeight);
            tileHeight *= 15;
            tileHeight += 119;

            tile.setColor(sf::Color(tileHeight,tileHeight,tileHeight));
            window.setView(cameraView);
            window.draw(tile);
        }
    }
}