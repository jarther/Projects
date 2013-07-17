// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "I wrote a program once. It was terrible." << endl;
	return 0;
}

void mergeSort(vector<int>& list, int start, int end)
{
	//if list is length 1, it is already sorted
	if (start == end)
		return;

	//if we get to here, we need to divide the list further. Determine the midpoint to split the array in two
	int mid = (end-start)/2;

	//call mergeSort on each half of the list
	// !!!!! pointer to list or just list or what?!!!!
	mergeSort(list, start, mid);
	mergeSort(list, mid+1, end);

}

void merge(vector<int>& list, int start, int mid, int end)
{
	vector<int> temp;
	//left and right are basically iterators for the left and right sides of the list
	int left = start;
	int right = mid + 1;

	//while the iterators have not run off their respective sides of the list, keep merging
	while (left <= mid && right <= end)
	{
		if( list.at(left) < list.at(right) )
		{
			temp.push_back(list.at(left));
			left++;
		}
		else //also catches left=right case
		{
			temp.push_back(list.at(right));
			right++;
		}
	}

	//borrow left again as an index
	left = start;
	while ( left < start )
	{
		list[left] = temp.at(left);
		left++;
	}

	//ditch temp
	vector<int>().swap(temp);

	return;
}