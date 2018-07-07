#include "event.hpp"

namespace sdl2
{
auto
Event::poll() -> int
{
	return SDL_PollEvent(&event);
}

auto
Event::type() -> Uint32
{
	return event.type;
}
} // namespace sdl2
