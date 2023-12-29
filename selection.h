#ifndef SELECTION_H
#define SELECTION_H
#include "merge.h"
#include <iostream>
#include <vector>
using namespace std;

//selection sort algorithm
void selectSort(vector<int> &arr, int &moves, int &comparisons){
	int max;
	int p; //position when placed in array
  int temp; //placeholder
    
  for(int i = 1000; i > 0; i--){
    //initialize 
    max = i;
		p = 0;
    moves++; //counter
		for(int j = 0; j < i; j++){ 
			if(arr[j] > max){
        comparisons++; //counter
				max = arr[j];
				p = j;
		  }
    }
    temp = arr[p];
    arr[p] = arr[i-1];
    arr[i-1] = temp;
  }
}
#endif