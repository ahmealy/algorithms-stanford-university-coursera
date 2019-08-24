/************************************************************************
This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.

Your task is to compute the number of inversions in the file given, where the i^{th}ith
row of the file indicates the i^{th}ith entry of an array.

Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures.
***************************************************************************/
#include<iostream>
#include <fstream>
#include<vector>
using namespace std;

long long mMerge(vector<int>& xNums, int xLeft, int lMid, int xRight);
long long mCountInversionsMergeSort(vector<int> &xNums, int xLeft, int xRight);


int main()
{
    std::ifstream infile("IntegerArray.txt");
    int lNum;
    vector<int> lNums;
    while (infile >> lNum)
    {
        lNums.push_back(lNum);
    }
    long long lInvNum = mCountInversionsMergeSort(lNums, 0, lNums.size()-1);
    cout << " Number of inversions are " << lInvNum<<endl;
    return 0;
}

/* This function sorts the input array and returns the
number of inversions in the array */
long long mCountInversionsMergeSort(vector<int> &xNums, int xLeft, int xRight)
{
    if(xLeft == xRight) return 0;

    int lMid;
    long long lInvCnt = 0;
    if (xLeft < xRight)
    {
        lMid = (xLeft + xRight) / 2;

        lInvCnt = mCountInversionsMergeSort(xNums, xLeft, lMid);
        lInvCnt += mCountInversionsMergeSort(xNums, lMid + 1, xRight);

        lInvCnt += mMerge(xNums, xLeft, lMid, xRight);
    }
    return lInvCnt;
}

// This function merges two sorted arrays and returns inversion count in the arrays.
long long mMerge(vector<int> &xNums, int xLeft, int lMid, int xRight)
{
    int i, j, k;
    long long lInvCnt = 0;
    int n1 = lMid - xLeft + 1;
    int n2 =  xRight - lMid;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = xNums[xLeft + i];
    for (j = 0; j < n2; j++)
        R[j] = xNums[lMid + 1 + j];

    /* Merge the temp arrays back into xNums[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = xLeft; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            xNums[k] = L[i];
            i++;
        }
        else
        {
            xNums[k] = R[j];
            j++;
            lInvCnt = lInvCnt + (n1 - i);
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        xNums[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        xNums[k] = R[j];
        j++;
        k++;
    }

    return lInvCnt;
}
