#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
using namespace std;

//note merge sort will not have any moves due to the fact that 
void mergeSort(vector<int> &arr, int low, int high, int &moves, int &comparisons){
  int middle = (low + high)/2;
  int list1 = middle - low + 1;
	int list2 = high - middle;
  int int1 = 0;
  int int2 = 0;
  int n = low;

	vector<int> arr1(list1);
	vector<int> arr2(list2);
  
	if (low < high){
		mergeSort(arr, low, middle, moves, comparisons);
		mergeSort(arr, middle+1, high, moves, comparisons);
	
	  for (int i=0; i<list1; i++){
		  arr1[i] = arr[low+i];
	  }
	  for (int i=0; i<list2; i++){
		  arr2[i] = arr[middle+1+i];
	  }

	  

  
	while (int1 < list1 && int2 < list2){
		comparisons++;
		if (arr1[int1] < arr2[int2]){
			arr[n] = arr1[int1];
			int1++; 
		}
		else {
			arr[n] = arr2[int2];
			int2++; 
		}
		n++;
	}

  //if array 1 or 2 runs out of rumbers, place remaining at end of merged list
	while (int1 < list1){
		arr[n] = arr1[int1];
    moves++;
		n++; int1++; 
	}
	while (int2 < list2){
		arr[n] = arr2[int2];
    moves++;
		n++; int2++; 
	}
	}
}

#endif