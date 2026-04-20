#include <iomanip>
#include "GuardLogic.h"
#include "Overloads.h"
CustomTypes::DoorType assessDoorTemperature(const auto temperature) {
	// tag as safe exit
	if (temperature >= Safe::minTemp && temperature <= Safe::maxTemp) {
		return CustomTypes::DoorType::safe;
	}
	// tag as trap room
	else if (temperature >= Trap::minTemp && temperature <= Trap::maxTemp) {
		return CustomTypes::DoorType::trap;
	}
	// tag as start room
	else if (temperature >= Start::minTemp && temperature <= Start::maxTemp) {
		return CustomTypes::DoorType::start;
	}
	else {
		return CustomTypes::DoorType::unknown;
	}
}

CustomTypes::DoorType assessDoorLoudness(const auto loudness) {
	// tag as safe exit
	if (loudness >= Safe::minSound && loudness <= Safe::maxSound) {
		return CustomTypes::DoorType::safe;
	}
	// tag as trap room
	else if (loudness >= Trap::minSound && loudness <= Trap::maxSound) {
		return CustomTypes::DoorType::trap;
	}
	// tag as start room
	else if (loudness >= Start::minSound && loudness <= Start::maxSound) {
		return CustomTypes::DoorType::start;
	}
	else {
		return CustomTypes::DoorType::unknown;
	}
}

CustomTypes::DoorType assessDoorSmell(const CustomTypes::Smells smell) {
	// tag as safe exit
	if (smell == CustomTypes::Smells::grass) {
		return CustomTypes::DoorType::safe;
	}
	// tag as trap room
	else if (smell == CustomTypes::Smells::machineOils) {
		return CustomTypes::DoorType::trap;
	}
	// tag as start room
	else if (smell == CustomTypes::Smells::nothing) {
		return CustomTypes::DoorType::start;
	}
	else {
		return CustomTypes::DoorType::unknown;
	}
}

CustomTypes::DoorType assessDoor(const DoorParameters* door) {
	if (!door) {
		std::cout << "Cannot assess door.\n";
		return CustomTypes::DoorType::unknown;
	}

	auto Temperature_result{ assessDoorTemperature(door->getTemperature()) };
	auto Loudness_result{ assessDoorLoudness(door->getLoudness()) };
	auto Smell_result{ assessDoorSmell(door->getSmell()) };

	if (Temperature_result == Loudness_result && Loudness_result == Smell_result)
		return Temperature_result;

	return CustomTypes::DoorType::unknown;
}

int mainGuard(const Universe* world) {
	if (!world) {
		std::cout << "Cannot Interact with World.\n";
		return -1;
	}

	std::cout << "I see 3 doors here which should I choose?\n";
	std::cout << "Lets check this door\n\n";

	int StartDoor{};
	int SafeDoor{};

	for (int i{ 1 }; i <= 3; ++i) {
		const auto* door{ world->inspectDoor(i) };
		if (!door) {
			std::cout << "Wait, Door " << i << " is completely missing! Moving on...\n\n";
			continue; 
		}
		std::cout << " --- [GUARD CHECKS DOOR #" << i << "] --- \n\n";
		const auto temp{ door->getTemperature() };
		std::cout << std::fixed << std::setprecision(2) << "Hm, this door has temperature " << temp << " C, ";
		if (temp < 15) {
			std::cout << "its freeezing!!. ";
		}
		else if (temp > 15 && temp < 38) {
			std::cout << "its fine ";
		}
		else {
			std::cout << "its too hot.";
		}
		std::cout << "\n";

		const auto sound{ door->getLoudness() };
		std::cout << "lets hear what is behind it, ";
		if (sound >= 50) {
			std::cout << "its too loud";
		}
		else if (sound < 50 && sound > 30) {
			std::cout << "its random noises ";
		}
		else {
			std::cout << "can't hear anything";
		}
		std::cout << "\n";

		const auto smell{door->getSmell()};
		std::cout << "lets smell what is behind this door, " << smell;

		std::cout << "\n";
		const auto doorType{ assessDoor(door) };
		std::cout << " --- [GUARD ASSESSES THIS DOOR] --- \n";
		if (doorType == CustomTypes::DoorType::start) {
			StartDoor = i;
		}
		else if (doorType == CustomTypes::DoorType::safe) {
			SafeDoor = i;
		}
		std::cout << "Let me see, I think " << doorType;
		std::cout << "\n";
		if (i < 3) {
			std::cout << "Let me check another door";
		}
		std::cout << "\n\n\n";
		
	}
	std::cout << "Time to make a decision\n";

	if (SafeDoor) {
		std::cout << "Door no. " << SafeDoor << " seems like the escape route.\n";
		std::cout << "Lets choose this.";
		return SafeDoor;
	}
	if (StartDoor) {
		std::cout<< "Door no. " << StartDoor << " seems like way to another universe.\n";
		std::cout << "No one seems like good choice so I should get to another universe.\n";
		return StartDoor;
	}
}