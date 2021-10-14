#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
void swap_(RectangleShape& first, RectangleShape& second);
void bubble_sort(std::vector<RectangleShape>& elements, RenderWindow& window, const int size);
int main()
{
	RenderWindow window(VideoMode(400, 300), "Bubble sort visualization!");
	window.setFramerateLimit(20);
	srand(time(0));
	int size;
	float x = 8;
	std::cout << "enter count of elements (less than 50): ";
	std::cin >> size;
	std::vector<RectangleShape> elements(size);
	for (int i = 0; i < size; i++) {
		elements[i].setSize(Vector2f(3, (-rand() % 290) + 2));
		elements[i].setPosition(Vector2f(x, window.getSize().y));
		x += 8;
	}
	int i = 0, j = 0;
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		bubble_sort(elements, window, size);
	}
}
void swap_(RectangleShape& first, RectangleShape& second) {
	int temp = first.getSize().y;
	first.setSize(Vector2f(3, second.getSize().y));
	second.setSize(Vector2f(3, temp));
}
// you can find realization of bubble sort in my repository "simple algorithms cpp"
void bubble_sort(std::vector<RectangleShape>& elements, RenderWindow& window, const int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (elements[j].getSize().y < elements[j + 1].getSize().y) {
				elements[j].setFillColor(Color::Red);
				elements[j + 1].setFillColor(Color::Red);
				swap_(elements[j], elements[j + 1]);
			}
			window.clear();
			for (int i = 0; i < size; i++) {
				window.draw(elements[i]);
			}
			window.display();
			for(int i = 0; i < size; i++)
				elements[i].setFillColor(Color::White);
		}
	}
	window.close();
}