// merge_sort_secvential.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>

#define MAX_SIZE 100000

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1];
	int *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // start index of first subarray 
	j = 0; // start index of second subarray 
	k = l; // start index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* copy the remaining elements of L[]*/
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[]*/
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] R;
	delete[] L;
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// calculate the middle
		int m = l + (r - l) / 2;

		// sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* prints an array */
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int readData(int *arr, string filename)
{
	int nr, value, i;

	ifstream inFile;
	inFile.open(filename.c_str());
	if (inFile.is_open())
	{
		inFile >> nr; 
		for (i = 0; i < nr; i++)
		{
			inFile >> arr[i];
		}

		inFile.close(); 
	}
	else { 
		//Error message
		cout << "Can't find input file! " << endl;
	}
	return nr;
}


int main()
{
	int arr[MAX_SIZE];
	int n;
	n = readData(arr,"in.txt");

	int arr_size = n;

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}

