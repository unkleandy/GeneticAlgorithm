#include "Chromosome.h"
#include "RandomTools.h"


Chromosome::Chromosome()
{
}

size_t Chromosome::size() const
{
	return mData.size();
}

void Chromosome::resize(size_t size)
{
	mData.resize(size);
}

std::vector<bool>::reference Chromosome::operator[](size_t pos)
{
	return mData[pos];
}

bool Chromosome::operator[](size_t pos) const
{
	return mData[pos];
}

void Chromosome::read(uint32_t & value, size_t from, size_t length) const
{
	value = 0;
	size_t debutBit = length + from - 1;

	for (size_t i{ 0 }; i < length; ++i) {
		value |= (mData[debutBit - i] << i);
	}
}

void Chromosome::write(uint32_t value, size_t from, size_t length)
{
	int masque;

	for (size_t i{ 0 }; i < length; ++i) {
		masque = 1;
		masque <<= (length - 1) - i;
		mData[from + i] = value & masque;
	}
}

void Chromosome::flip(size_t pos)
{
	mData[pos] = !mData[pos];
}

void Chromosome::randomize(double probability)
{
	for (size_t i{ 0 }; i < size(); ++i) {
		mData[i] = RandomTools::generateEvent(probability);
	}
}

void Chromosome::randomize(size_t from, size_t to, double probability)
{
	for (size_t i{ from }; i < to; ++i) {
		mData[from] = RandomTools::generateEvent(probability);
	}
}