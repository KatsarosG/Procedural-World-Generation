#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cmath>

#include "setup/setup.h"
#include "setup/LoadTextures.h"
#include "setup/GenerateNoise.h"
#include "gameLoop/Eventhandler.h"
#include "gameLoop/FrameSetup.h"
#include "gameLoop/MakeWorld.h"
#include "gameLoop/CameraMovement.h"
#include "gameLoop/Fps.h"

using namespace std;

int main() {
    setup();
    loadTextures();
    generateNoises();

    //Game Loop
    while (window.isOpen()) {
        eventHandler();
        frameSetup();
        makeWorld();
        moveCamera();
        showFps();

        window.display();
    }
}