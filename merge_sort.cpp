void mergeA(int arr[], int start, int mid, int end)
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

void mergeB(int arr[], int start, int mid, int end)
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
        if (arrOne[arrOneIndex] >=
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

void mergeSortA(int arr[], int start, int end)
{ // must do size - 1
    if (start >=
        end) // base case, if start is >= end we have proccessed all the indexes
    {

        return;
    }
    int mid = start + (end - start) / 2; // gives midpoint in subarr

    mergeSortA(arr, start, mid);
    mergeSortA(arr, mid + 1,
               end); // +1 so we dont operate on same index in both subarrs
    mergeA(arr, start, mid, end);
}

void mergeSortB(int arr[], int start, int end)
{ // must do size - 1
    if (start >=
        end) // base case, if start is >= end we have proccessed all the indexes
    {
        return;
    }
    int mid = start + (end - start) / 2; // gives midpoint in subarr

    mergeSortB(arr, start, mid);
    mergeSortB(arr, mid + 1,
               end); // +1 so we dont operate on same index in both subarrs
    mergeB(arr, start, mid, end);
}

void insertionSortAIns(int arr[], int start, int end)
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

void insertionSortBIns(int arr[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeInsertionSortA(int arr[], int start, int stop, int k) // k is switch from merge to insertion 5% of the total array size
{
    if (stop - start <= k)
    {
        insertionSortAIns(arr, start, stop);
    }

    else
    {
        int mid = start + (stop - start) / 2;       // midpoint to partiton is half of array length
        mergeInsertionSortA(arr, start, mid, k);    // partition 1 half of current full array
        mergeInsertionSortA(arr, mid + 1, stop, k); // partition 2 half of current full array
        mergeA(arr, start, mid, stop);
    } // merge both back
}

void mergeInsertionSortB(int arr[], int start, int stop, int k)
{
    if (stop - start <= k)
    {
        insertionSortBIns(arr, start, stop);
    }

    else
    {
        int mid = start + (stop - start) / 2;       // midpoint to partiton is half of array length
        mergeInsertionSortB(arr, start, mid, k);    // partition 1 half of current full array
        mergeInsertionSortB(arr, mid + 1, stop, k); // partition 2 half of current full array
        mergeB(arr, start, mid, stop);
    }
}

// Versions with Steps===================================================
void mergeAS(int arr[], int start, int mid, int end)
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

void mergeBS(int arr[], int start, int mid, int end)
{
    int arrOneSize = mid - start + 1;
    steps += 3; // +3 for variable assignment
    int arrTwoSize = end - mid;
    steps++; // +1 to assign variable
    int *arrOne = new int[arrOneSize];
    steps++; // +1 to assign variable
    int *arrTwo = new int[arrTwoSize];

    for (int i = 0; i < arrOneSize; i++)
    {
        steps += 3; // +3 for loop
        arrOne[i] = arr[start + i];
    }

    for (int i = 0; i < arrTwoSize; i++)
    {
        arrTwo[i] = arr[mid + 1 + i];
    }
    steps++; // +1 to assign variable

    int arrOneIndex = 0;
    int arrTwoIndex = 0;
    int mergedArrIndex = start;
    steps++; // +1 to assign variable
    steps++; // +1 to assign variable
    steps++; // +1 to assign variable
    while (arrOneIndex < arrOneSize &&
           arrTwoIndex < arrTwoSize)
    {
        steps += 2; // +2 for while loop
        if (arrOne[arrOneIndex] >=
            arrTwo[arrTwoIndex])
        {
            arr[mergedArrIndex] = arrOne[arrOneIndex];
            arrOneIndex++;
        }
        else
        {
            arr[mergedArrIndex] =
                arrTwo[arrTwoIndex];
            arrTwoIndex++;
            steps++; // +1 for variable incrementation
        }

        steps++; // +1 for if

        mergedArrIndex++;
        steps += 1; // +1 for end of while loop
    }
    steps += 1; // +1 for end of while loop

    while (arrOneIndex <
           arrOneSize)
    {
        arr[mergedArrIndex] = arrOne[arrOneIndex];
        arrOneIndex++;
        mergedArrIndex++;
    }
    while (arrTwoIndex <
           arrTwoSize)
    {
        steps += 1; // +1 for while loop
        arr[mergedArrIndex] = arrTwo[arrTwoIndex];
        arrTwoIndex++;
        mergedArrIndex++;
        steps++; // +1 to assign variable
        steps++; // +1 for variable incrementation
        steps++; // +1 for variable incrementation
    }
    steps += 1; // +1 for end of while loop
    delete[] arrOne;
    delete[] arrTwo;
    steps++; // +1 for deleting array
    steps++; // +1 for deleting array
}

void mergeSortAS(int arr[], int start, int end)
{
    steps++; // initialize step
    if (start >= end)
    {
        steps++; // +1 for if
        return;
    }
    steps++; // +1 for if

    int mid = start + (end - start) / 2;
    steps += 3; // +3 for variable assignment
    mergeSortAS(arr, start, mid);
    steps++; // +1 for function call
    mergeSortAS(arr, mid + 1, end);
    steps++; // +1 for function call
    mergeAS(arr, start, mid, end);
    steps++; // +1 for function call
}

void mergeSortBS(int arr[], int start, int end)
{
    steps++; // initialize step
    if (start >=
        end)
    {
        steps++; // +1 for if
        return;
    }
    steps++; // +1 for if
    int mid = start + (end - start) / 2;
    steps += 3; // +3 for variable assignment

    mergeSortBS(arr, start, mid);
    steps++; // +1 for function call
    mergeSortBS(arr, mid + 1, end);
    steps++; // +1 for function call
    mergeBS(arr, start, mid, end);
    steps++; // +1 for function call
}

void insertionSortAInsS(int arr[], int start, int end)
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

void insertionSortBInsS(int arr[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        steps += 3; // +3 for loop
        int key = arr[i];
        int j = i - 1;
        steps++; // +1 to assign variable
        steps++; // +1 to assign variable
        while (j >= start && arr[j] < key)
        {
            steps += 2; // +2 for while loop
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

void mergeInsertionSortAS(int arr[], int start, int stop, int k)
{
    if (stop - start <= k)
    {
        steps++; // +1 for function call
        insertionSortAInsS(arr, start, stop);
    }
    else
    {
        int mid = start + (stop - start) / 2;
        steps += 2; // +2 for variable assignment
        steps++;    // +1 for function call
        mergeInsertionSortAS(arr, start, mid, k);
        steps++; // +1 for function call
        mergeInsertionSortAS(arr, mid + 1, stop, k);
        steps++; // +1 for function call
        mergeAS(arr, start, mid, stop);
        steps++; // +1 for function call
    }
    steps++; // +1 for if
}

void mergeInsertionSortBS(int arr[], int start, int stop, int k)
{
    if (stop - start <= k)
    {
        insertionSortBInsS(arr, start, stop);
    }

    else
    {
        int mid = start + (stop - start) / 2;
        steps += 2; // +2 for variable assignment
        steps++;    // +1 for function call

        mergeInsertionSortBS(arr, start, mid, k);
        steps++; // +1 for function call
        mergeInsertionSortBS(arr, mid + 1, stop, k);
        steps++; // +1 for function call
        mergeBS(arr, start, mid, stop);
    }
    steps++; // +1 for function call
}
