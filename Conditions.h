#ifndef CONDITIONS_H
#define CONDITIONS_H
#include "CustomTypesAndAliases.h"

namespace CT = CustomTypes;
namespace TA = TypeAliases;
// Defines Condtion of the rooms and readings of handheld sensor for observer
class Conditions
{
	TA::Celcius temperature{};
	TA::Decibel loudness{};
	CT::Smells smell{ CT::Smells::nothing };
public:
	Conditions(const TA::Celcius temperature, const TA::Decibel loudness, const CT::Smells smell) :
		temperature(temperature),
		loudness(loudness),
		smell(smell) {}

	// Getters
	TA::Celcius getTemperature()
	{
		return this->temperature;
	}

	TA::Decibel getLoudness()
	{
		return this->loudness;
	}
	CT::Smells getSmell()
	{
		return this->smell;
	}
};

#endif // !CONDITIONS_H
