#include "renderer.hpp"

namespace sdl2
{

Renderer::Renderer(const Window &win, int index, Uint32 flags)
    : ren{SDL_CreateRenderer(win.win, index, flags)}
{
	if (!ren)
		error("Failed to create renderer");
}

Renderer::~Renderer() { SDL_DestroyRenderer(ren); }

// Set renderer draw color
auto
Renderer::set_draw_color(Color c, Uint8 alpha) -> void
{
	auto [red, green, blue] = c;
	SDL_SetRenderDrawColor(ren, red, green, blue, alpha);
}

// Fill renderer will current color
auto
Renderer::clear() -> void
{
	SDL_RenderClear(ren);
}

// Present renderer
auto
Renderer::present() -> void
{
	SDL_RenderPresent(ren);
}

/*
 * draw a triangle givin its three points
 */

auto
Renderer::draw_triangle(const Triangle &tri) -> void
{
	auto [top, b_left, b_right]{tri};

	SDL_Point points[]{top, b_left, b_right, top};

	SDL_RenderDrawLines(ren, points, 4);
}

} // namespace sdl2
