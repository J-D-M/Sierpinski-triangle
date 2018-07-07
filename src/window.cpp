#include "window.hpp"

namespace sdl2
{

Window::Window(
    const char *title, int x, int y, int width, int height, Uint32 flag)
    : win{SDL_CreateWindow(title, x, y, width, height, flag)}
{
	if (!win)
		error("Failed to created window");
}

Window::~Window() { SDL_DestroyWindow(win); }
} // namespace sdl2
