#pragma once

#include <tuple>

#include "error.hpp"
#include "triangle.hpp"
#include "window.hpp"

namespace sdl2
{

// Typedefs
using Color = std::tuple<Uint8, Uint8, Uint8>;

// Color constants
namespace color
{
const Color red{0xff, 0x0, 0x0};
const Color green{0x0, 0xff, 0x0};
const Color blue{0x0, 0x0, 0xff};
const Color white{0xff, 0xff, 0xff};
const Color black{0x0, 0x0, 0x0};
} // namespace color

class Renderer : Error
{
      public:
	// SDL renderer constants
	static const auto accelerated{SDL_RENDERER_ACCELERATED};

	Renderer(const Window &win, int index, Uint32 flags);
	~Renderer();

	auto set_draw_color(Color c, Uint8 alpha) -> void;
	auto clear() -> void;
	auto present() -> void;

	auto draw_triangle(const Triangle &tri) -> void;

      private:
	SDL_Renderer *ren;
};

} // namespace sdl2
