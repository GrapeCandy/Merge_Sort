#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <chrono>
#define size_of_array 5

using namespace std;

void merge_sort(int arr[], int start, int end);					//Recurrsive merge sort
void merge(int arr[], int start, int end, int mid);				//Merge two separated array
void Make_best(int arr[], int arr0[]);
void Make_aver(int arr[], int arr1[]);
void Make_worst(int arr[], int num);
void worst_merge(int mid, int num, int arr[], int first[], int second[]);

void main(void)
{
	int arr[size_of_array] = { 0, };							//Array that store original array
	int arr0[size_of_array] = { 0, };							//Array that store best case array
	int arr1[size_of_array] = { 0, };							//Array that store average case array
	int arr2[size_of_array] = { 0, };							//Array that store worst case array

	for (int a = 1; a <= size_of_array; a++) { arr[a - 1] = a; arr2[a - 1] = a; }		//Push number into array in order
	Make_best(arr, arr0);																//Make best case array
	Make_aver(arr, arr1);																//Make average case array
	Make_worst(arr2, size_of_array);													//Make worst case array

	/*Print Original array*/
	cout << "--Original array_best--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print array
	}
	cout << endl << endl;										//Change line two times

	/*Print Original array*/
	cout << "--Original array_aver--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr1[a] << " ";									//Print array
	}
	cout << endl << endl;										//Change line two times

	/*Print Original array*/
	cout << "--Original array_worst--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr2[a] << " ";									//Print array
	}
	cout << endl << endl;										//Change line two times

	cout << "--Simulation_Best--\n";
	clock_t start = clock();										//Check start time in sec
	auto st = chrono::high_resolution_clock::now();					//check start time in ns
	merge_sort(arr0, 0, size_of_array - 1);							//Call merge sort
	clock_t end = clock();											//Check end time in sec
	auto et = chrono::high_resolution_clock::now();					//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;											//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(et - st).count() << " ns" << endl << endl;			//Print sorting time in ns	
	cout << endl;

	cout << "--Simulation_Average--\n";
	clock_t startt = clock();										//Check start time in sec
	auto stt = chrono::high_resolution_clock::now();				//check start time in ns
	merge_sort(arr1, 0, size_of_array - 1);							//Call merge sort
	clock_t endd = clock();											//Check end time in sec
	auto ett = chrono::high_resolution_clock::now();				//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(endd - startt) / CLOCKS_PER_SEC << " sec" << endl;											//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(ett - stt).count() << " ns" << endl << endl;			//Print sorting time in ns	
	cout << endl;

	cout << "--Simulation_Worst--\n";
	clock_t starttt = clock();										//Check start time in sec
	auto sts = chrono::high_resolution_clock::now();				//check start time in ns
	merge_sort(arr2, 0, size_of_array - 1);							//Call insertion sort
	clock_t enddd = clock();										//Check end time in sec
	auto ete = chrono::high_resolution_clock::now();				//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(enddd - starttt) / CLOCKS_PER_SEC << " sec" << endl;											//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(ete - sts).count() << " ns" << endl << endl;			//Print sorting time in ns	
	cout << endl;

	/*Print Sorted array*/
	cout << "--Sorted array_best--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print array
	}
	cout << endl;												//Change line

	/*Print Sorted array*/
	cout << "--Sorted array_aver--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print array
	}
	cout << endl;												//Change line

	/*Print Sorted array*/
	cout << "--Sorted array_worst--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print array
	}
	cout << endl;												//Change line
}

void merge(int arr[], int start, int end, int mid)
{
	int a = start;												//Start of sorting
	int	b = mid + 1;											//Second array's first point after separating
	int	tmp_start = 0;											//Temp array's pointer
	vector<int> tmp;											//Temp array that stores sorted numbers

	while (a <= mid && b <= end)								//While reach to end of two array
	{
		if (arr[a] > arr[b])									//If first array's value is bigger than second array's value
		{
			tmp.push_back(arr[b]);								//Input second array's value to temp array
			b++;												//Move second array's pointer to next
		}
		else if (arr[a] < arr[b])								//If first array's value is smaller than second array's value
		{
			tmp.push_back(arr[a]);								//Input first array's value to temp array
			a++;												//Move first array's pointer to next
		}
	}

	cout << "merge: ";
	for (int t = 0; t < tmp.size(); t++)	cout << tmp[t] << " ";
	cout << endl;

	/*Input remained value to temp array*/
	while (a <= mid)											//Until first array's pointer reach to end of first array
	{
		tmp.push_back(arr[a]);									//Input value to temp array
		a++;													//Move pointer to next
	}
	while (b <= end)
	{
		tmp.push_back(arr[b]);									//Until second array's pointer reach to end of second array
		b++;													//Move pointer to next
	}

	/*Copy to original array*/
	for (int it = start; it <= end; it++)
	{
		arr[it] = tmp[tmp_start];								//Copy unsorted array to original array
		tmp_start++;											//Move temp array's pointer
	}
	cout << "Merging: ";
	for (int t = 0; t < tmp.size(); t++)	cout << tmp[t] << " ";
	cout << endl;
}

void merge_sort(int arr[], int start, int end)
{
	cout << "Separating: ";
	for (int h = start; h <= end; h++)
	{
		cout << arr[h] << " ";
	}
	cout << endl;

	if (start < end)											//Repeat until each array size is 1
	{
		int mid = (start + end) / 2;							//Check middle of array

		merge_sort(arr, start, mid);							//Make first array that has half size of current array
		merge_sort(arr, mid + 1, end);							//Make second array that has half size of current array
		merge(arr, start, end, mid);							//Merge while arranging the array
	}
}

void Make_best(int arr[], int arr0[])
{
	int tmp_arr[size_of_array] = { 0, };						//Array that store temp value
	int end = size_of_array - 1;								//End of array index

	for (int i = 0; i < size_of_array; i++)						//While reach to end of array
	{
		tmp_arr[i] = arr[end];									//tmp_arr's i'th value is arr's end'th value
		end--;													//Move end pointer to front
	}

	for (int j = 0; j < size_of_array; j++)						//While reach to end of array
	{
		arr0[j] = tmp_arr[j];									//Copy tmp_arr's value to arr0
	}
}
 
void Make_aver(int arr[], int arr1[])
{
	int end = size_of_array - 1;								//End of array's index
	int mid = (size_of_array / 2);								//Middle of array

	for (int i = 0; i < mid - 1; i++)							//While reach to middle of array
	{
		arr1[i] = arr[end];										//arr1's i'th value is arr's end'th value
		arr1[end] = arr[i];										//arr1's end'th value is arr's i'th value
		end--;													//Move end pointer to front
	}

	arr1[mid - 1] = arr[mid - 1];								//The middle of two or one value maitain its seat
	arr1[mid] = arr[mid];										//The middle of two or one value maitain its seat	
}

void Make_worst(int arr[], int num)
{
	if (num == 1)	return;										//If input size is 1, retrun function
	else if (num == 2)	return;									//If input size is 2, retrun function

	int a = 0;													//arr's pointer
	int b = 0;													//first or second array's pointer
	int mid = (num + 1) / 2;									//middle of array

	int* first = new int[mid];									//array that stores half of array
	int* second = new int[num - mid];							//Array that stores remain array

	while (1)
	{
		if (a >= num)	break;									//If arr's pointer exceeds num size, break loop
		first[b] = arr[a];										//first array's b'th value is arr's a'th value

		a += 2;													//Add 2 to a
		b++;													//Add 1 to b
	}

	a = 1;														//Initialize a to 1
	b = 0;														//Initialize b to 0
	while (1)
	{
		if (a >= num)	break;									//If arr's pointer exceeds num size, break loop
		second[b] = arr[a];										//Second array's b'th value is arr's a'th value

		a = a + 2;												//Add 2 to a
		b++;													//Add 1 to b
	}

	Make_worst(first, mid);										//Call Make_worst function(separate array)
	Make_worst(second, num - mid);								//Call Make_worst function(separate array)
	worst_merge(mid, num, arr, first, second);					//Merge separated arrays
}
void worst_merge(int mid, int num, int arr[], int first[], int second[])
{
	int tmp;													//Index of first array
	int iter = 0;												//Iterator

	for (tmp = 0; tmp < mid; tmp++) arr[tmp] = first[tmp];		//while reach to middle of array, arr's tmp'th value is first's tmp'th value
	while (1)
	{
		if (iter >= num - mid)	break;							//If inter is greater or equal than (current array's size - middle index), break the loop

		arr[tmp] = second[iter];								//arr's tmp'th value is second's iter'th value
		tmp++;													//move pointer to next
			
		iter++;													//move iterator to next
	}
}

