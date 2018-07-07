#include <cmath>
#include <mutex>
#include <thread>

#include "wrappers.hpp"

using namespace sdl2;

auto
triang_animation(Renderer &  rend,
                 std::mutex &rend_mutex,
                 Sierpinski &sier,
                 bool &      quit,
                 unsigned    depth) -> void
{
	while (!quit) {
		if (!depth) {
			continue;
		}
		// scoping for mutex
		{
		std::lock_guard<std::mutex> guard(rend_mutex);

		for (const auto &triangle : sier.get_sub_triangles())
			rend.draw_triangle(triangle);
		}

		SDL_Delay(750);

		sier.iterate();
		depth--;
	}
}

auto
main() -> int
{

	int width{1024};
	int height{768};

	Subsystem sys(SDL_INIT_VIDEO);

	Window main_win("Sierpinski Triangle",
	                Window::npos,
	                Window::npos,
	                width,
	                height,
	                Window::shown);

	Renderer main_rend(main_win, -1, Renderer::accelerated);
	Event    event;

	// Centered equilateral triangle that fits in window
	int triangle_length{
	    static_cast<int>((width > height ? width : height) * (0.8))};
	int triangle_height{
	    static_cast<int>(std::sqrt(3) * triangle_length / 2)};

	Triangle main_triangle{
	    {width / 2, (height - triangle_height) / 2},
	    {(width - triangle_length) / 2, (height + triangle_height) / 2},
	    {(width + triangle_length) / 2, (height + triangle_height) / 2}};

	Sierpinski sier_triang({main_triangle});

	main_rend.set_draw_color(color::black, 0xff);
	main_rend.clear();
	main_rend.set_draw_color(color::white, 0xff);

	std::mutex main_rend_mutex;

	bool quit{false};

	std::thread async_draw(triang_animation,
	                       std::ref(main_rend),
	                       std::ref(main_rend_mutex),
	                       std::ref(sier_triang),
	                       std::ref(quit),
	                       7);

	while (!quit) {
		while (event.poll()) {
			if (event.type() == SDL_QUIT)
				quit = true;
		}

		std::thread delay(SDL_Delay, (static_cast<int>(1000 / 30)));

		std::lock_guard<std::mutex> rend_guard(main_rend_mutex);
		main_rend.present();

		delay.join();
	}
	async_draw.join();
}
