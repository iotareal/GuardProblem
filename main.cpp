#include <iostream>
#include "Conditions.h"
#include "CustomTypesAndAliases.h"
#include "Random.h"
#include "Overloads.h"
namespace CT = CustomTypes;
namespace TA = TypeAliases;
namespace RNG = Random;

int main()
{
	CT::Universe myuniverse = {
		new Conditions(RNG::getTemperature_rand(1.2, 10.11),RNG::getLoudness_rand(1.2, 100.11),RNG::getSmell_rand()), 
		new Conditions(RNG::getTemperature_rand(1.2, 10.11),RNG::getLoudness_rand(1.2, 100.11),RNG::getSmell_rand()), 
		new Conditions(RNG::getTemperature_rand(1.2, 10.11),RNG::getLoudness_rand(1.2, 100.11),RNG::getSmell_rand()), 
	};

	std::cout << "Random Temprature(C): "<< myuniverse.door_1->getTemperature() <<'\n';
	std::cout << "Smells like: "<< myuniverse.door_2->getSmell() <<'\n';
	std::cout << "Sound like: "<< myuniverse.door_1->getLoudness() <<'\n';

}