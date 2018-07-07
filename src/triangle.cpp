#include "triangle.hpp"

Sierpinski::Sierpinski(std::vector<Triangle> t) : sub_triangles{t} {}

constexpr static auto
halfway_point(SDL_Point p1, SDL_Point p2) -> SDL_Point
{
	return {(p1.x + p2.x) / 2, (p1.y + p2.y) / 2};
}

static auto
get_new_triangles(const Triangle &triang) -> std::vector<Triangle>
{
	auto [top, bottom_left, bottom_right]{triang};

	Triangle top_tri{top,
	                 halfway_point(top, bottom_left),
	                 halfway_point(top, bottom_right)};

	Triangle left_tri{halfway_point(top, bottom_left),
	                  bottom_left,
	                  halfway_point(bottom_left, bottom_right)};

	Triangle right_tri{halfway_point(top, bottom_right),
	                   halfway_point(bottom_left, bottom_right),
	                   bottom_right};

	return {top_tri, left_tri, right_tri};
}

auto
Sierpinski::iterate() -> void
{
	std::vector<Triangle> tmp;

	for (const auto &triangle : sub_triangles)
		for (auto new_triangle : get_new_triangles(triangle))
			tmp.push_back(new_triangle);

	sub_triangles = tmp;
}

auto
Sierpinski::get_sub_triangles() -> std::vector<Triangle>
{
	return sub_triangles;
}
