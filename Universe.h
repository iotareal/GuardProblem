#ifndef UNIVERSE_H
#define UNIVERSE_H
#include "CustomTypesAndAliases.h"
#include "DoorParameters.h"
#include "Random.h"
#include "DoorGenerator.h"

// Universe class generates new set of doors for every new universe
class Universe{
	DoorParameters* door_1{ nullptr };
	DoorParameters* door_2{ nullptr };
	DoorParameters* door_3{ nullptr };

	// returns random door type
	CustomTypes::DoorType getDoortype() {
		auto type = Random::pickRandomDoorType();
		while (type == CustomTypes::DoorType::start) {
			type = Random::pickRandomDoorType();
		}
		return type;
	}
public:
	Universe() {
		int startDoor{ Random::randInt(1,3) };
		if (startDoor == 1) door_1 = getDoor(CustomTypes::DoorType::start);
		else if (startDoor == 2) door_2 = getDoor(CustomTypes::DoorType::start);
		else door_3 = getDoor(CustomTypes::DoorType::start);

		while (!door_1) {
			door_1 = getDoor(getDoortype());
		}

		while (!door_2) {
			auto type = getDoortype();
			if (!door_1->checkDoorType(type)) {
				door_2 = getDoor(type);
			}
		}

		while (!door_3) {
			auto type = getDoortype();
			if (!door_1->checkDoorType(type) && !door_2->checkDoorType(type)) {
				door_3 = getDoor(type);
			}
		}
	}

	const DoorParameters* inspectDoor(const int serial) const {
		if (serial == 1) return door_1;
		else if (serial == 2) return door_2;
		else return door_3;

		return nullptr;
	}
	~Universe() {
		delete door_1;
		delete door_2;
		delete door_3;
		door_1 = nullptr;
		door_2 = nullptr;
		door_3 = nullptr;
	}
};
#endif // !UNIVERSE_H
