#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int Size;
double SizePercent;
int dataSetSizes[8]{100, 300, 500, 1000, 3000, 5000, 10000, 50000};
vector<int> BaseArr;
long long int steps;
long long int CPUTotal;
long long int StepTotal;

// Utility Functions
void printArray(int arr[], int n)
{
    cout << "(";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << ",";
        }
    }
    cout << ")"
         << "\n";
}

int *newPermutArray(int n)
{
    int *arr = new int[Size];

    for (int i = 0; i < n; i++)
    {

        arr[i] = i + 1;
    }

    random_shuffle(arr, arr + Size);

    for (int i = 0; i < Size; i++)
    {
        BaseArr.push_back(arr[i]);
    }

    return arr;
}

void remakeArray(int arr[])
{

    for (int i = 0; i < Size; i++)
    {
        arr[i] = BaseArr[i];
    }
}

void func_evalMergeIns(int arr[], int n, int m, double k, void (*func)(int[], int, int, double)) // for merge ins sort, has extra parameter
{
    auto start = high_resolution_clock::now();
    func(arr, n, m, k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    remakeArray(arr);
    CPUTotal += duration.count();
}

void func_evalMergeInsSteps(int arr[], int n, int m, double k, void (*func)(int[], int, int, double)) // for merge ins sort, has extra parameter
{
    steps = 0;
    func(arr, n, m, k);
    remakeArray(arr);
    StepTotal += steps;
}

// Functions for Merge-Insertion Sort CPU time

void merge(int arr[], int start, int mid, int end)
{
    int arrOneSize = mid - start + 1; // gives size of first subarray
    int arrTwoSize = end - mid;

    int *arrOne = new int[arrOneSize]; // using the size to create arrays
    int *arrTwo = new int[arrTwoSize];

    for (int i = 0; i < arrOneSize; i++)
    {
        arrOne[i] = arr[start + i]; // copys data from arr to first sub arr, i
                                    // because we are operating on it
    }

    for (int i = 0; i < arrTwoSize; i++)
    {
        arrTwo[i] = arr[mid + 1 + i]; // copys data from arr to second sub arr
    }

    int arrOneIndex = 0;
    int arrTwoIndex = 0;
    int mergedArrIndex = start;

    while (arrOneIndex < arrOneSize &&
           arrTwoIndex < arrTwoSize) // iterate over both subarrs
    {
        if (arrOne[arrOneIndex] <=
            arrTwo[arrTwoIndex]) // if first subarray has smaller or equal value
        {
            arr[mergedArrIndex] = arrOne[arrOneIndex]; // copy data over
            arrOneIndex++;                             // increment index of first subarr
        }
        else
        {
            arr[mergedArrIndex] =
                arrTwo[arrTwoIndex]; // copy data from second subarray over
            arrTwoIndex++;
        }
        mergedArrIndex++;
    }

    while (arrOneIndex <
           arrOneSize) // copy the remaining elements of left if there are any
    {
        arr[mergedArrIndex] = arrOne[arrOneIndex];
        arrOneIndex++;
        mergedArrIndex++;
    }
    while (arrTwoIndex <
           arrTwoSize) ////copy the remaining elements of right if there are any
    {
        arr[mergedArrIndex] = arrTwo[arrTwoIndex];
        arrTwoIndex++;
        mergedArrIndex++;
    }
    delete[] arrOne;
    delete[] arrTwo;
}

void insertionSortM(int arr[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeInsertionSort(int arr[], int start, int stop, double k) // k is switch from merge to insertion 5% of the total array size
{
    if (stop - start <= k)
    {
        insertionSortM(arr, start, stop);
    }

    else
    {
        int mid = start + (stop - start) / 2;      // midpoint to partiton is half of array length
        mergeInsertionSort(arr, start, mid, k);    // partition 1 half of current full array
        mergeInsertionSort(arr, mid + 1, stop, k); // partition 2 half of current full array
        merge(arr, start, mid, stop);
    } // merge both back
}

// functions for Merge Insertion Sort Step avgs

void mergeS(int arr[], int start, int mid, int end)
{
    int arrOneSize = mid - start + 1;
    steps += 3; // +3 for variable assignment
    int arrTwoSize = end - mid;
    steps++; // +1 to assign variable

    int *arrOne = new int[arrOneSize];
    steps++; // +1 to assign variable
    int *arrTwo = new int[arrTwoSize];
    steps++; // +1 to assign variable

    for (int i = 0; i < arrOneSize; i++)
    {
        steps += 3; // +3 for loop
        arrOne[i] = arr[start + i];
    }
    steps++; // +1 for end of loop

    for (int i = 0; i < arrTwoSize; i++)
    {
        steps += 3; // +3 for loop
        arrTwo[i] = arr[mid + 1 + i];
        steps++; // +1 to assign variable
    }
    steps++; // +1 for end of loop
    int arrOneIndex = 0;
    steps++; // +1 to assign variable
    int arrTwoIndex = 0;
    steps++; // +1 to assign variable
    int mergedArrIndex = start;
    steps++; // +1 to assign variable

    while (arrOneIndex < arrOneSize && arrTwoIndex < arrTwoSize)
    {
        steps += 2; // +2 for while loop
        if (arrOne[arrOneIndex] <= arrTwo[arrTwoIndex])
        {
            arr[mergedArrIndex] = arrOne[arrOneIndex];
            arrOneIndex++;
        }
        else
        {
            arr[mergedArrIndex] = arrTwo[arrTwoIndex];
            steps++; // +1 for variable incrementation
            arrTwoIndex++;
        }
        steps++; // +1 for if
        mergedArrIndex++;
        steps++; // +1 for variable incrementation
    }
    steps += 1; // +1 for end of while loop

    while (arrOneIndex < arrOneSize)
    {
        steps += 1; // +1 for while loop
        arr[mergedArrIndex] = arrOne[arrOneIndex];
        arrOneIndex++;
        mergedArrIndex++;
        steps++; // +1 to assign variable
        steps++; // +1 for variable incrementation
        steps++; // +1 for variable incrementation
    }

    while (arrTwoIndex < arrTwoSize)
    {
        steps += 1; // +1 for while loop
        arr[mergedArrIndex] = arrTwo[arrTwoIndex];
        arrTwoIndex++;
        mergedArrIndex++;
        steps++; // +1 to assign variable
        steps++; // +1 for variable incrementation
        steps++; // +1 for variable incrementation
    }
    delete[] arrOne;
    steps++; // +1 for deleting array
    delete[] arrTwo;
    steps++; // +1 for deleting array
}

void insertionSortMS(int arr[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        steps += 3; // +3 for loop
        int key = arr[i];
        int j = i - 1;
        steps++; // +1 to assign variable
        steps++; // +1 to assign variable
        while (j >= start && arr[j] > key)
        {
            steps += 2; // +2 for while loop
            steps += 2; // +2 for do-while loop
            arr[j + 1] = arr[j];
            j--;
            steps++; // +1 to assign variable
            steps++; // +1 to assign variable
        }
        steps += 1; // +1 for do-while loop

        arr[j + 1] = key;
        steps++; // +1 to assign variable
    }
    steps++; // +1 for end of loop
}

void mergeInsertionSortS(int arr[], int start, int stop, double k)
{
    if (stop - start <= k)
    {
        steps++; // +1 for function call
        insertionSortMS(arr, start, stop);
    }
    else
    {
        int mid = start + (stop - start) / 2;
        steps += 2; // +2 for variable assignment
        steps++;    // +1 for function call
        mergeInsertionSortS(arr, start, mid, k);
        steps++; // +1 for function call
        mergeInsertionSortS(arr, mid + 1, stop, k);
        steps++; // +1 for function call
        mergeS(arr, start, mid, stop);
        steps++; // +1 for function call
    }
    steps++; // +1 for if
}
int main()

{

    cout << "====================CPU Avgs=================\n\n\n";
    for (int i = 0; i < 1; i++) // for all datasetsizes
    {

        Size = dataSetSizes[i];
        cout << "\n\n\nCurrent Size: " << Size << "\n\n";
        SizePercent = 0;

        cout << setw(15) << left << "Portion of N" << setw(15) << "Portion Value" << setw(15) << "CPU AVG" << right << endl;
        for (int i = 1; i <= 50; i++) // for 1 - 50 percent of dataset size
        {
            SizePercent += 0.01;
            CPUTotal = 0;

            for (int j = 1; j <= 50; j++) // evaluate avg of each percent for that datasetsize
            {
                int *tempArr = newPermutArray(Size);

                func_evalMergeIns(tempArr, 0, Size - 1, Size * SizePercent, mergeInsertionSort);

                delete[] tempArr;
                BaseArr.clear();
            }
            cout << setw(15) << left << SizePercent << setw(15) << Size * SizePercent << setw(15) << CPUTotal / 50 << right << endl;
        }
    }

    // cout << "====================STEP Avgs=================\n\n\n";
    // for (int i = 0; i < 8; i++) // for all datasetsizes
    // {

    //     Size = dataSetSizes[i];
    //     cout << "\n\n\nCurrent Size: " << Size << "\n\n";
    //     SizePercent = 0;

    //     cout << setw(15) << left << "Portion of N" << setw(15) << "Portion Value" << setw(15) << "STEP AVG" << right << endl;
    //     for (int i = 1; i <= 50; i++) // for 1 - 50 percent of dataset size
    //     {
    //         SizePercent += 0.01;
    //         StepTotal = 0;

    //         for (int j = 1; j <= 50; j++) // evaluate avg of each percent for that datasetsize
    //         {
    //             int *tempArr = newPermutArray(Size);

    //             func_evalMergeInsSteps(tempArr, 0, Size - 1, Size * SizePercent, mergeInsertionSortS);

    //             delete[] tempArr;
    //             BaseArr.clear();
    //         }
    //         cout << setw(15) << left << SizePercent << setw(15) << Size * SizePercent << setw(15) << StepTotal / 50 << right << endl;
    //     }
    // }


    return 0;
}