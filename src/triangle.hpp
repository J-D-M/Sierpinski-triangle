#pragma once

#include <SDL2/SDL.h>
#include <tuple>
#include <vector>

using Triangle = std::tuple<SDL_Point, SDL_Point, SDL_Point>;

class Sierpinski
{
      public:
	Sierpinski(std::vector<Triangle> t);

	auto iterate() -> void;
	auto get_triangles() -> std::vector<Triangle>;

      private:
	Sierpinski();
	std::vector<Triangle> sub_triangles;
};
