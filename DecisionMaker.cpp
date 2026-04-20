#include "DecisionMaker.h"
#include "CustomTypesAndAliases.h"
#include "Constants.h"
bool isDoorSafe(Conditions& door) {
	return
		(door.getLoudness() >= minGrasslandSound && door.getLoudness() <= maxGrasslandSound) &&
		(door.getSmell() == CustomTypes::Smells::grass) &&
		(door.getTemperature() >= minGrasslandTemp && door.getTemperature() <= maxGrasslandTemp);
}
bool isDoorStart(Conditions& door) {
	return
		(door.getLoudness() >= minVoidSound && door.getLoudness() <= maxVoidSound) &&
		(door.getSmell() == CustomTypes::Smells::nothing) &&
		(door.getTemperature() >= minVoidTemp && door.getTemperature() <= maxVoidTemp);
}
bool isDoorTrap(Conditions& door) {
	return
		(door.getLoudness() >= minMachineSound && door.getLoudness() <= maxMachineSound) &&
		(door.getSmell() == CustomTypes::Smells::machineOils) &&
		(door.getTemperature() >= minMachineTemp && door.getTemperature() <= maxMachineTemp);
}
bool isDoorUnknown(Conditions& door) {
	return !(isDoorSafe(door) || isDoorTrap(door) || isDoorStart(door));
}