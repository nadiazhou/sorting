//NADIA ZHOU
//Sorting using recursive algorithms
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <chrono>

#include "merge.h"
#include "quick.h"
#include "bubble.h"
#include "selection.h"

using namespace std;

//prototype
void reset(int &moves, int &comparisons, vector<int> &cop, vector<int> arr);
void result(int &moves, int &comparisons, long time, vector<int> &cop, vector<int> arr);

int main() {
  //initialuze
	srand(time(0));
	int moves=0;
  int comparisons=0;
  vector<int> random(1000);

  //generate and print 1000 num array
	for (int i = 0; i < 1000; i ++){
    random[i] = rand() % 1000 + 1 ;
    cout << random[i] << " ";
    }

  // atbs - array to be sorted, copy of the original array that is sorted with each 
  vector<int> atbs = random;

  //TIMER - runs the algorithm, uses time.h and chrono to record the time interval to which it starts and finished //***************************************************************************************************************
	//BUBBLE SORT 
	auto start = chrono::high_resolution_clock::now();//start timer
	bubbleSort(atbs, moves, comparisons);
	auto stop = chrono::high_resolution_clock::now(); //finish timer 
	auto duration = chrono::duration_cast<chrono::nanoseconds>(stop-start); //records interval

  cout << endl << endl << "bubble sort-------------------------------------------------------------- " << endl;
	result(moves, comparisons, duration.count(), atbs, random);
  //***************************************************************************************************************
	//SELECTION SORT
	start = chrono::high_resolution_clock::now();
	selectSort(atbs, moves, comparisons);
	stop = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);

  cout << "selection sort--------------------------------------------------------------" << endl;
	result(moves, comparisons, duration.count(), atbs, random);
  //***************************************************************************************************************
	//QUICK SORT
	start = chrono::high_resolution_clock::now();
	quickSort(atbs, 0, 999, moves, comparisons); 
	stop = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);

  cout << "quick sort--------------------------------------------------------------" << endl;
	result(moves, comparisons, duration.count(), atbs, random);

  //***************************************************************************************************************
	//MERGE SORT
	start = chrono::high_resolution_clock::now();
	mergeSort(atbs, 0, 999, moves, comparisons);
	stop = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::nanoseconds>(stop-start);

  cout << "merge sort--------------------------------------------------------------" << endl;
	result(moves, comparisons, duration.count(), atbs, random);
	return 0;
}

//prints result for each sorting type 
void result(int &moves, int &comparisons, long time, vector<int> &cop, vector<int> arr){
	cout << "COMPARISONS: " << comparisons << endl <<"MOVES: " << moves << endl << "TIME: " << time << " nanoseconds" << endl << endl; 
  moves = 0; comparisons = 0; cop = arr;
}
