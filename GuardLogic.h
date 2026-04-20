#ifndef GUARDLOGIC_H
#define GUARDLOGIC_H
#include <iostream>
#include "Universe.h"
CustomTypes::DoorType assessDoorTemperature(const auto temperature);
CustomTypes::DoorType assessDoorLoudness(const auto loudness);
CustomTypes::DoorType assessDoorSmell(const CustomTypes::Smells smell);
CustomTypes::DoorType assessDoor(const DoorParameters* door);
int mainGuard(const Universe* world);

#endif // !GUARDLOGIC_H
