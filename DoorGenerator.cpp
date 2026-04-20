#include "DoorGenerator.h"
DoorParameters* getDoor(CustomTypes::DoorType type) {
	switch (type)
	{
	case CustomTypes::DoorType::safe:
		return new DoorParameters(
			Random::getTemperature_rand(Safe::minTemp, Safe::maxTemp),
			Random::getLoudness_rand(Safe::minSound, Safe::maxSound),
			Safe::smell,
			CustomTypes::DoorType::safe
		);
	case CustomTypes::DoorType::start:
		return new DoorParameters(
			Random::getTemperature_rand(Start::minTemp, Start::maxTemp),
			Random::getLoudness_rand(Start::minSound, Start::maxSound),
			Start::smell,
			CustomTypes::DoorType::start
		);
	case CustomTypes::DoorType::trap:
		return new DoorParameters(
			Random::getTemperature_rand(Trap::minTemp, Trap::maxTemp),
			Random::getLoudness_rand(Trap::minSound, Trap::maxSound),
			Trap::smell,
			CustomTypes::DoorType::trap
		);
	case CustomTypes::DoorType::unknown:
		return new DoorParameters(
			Random::getTemperature_rand(Unknown::minTemp, Unknown::maxTemp),
			Random::getLoudness_rand(Unknown::minSound, Unknown::maxSound),
			Unknown::smell,
			CustomTypes::DoorType::unknown
		);
	default:
		return nullptr;
		break;
	}
}