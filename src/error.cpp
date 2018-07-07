#include <SDL2/SDL.h>

#include "error.hpp"

namespace sdl2
{
// Log error and exit with failure
auto
Error::error(const char *msg) -> void
{
	SDL_Log("%s"
	        "%s",
	        msg,
	        SDL_GetError());

	exit(EXIT_FAILURE);
}
} // namespace sdl2
