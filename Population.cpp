 #include "Population.h"
#include "Solution.h"



Population::Population() {
}


Population::~Population() {
}

size_t Population::size() const {
	return mSolutions.size();
}

void Population::set(size_t size, Solution const & solutionSample) {
	for (size_t i{}; i < mSolutions.size(); ++i) {
		delete mSolutions[i];
	}

	mSolutions.resize(size);
	for (size_t i{}; i < mSolutions.size(); ++i) {
		mSolutions[i] = solutionSample.clone();
	}
}

Solution & Population::operator[](size_t pos) {
	return *mSolutions.at(pos);
}

Solution const & Population::operator[](size_t pos) const {
	return *mSolutions.at(pos);
}

void Population::processFitness() {
	for (size_t i{}; i < mSolutions.size(); ++i) {
		mSolutions[i]->processFitness();
	}
}

void Population::randomize() {
	for (size_t i{}; i < size(); ++i)
		mSolutions[i]->randomize();
}

void Population::encode() {
	for (size_t i{}; i < mSolutions.size(); ++i) {
		mSolutions[i]->encode();
	}
}

void Population::decode() {
	for (size_t i{}; i < mSolutions.size(); ++i) {
		mSolutions[i]->decode();
	}
}

void Population::sort() {
	std::sort(mSolutions.begin(), mSolutions.end(), fitness_comparator());
}

void Population::swap(Population & other) {
	mSolutions.swap(other.mSolutions);
}