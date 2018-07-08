#include <cmath>

#include "wrappers.hpp"

// Centered equilateral triangle that fits in window
auto
get_sierpinski(int w, int h) -> Sierpinski
{

	int tri_length{static_cast<int>((w > h ? w : h) * (0.8))};
	int tri_height{static_cast<int>(std::sqrt(3) * tri_length / 2)};

	Triangle main_triangle{{w / 2, (h - tri_height) / 2},
	                       {(w - tri_length) / 2, (h + tri_height) / 2},
	                       {(w + tri_length) / 2, (h + tri_height) / 2}};

	return {{main_triangle}};
}

auto
animation(sdl2::Event &event, sdl2::Renderer &rend, Sierpinski &sier) -> void
{
	int depth{8};
	for (bool quit{false}; !quit;) {
		while (event.poll()) {
			if (event.type() == SDL_QUIT)
				quit = true;
			else if (event.type() == SDL_WINDOWEVENT)
				rend.present();
		}

		if (!depth) {
			continue;
		}
		for (const auto &t : sier.get_triangles())
			rend.draw_triangle(t);

		sier.iterate();
		--depth;

		rend.present();
		SDL_Delay(750);
	}
}

auto
main() -> int
{
	using namespace sdl2;

	const int width  = 1024;
	const int height = 768;

	auto sys       = Subsystem(SDL_INIT_VIDEO);
	auto main_win  = Window("Sierpinski Triangle",
                               Window::npos,
                               Window::npos,
                               width,
                               height,
                               Window::shown);
	auto main_rend = Renderer(main_win, -1, Renderer::accelerated);
	auto event     = Event();

	Sierpinski sier{get_sierpinski(width, height)};

	main_rend.set_draw_color(color::black);
	main_rend.clear();
	main_rend.set_draw_color(color::white);

	animation(event, main_rend, sier);
}
