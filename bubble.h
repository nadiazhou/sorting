#ifndef BUBBLE_H
#define BUBBLE_H
#include "merge.h"
#include <iostream>
#include <vector>
using namespace std;

//bubble sort algorithm
void bubbleSort(vector<int> &arr, int &moves, int &comparisons){
	bool swap;
  
	for (int i=0; i < arr.size()-1; i++){
		swap = false;
		for (int j=0; j<arr.size()-i-1; j++){
			comparisons++;
			if (arr[j] > arr[j+1]){
				moves++;
        
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        
				swap = true;
			}
		}
    //break out of algorithm when no numbers left to sort
		if (swap == false){
			break;
		}
	}
}

#endif