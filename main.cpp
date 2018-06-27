

#include "stdafx.h"
#include "Blackboard.h"
#include <iostream>

struct Vector2
{
	float x;
	float y;
};

int main()
{
	Blackboard b;
	b.set("speed", 55.3f);

	Vector2* v = new Vector2();
	v->x = 123;
	v->y = 789;

	b.set("velocity", v);

	int speed;
	if (b.get("speed", speed))
	{
		std::cout << speed << std::endl;
	}
	std::cout << b.getType("speed") << std::endl;
	std::cout << b.getType("velocity") << std::endl;

	Vector2* v2 = nullptr;
	if (b.get("velocity", v2))
	{
		std::cout << v2->x << "," << v2->y << std::endl;
	}
	v2->x = 567;


	Vector2* v3 = nullptr;
	if (b.get("velocity", v3))
	{
		std::cout << v3->x << "," << v3->y << std::endl;
	}

	system("pause");
	return 0;
}