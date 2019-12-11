#include "Population.h"
#include <Solution.h>


Population::Population(){
}


Population::~Population(){
}

size_t Population::size() const{
	return mSolution.size();
}

void Population::set(size_t size, Solution & const SolutionSample){
}

Solution & Population::operator[](size_t pos){
	return *mSolution.at(pos);
}

Solution const & Population::operator[](size_t pos) const{
	return *mSolution.at(pos);
}

void Population::processFitness(){
}

void Population::randomize(){
}

void Population::encode(){
}

void Population::decode(){
}

//TODO
void Population::quicksort(std::vector<Solution*>solutions, int left, int right) {
	int leftTemp{ left }, rightTemp{ right };
	int pivot = solutions[left]->fitness();
	while (left < right) {
		while ((solutions[right]->fitness() >= pivot) && (left < right))
			right--;
		if (left != right) {
			solutions[left] = solutions[right];
			left++;
		}
		while ((solutions[left]->fitness() <= pivot) && (left < right))
			left++;
		if (left != right) {
			solutions[right] = solutions[left];
			right--;
		}
	}
	//BUG A REGLER
	//solutions[left]->fitness() = pivot;
	pivot = left;
	left = leftTemp;
	right = rightTemp;
	if (left < pivot)
		quicksort(solutions, left, pivot - 1);
	if (right > pivot)
		quicksort(solutions, pivot + 1, right);
}

void Population::sort(){

	quicksort(mSolution, 0, mSolution.size()-1);
}

void Population::swap(Population & other){
}

//EFFACER UNE FOIS LA CLASSE SOLUTION EST FAITE
fitness_t Solution::fitness() const{
	return mFitness;
}
//---------------------------------------------
