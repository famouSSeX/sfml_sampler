#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

using namespace sf; using namespace std::chrono_literals;

int main() {
	RenderWindow window(VideoMode(450, 450), "Laba #9");

	CircleShape shape1(100, 100);
	int shape1_x = 0; int shape1_y = 0;
	shape1.setFillColor(Color::Green);
	shape1.setPosition(shape1_x, shape1_y);

	CircleShape shape2(75, 75);
	int shape2_x = 0; int shape2_y = 200;
	shape2.setFillColor(Color::Yellow);
	shape2.setPosition(shape2_x, shape2_y);

	CircleShape shape3(50, 50);
	int shape3_x = 0; int shape3_y = 350;
	shape3.setFillColor(Color::Cyan);
	shape3.setPosition(shape3_x, shape3_y);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		shape1_x++; shape2_x += 2; shape3_x += 3;
		if (shape1_x > 250)
			shape1_x = 250;

		if (shape2_x > 300)
			shape2_x = 300;

		if (shape3_x > 350)
			shape3_x = 350;
		shape1.setPosition(shape1_x, shape1_y);
		shape2.setPosition(shape2_x, shape2_y);
		shape3.setPosition(shape3_x, shape3_y);

		window.clear();
		window.draw(shape1);
		window.draw(shape2);
		window.draw(shape3);
		window.display();
		std::this_thread::sleep_for(10ms);
	}
	return 0;
}