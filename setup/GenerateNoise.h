#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "init.h"

using namespace std;

void generateNoises(void);
double getNoise();
double getFinalNoise(int, int);

void generateNoises(void) {
    heightNoiseLand.SetSeed(seed);
    heightNoiseLand.SetFrequency(0.01);
    heightNoiseLand.SetNoiseType(FastNoise::Perlin);

    noiseForNoise2.SetSeed(seed);
    noiseForNoise2.SetFrequency(0.005);
    noiseForNoise2.SetNoiseType(FastNoise::Perlin);

    heightNoise2.SetSeed(seed);
    heightNoise2.SetFrequency(0.1);
    heightNoise2.SetNoiseType(FastNoise::Perlin);

    noiseForNoise3.SetSeed(seed);
    noiseForNoise3.SetFrequency(0.001);
    noiseForNoise3.SetNoiseType(FastNoise::Perlin);

    heightNoise3.SetSeed(seed);
    heightNoise3.SetFrequency(0.05);
    heightNoise3.SetNoiseType(FastNoise::Perlin);

}
double getNoise(FastNoise noise, int x, int y, double multiplier, double exp) {
    double r = ((noise.GetNoise(x,y)+1)/2)*multiplier;
    r = pow(r,exp);
    return r;
}

double getFinalNoise(int x, int y) {
    double r;
    r = getNoise(heightNoiseLand, x, y, 0.9, 1.2);
    r += getNoise(heightNoise2, r*1000, y, getNoise(noiseForNoise2, x, y, 0.2, 1.5), 1);
    r += abs(getNoise(heightNoise3, x, y, getNoise(noiseForNoise3, r*1234, y, 1, 1.2), 3));
    return r;

}
