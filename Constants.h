#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "CustomTypesAndAliases.h"
// Usable constants based on google search and assumptions

//Values for Trap Door
namespace Trap {
	inline constexpr TypeAliases::Celcius minTemp{ 60.0 };
	inline constexpr TypeAliases::Celcius maxTemp{ 90.0 };
	inline constexpr TypeAliases::Decibel minSound{ 50.0 };
	inline constexpr TypeAliases::Decibel maxSound{ 90.0 };
	inline constexpr CustomTypes::Smells smell{ CustomTypes::Smells::machineOils };
}

// Values for Safe exit door
namespace Safe {
	inline constexpr TypeAliases::Celcius minTemp{ 10.0 };
	inline constexpr TypeAliases::Celcius maxTemp{ 37.9 };
	inline constexpr TypeAliases::Decibel minSound{ 5.0 };
	inline constexpr TypeAliases::Decibel maxSound{ 14.9 };
	inline constexpr CustomTypes::Smells smell{ CustomTypes::Smells::grass };

}

// Values for Start door
namespace Start {
	inline constexpr TypeAliases::Celcius minTemp{ -40.0 };
	inline constexpr TypeAliases::Celcius maxTemp{ 9.9 };
	inline constexpr TypeAliases::Decibel minSound{ 0.0 };
	inline constexpr TypeAliases::Decibel maxSound{ 4.9 };
	inline constexpr CustomTypes::Smells smell{ CustomTypes::Smells::nothing };
}

namespace Unknown {
	inline constexpr TypeAliases::Celcius minTemp{ 38.0 };
	inline constexpr TypeAliases::Celcius maxTemp{ 59.9 };
	inline constexpr TypeAliases::Decibel minSound{ 15.0 };
	inline constexpr TypeAliases::Decibel maxSound{ 49.9 };
	inline constexpr CustomTypes::Smells smell{ CustomTypes::Smells::unknown };

}


#endif // !CONSTANTS_H
