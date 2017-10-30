#include "Random.h"
#include <random>
#include <ctime>


Random::Random()
{
	random();
}


Random::~Random()
{
}

int Random::getValue() const
{
	return value;
}

void Random::setValue(int value)
{
	this->value = value;
}

void Random::random()
{
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<int> distribution(2, 16);
	value = distribution(gen);
}
