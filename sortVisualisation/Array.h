#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <SFML/Graphics.hpp>

//#include "Global.h"

struct Array
{
	//Array();
	std::vector<int> array;

	void createArray();

	void bubbleSort(sf::RenderWindow& window);

	void quickSort(int low, int high, sf::RenderWindow& window);

	void mergeSort(int const begin, int const end, sf::RenderWindow& window);

	void draw(sf::RenderWindow& window, const std::string& name);

	void printArray();

private:

	void swap(int* p1, int* p2);

	int quickPartition(int low, int high);

	void merge(int const left, int const mid, int const right);

};

