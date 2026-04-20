#include "Overloads.h"
std::ostream& operator<<(std::ostream& cout, CustomTypes::Smells smell) {
	switch (smell)
	{
	case CustomTypes::Smells::machineOils:
		cout << "smell like lubricants and machines.";
		break;
	case CustomTypes::Smells::grass:
		cout << "ah smells like green grass.";
		break;
	case CustomTypes::Smells::unknown:
		cout << "cannot recognise this smell.";
		break;
	case CustomTypes::Smells::nothing:
		cout << "can't smell anything";
		break;
	default:
		break;
	}
	return cout;
}
std::ostream& operator<<(std::ostream& cout, CustomTypes::DoorType door) {
	switch (door)
	{
	case CustomTypes::DoorType::safe:
		cout << "this door is safe";
		break;
	case CustomTypes::DoorType::start:
		cout << "this might lead to another universe";
		break;
	case CustomTypes::DoorType::trap:
		cout << "this might be a trap";
		break;
	case CustomTypes::DoorType::unknown:
		cout << "this is something... I can't say";
		break;
	default:
		break;
	}
	return cout;
}
