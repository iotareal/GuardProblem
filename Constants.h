#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "CustomTypesAndAliases.h"
#include "Random.h"
constexpr TypeAliases::Celcius minTemperature{ -40.0 };
constexpr TypeAliases::Celcius maxTemperature{ 100.0 };

const TypeAliases::Celcius machineTemprature{ Random::getTemperature_rand(60.0,90.0) };
const TypeAliases::Decibel machineLoudness{ Random::getLoudness_rand(87.0,125.0) };


#endif // !CONSTANTS_H
