#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "init.h"

using namespace std;

void generateNoises(void);
void generateNoises(void) {
    heightNoise.SetSeed(seed);
    heightNoise.SetFrequency(0.01);
    heightNoise.SetNoiseType(FastNoise::PerlinFractal);

    heightNoise2.SetSeed(seed);
    heightNoise2.SetFrequency(0.001);
    heightNoise2.SetNoiseType(FastNoise::PerlinFractal);
}
