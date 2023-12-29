#ifndef QUICK_H
#define QUICK_H
#include "merge.h"
#include <iostream>
#include <vector>
using namespace std;

 
int order(vector<int> &arr, int low, int high, int &moves, int &comparisons){
  //assigns pivot too highest element of array
	int pivot = arr[high];
	int i = low-1;

  //moves numbers left or right of the pivot depending on their value
	for (int j=low; j<high; j++){
		comparisons++;
		if (arr[j] < pivot){
			i++;
		  int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
			moves++;
		}
	}
  //swap numbers around 
  int temp = arr[i+1];
  arr[i+1] = arr[high];
  arr[high] = temp;
  
  moves++;
	return (i+1);
}

//quick sort algorithm
void quickSort(vector<int> &arr, int low, int high, int &moves, int &comparisons){
	if (low < high){
    
		int m = order(arr, low, high, moves, comparisons);
		
		quickSort(arr, low, m-1, moves, comparisons); //sorts left side of array
		quickSort(arr, m+1, high, moves, comparisons); //right side 
	}
}


#endif