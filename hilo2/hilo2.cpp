// hilo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void repeat(int x);

unsigned int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // static used for efficiency, so we only calculate this value once
																				// evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool hilo(int random, int n)
{
	std::cout << "Guess #" << n << ": ";
	int guess;
	std::cin >> guess;

	if (guess == random)
	{
		std::cout << "Correct! You win!" << '\n';
		return true;
	}
	else if (guess < random)
	{
		std::cout << "Your guess is too low." << '\n';
		return false;
	}
	else if (guess > random)
	{
		std::cout << "Your guess is too high." << '\n';
		return false;
	}
}

void again(int random)
{
	std::cout << "Would you like to play again? (y/n) ";
	char input;
	std::cin >> input;

	switch (input)
	{
	case 'y':
		repeat(random);
	case 'n':
		std::cout << "Thank you for playing." << '\n';
		break;
	default:
		again(random);
	}
}

void repeat(int random)
{
	std::cout << "Let's play a game. I'm thinking of an integer between 1 and 100. You have 7 tries to guess what it is." << '\n';

	for (int n = 1; hilo(random, n) == false; n = n + 1)
		if (n > 6)
		{
			std::cout << "Sorry, you lose." << '\n';
			break;
		}

	unsigned int randomnext = getRandomNumber(1, 100);
	again(randomnext);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	unsigned int random = getRandomNumber(1, 100);

	repeat(random);

	return 0;
}