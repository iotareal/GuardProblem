#ifndef RANDOM_MT_H
#define RANDOM_MT_H
// Some functions to generate random universe and arbitrary conditions
#include <chrono>
#include <random>
#include "CustomTypesAndAliases.h"

namespace Random
{
	// Generates Seeded Mersenne Twister
	inline std::mt19937 generate()
	{
		std::random_device rd{};

		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd(),rd(),rd() };

		return std::mt19937{ ss };
	}

	// Created Mersenne Twister
	inline auto mt{ generate() };

	inline int randInt(const int min, const int max) {
		return std::uniform_int_distribution{ min,max }(mt);
	}

	//Generate Random Temperature(Celcius Alias for double)
	inline TypeAliases::Celcius getTemperature_rand(TypeAliases::Celcius min, TypeAliases::Celcius max) {
		return std::uniform_real_distribution<TypeAliases::Celcius>{min, max}(mt);
	}

	//Generate Random Noise level (Decibel Alias for double)
	inline TypeAliases::Decibel getLoudness_rand(TypeAliases::Decibel min, TypeAliases::Decibel max) {
		return std::uniform_real_distribution<TypeAliases::Decibel>{min, max}(mt);
	}

	// Generates Random Smell (enum Smells)
	inline CustomTypes::Smells getSmell_rand()
	{
		return static_cast<CustomTypes::Smells>(std::uniform_int_distribution{
			static_cast<short>(CustomTypes::Smells::nothing),
			std::max(
				static_cast<short>(CustomTypes::Smells::machineOils),
				static_cast<short>(CustomTypes::Smells::unknown))
			}(mt));
	}

	// Generates random door type (used to create universe)
	inline CustomTypes::DoorType pickRandomDoorType() {
		return static_cast<CustomTypes::DoorType>(std::uniform_int_distribution{
			static_cast<short>(CustomTypes::DoorType::unknown),
			static_cast<short>(CustomTypes::DoorType::safe) }(mt)
			);
	}

	// Reseeds Mersenne Twister
	inline void reseed() {
		mt = generate();
	}
}

#endif