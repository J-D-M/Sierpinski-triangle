#pragma once

#include <SDL2/SDL.h>

#include "error.hpp"

namespace sdl2
{

class Subsystem : Error
{
      public:
	Subsystem(Uint32);
	~Subsystem();
};

} // namespace sdl2
