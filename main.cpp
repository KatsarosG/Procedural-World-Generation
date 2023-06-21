#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cmath>

#include "setup/setup.h"
#include "gameLoop/Eventhandler.h"
#include "gameLoop/FrameSetup.h"
#include "gameLoop/MakeWorld.h"
#include "gameLoop/CameraMovement.h"
#include "gameLoop/DebugView.h"

using namespace std;

int main() {
    setup();
    while (window.isOpen()) {
        eventHandler();
        frameSetup();
        makeWorld();
        moveCamera();
        drawDebug();

        window.display();
    }
}