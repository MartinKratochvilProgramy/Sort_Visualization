#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
//#include <chrono>
#include <thread>
#include "Array.h"

int width = 400;
int height = 400;


std::string input;

int main()
{
	Array arr;

	while (input != "q") {
		std::cout << "What sorting algorithm do you want to see? ('q' to exit, 'esc' to break visualisation)" << std::endl;
		std::cout << "Quick Sort:'quick', Bubble Sort: 'bubble', Merge Sort: 'merge'" << std::endl;
		std::cin >> input;

		if (input == "quick") {
			std::cout << "Quick Sort..." << std::endl;

			sf::RenderWindow window(sf::VideoMode(width, height), "Sort visualisation");
			window.setFramerateLimit(60);

			arr.createArray();
			arr.quickSort(0, arr.array.size() - 1, window);

			arr.draw(window, "Quick Sort");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		else if (input == "bubble") {
			std::cout << "Bubble Sort..." << std::endl;

			sf::RenderWindow window(sf::VideoMode(width, height), "Sort visualisation");
			window.setFramerateLimit(60);

			arr.createArray();
			arr.bubbleSort(window);

			arr.draw(window, "Bubble Sort");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
		else if (input == "merge") {
			std::cout << "Merge Sort..." << std::endl;

			sf::RenderWindow window(sf::VideoMode(width, height), "Sort visualisation");
			window.setFramerateLimit(60);

			arr.createArray();
			arr.mergeSort(0, arr.array.size() - 1, window);

			arr.draw(window, "Merge Sort");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));

		}
		else if (input == "q") {
			break;
		}
	}


}