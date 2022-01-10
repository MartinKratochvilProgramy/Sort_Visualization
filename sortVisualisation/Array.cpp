#pragma once
#include "Array.h"

extern int width;

void Array::createArray() {
	array.clear();
	for (int i = 0; i < width; i++)
	{
		array.push_back(i);
	}
	std::random_shuffle(std::begin(array), std::end(array));
}

void Array::printArray() {
	int count = 1;
	for (int item : array) {
		std::cout << item << " ";
		if (count % 10 == 0) {
			std::cout << std::endl;
		}
		count++;
	}
}

void Array::bubbleSort(sf::RenderWindow& window) {
	bool done;

	while (window.isOpen())
	{
		//bubble sort
		done = true;
		for (int i = 0; i < array.size() - 1; i++)
		{
			if (array[i] < array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				done = false;
			}
		}
		draw(window, "Bubble Sort");
		if (done == true) window.close();
	}

}

void Array::quickSort(int low, int high, sf::RenderWindow& window)
{
	if (window.isOpen())
	{
		draw(window, "Quick Sort");

		if (low < high)
		{
			//pozice pivotu
			int pi = quickPartition(low, high);

			// Separately sort elements before
			// partition and after partition
			quickSort(low, pi - 1, window);
			quickSort(pi + 1, high, window);

		}
	}

}

int Array::quickPartition(int low, int high)
{
	int pivot = array[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{

		if (array[j] > array[high])			// > or <= sets descending/ascending
		{
			i++;    // increment index of smaller element
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void Array::mergeSort(int const begin, int const end, sf::RenderWindow& window)
{
	if (window.isOpen())
	{
		draw(window, "Merge Sort");

		if (begin >= end) {
			return; // Returns recursively
		}

		auto mid = begin + (end - begin) / 2;
		mergeSort(begin, mid, window);
		mergeSort(mid + 1, end, window);
		merge(begin, mid, end);

	}

}

void Array::merge(int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, // Initial index of first sub-array
		indexOfSubArrayTwo = 0; // Initial index of second sub-array
	int indexOfMergedArray = left; // Initial index of merged array

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne] > rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void Array::draw(sf::RenderWindow& window, const std::string& name)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
	}

	window.clear();
	for (int i = 0; i < width; i++)
	{
		sf::CircleShape circle;
		circle.setPosition(i, array[i]);
		circle.setRadius(1);
		circle.setFillColor(sf::Color::Red);

		window.draw(circle);
	}

	sf::Font font;
	font.loadFromFile("Fonts/OpenSans-Regular.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString(name);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::Red);
	window.draw(text);

	window.display();
}

void Array::swap(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}