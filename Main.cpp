#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int selectDirectionRandomly() {
	int direction = rand() % 4;

	return direction;
}

int main() {

	RenderWindow* window = new RenderWindow(VideoMode(800, 800), "Random Walk");
	window->setFramerateLimit(60);
	
	srand(time(0));

	RectangleShape* walker = new RectangleShape(Vector2f(4, 4));
	walker->setFillColor(Color::White);
	int x = 400;
	int y = 400;


	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
		}
		walker->setPosition(x, y);

		switch (selectDirectionRandomly())
		{
		case 0:
			x += 1;
			break;
		case 1:
			x -= 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			y -= 1;
		default:
			break;
		}
		
		if (walker) {
			window->draw(*walker);
		}

		window->display();
	}

	return 0;
}