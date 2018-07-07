#pragma once

#include <SDL2/SDL.h>

#include "error.hpp"

namespace sdl2
{
class Renderer;

class Window : Error
{
      public:
	// SDL window constatnts
	static const Uint32 npos{SDL_WINDOWPOS_UNDEFINED};
	static const auto   shown{SDL_WINDOW_SHOWN};

	Window(const char *, int, int, int, int, Uint32);
	~Window();

	friend Renderer;

      private:
	SDL_Window *win;
};

} // namespace sdl2
