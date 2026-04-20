#ifndef CONDITIONS_H
#define CONDITIONS_H
#include "CustomTypesAndAliases.h"

// Doors condition that player will assess
class DoorParameters
{
	TypeAliases::Celcius temperature{};
	TypeAliases::Decibel loudness{};
	CustomTypes::Smells smell{ CustomTypes::Smells::unknown };
	CustomTypes::DoorType type{};
public:
	DoorParameters() {}
	DoorParameters(const TypeAliases::Celcius temperature, const TypeAliases::Decibel loudness, const CustomTypes::Smells smell, const CustomTypes::DoorType type) :
		temperature(temperature),
		loudness(loudness),
		smell(smell),
		type(type) {}

	// Getters
	TypeAliases::Celcius getTemperature() const
	{
		return this->temperature;
	}

	TypeAliases::Decibel getLoudness() const
	{
		return this->loudness;
	}
	CustomTypes::Smells getSmell() const
	{
		return this->smell;
	}
	bool checkDoorType(CustomTypes::DoorType type) const
	{
		return this->type == type;
	}
};

#endif // !CONDITIONS_H
