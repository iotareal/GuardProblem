#ifndef RANDOM_MT_H
#define RANDOM_MT_H

#include <chrono>
#include <random>
#include "CustomTypesAndAliases.h"

namespace TA = TypeAliases;
namespace CT = CustomTypes;

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
	
	inline auto mt{ generate() };

	inline TA::Celcius getTemperature_rand(TA::Celcius min, TA::Celcius max) {
		return std::uniform_real_distribution<TA::Celcius>{min, max}(mt);
	}

	inline TA::Decibel getLoudness_rand(TA::Decibel min, TA::Decibel max) {
		return std::uniform_real_distribution<TA::Decibel>{min, max}(mt);
	}

	inline CT::Smells getSmell_rand() 
	{
		return static_cast<CT::Smells>(std::uniform_int_distribution{
			static_cast<short>(CT::Smells::nothing), 
			std::max(static_cast<short>(CT::Smells::grass),static_cast<short>(CT::Smells::machine_oils))}(mt));
	}

	inline void reseed() {
		mt = generate();
	}
}

#endif