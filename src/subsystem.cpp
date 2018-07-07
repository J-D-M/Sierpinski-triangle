#include "subsystem.hpp"

namespace sdl2
{

Subsystem::Subsystem(Uint32 flags)
{
	if (SDL_Init(flags) < 0)
		error("Unable to initialize SDL");
}

Subsystem::~Subsystem() { SDL_Quit(); }

} // namespace sdl2
