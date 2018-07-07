#pragma once

#include <SDL2/SDL.h>

#include "error.hpp"

namespace sdl2
{

class Event
{
      public:
	auto poll() -> int;
	auto type() -> Uint32;

      private:
	SDL_Event event;
};

} // namespace sdl2
