
// QuickSort ===================================================================

int partitionHA(int arr[], int start, int end)
{ // Hoarse
  int pivot = arr[start];
  int i = start, j = end;
  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] < pivot);
    do
    {
      j--;
    } while (arr[j] > pivot);
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[start], arr[j]);
  return j;
}
void quickSortHA(int arr[], int start, int end)
{
  if (start < end)
  {
    int pivot = partitionHA(arr, start, end);
    quickSortHA(arr, start, pivot);
    quickSortHA(arr, pivot + 1, end);
  }
}
int partitionHB(int arr[], int start, int end)
{
  int pivot = arr[start];
  int i = start, j = end;
  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] > pivot);
    do
    {
      j--;
    } while (arr[j] < pivot);
    if (i < j)
      swap(arr[i], arr[j]);
  }
  swap(arr[start], arr[j]);
  return j;
}
void quickSortHB(int arr[], int start, int end)
{
  if (start < end)
  {
    int pivot = partitionHB(arr, start, end);
    quickSortHB(arr, start, pivot);
    quickSortHB(arr, pivot + 1, end);
  }
}

int partitionLA(int arr[], int start, int end) // Lamuto
{

  int pivot = arr[end]; // pivot position is at end
  int j = start - 1;    // index of smalllest element in array - 1 as j starts next to it

  for (int i = start; i <= end - 1; i++) // go thru array
  {
    if (arr[i] <= pivot) // if the element if smaller than swap
    {
      j++; // move i over first so you dont constantly swap in the same position
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[j + 1], arr[end]); // move the pivot into the array from the space next to i
  return (j + 1);             // place of pivot in the array
}

void QuicksortLA(int arr[], int start, int end)
{
  if (start < end) // as long as the quicksort ran thru all elements in the array
  {
    int partIndex = partitionLA(arr, start, end); // sort array and get partition index
    QuicksortLA(arr, start, partIndex - 1);       // redo recursevely for each subarray
    QuicksortLA(arr, partIndex + 1, end);
  }
}

int partitionLB(int arr[], int start, int end)
{

  int pivot = arr[end]; // pivot position is at end
  int j = start - 1;    // index of smalllest element in array - 1 as j starts next to it

  for (int i = start; i <= end - 1; i++) // go thru array
  {
    if (arr[i] >= pivot) // if the element if greater than swap
    {
      j++; // move i over first so you dont constantly swap in the same position
      swap(arr[j], arr[i]);
    }
  }
  swap(arr[j + 1], arr[end]); // move the pivot into the array from the space next to i
  return (j + 1);             // place of pivot in the array
}

void QuicksortLB(int arr[], int start, int end)
{
  if (start < end) // as long as the quicksort ran thru all elements in the array
  {
    int partIndex = partitionLB(arr, start, end); // sort array and get partition index
    QuicksortLB(arr, start, partIndex - 1);       // redo recursevely for each subarray
    QuicksortLB(arr, partIndex + 1, end);
  }
}

// Versions with Steps===================================================

// QuickSort ===================================================================

int partitionHAS(int arr[], int start, int end)
{ // Hoarse
  int pivot = arr[start];
  steps++; // +1 to assign variable

  int i = start, j = end;
  steps += 2; // +2 for variable assignment
  while (i < j)
  {
    steps += 1; // +1 for while loop
    do
    {
      steps += 2; // +2 for do-while loop
      i++;
      steps++; // +1 for variable incrementation
    } while (arr[i] < pivot);
    do
    {
      steps += 2; // +2 for do-while loop
      j--;
      steps++; // +1 for variable decrementation
    } while (arr[j] > pivot);
    if (i < j)
      swap(arr[i], arr[j]);
    steps += 3; // +3 for swap
    steps++;    // +1 for if
  }
  swap(arr[start], arr[j]);
  steps += 3; // +3 for swap
  return j;
}
void quickSortHAS(int arr[], int start, int end)
{
  steps++; // initialize step
  if (start < end)
  {
    int pivot = partitionHAS(arr, start, end);
    steps++; // +1 to assign variable
    steps++; // +1 for function call
    quickSortHAS(arr, start, pivot);
    steps++; // +1 for function call
    quickSortHAS(arr, pivot + 1, end);
    steps++; // +1 for function call
  }
  steps++; // +1 for if
}
int partitionHBS(int arr[], int start, int end)
{
  int pivot = arr[start];
  steps++; // +1 to intialize variable
  int i = start, j = end;
  steps++; // +1 to intialize variable
  steps++; // +1 to intialize variable
  while (i < j)
  {
    steps += 1; // +1 for while loop

    do
    {
      steps += 2; // +2 for do-while loop
      i++;
      steps++; // +1 for variable incrementation
    } while (arr[i] > pivot);
    do
    {
      j--;
      steps++; // +1 for variable decrementation
    } while (arr[j] < pivot);
    if (i < j)
    {
      swap(arr[i], arr[j]);
      steps += 3;
    }        // +3 for swap
    steps++; // +1 for if
  }

  swap(arr[start], arr[j]);
  steps += 3; // +3 for swap
  return j;
}
void quickSortHBS(int arr[], int start, int end)
{
  steps++; // initialize step
  if (start < end)
  {
    int pivot = partitionHBS(arr, start, end);
    steps++; // +1 to assign variable
    steps++; // +1 for function call
    quickSortHBS(arr, start, pivot);
    steps++; // +1 for function call
    quickSortHBS(arr, pivot + 1, end);
    steps++; // +1 for function call
  }
  steps++; // +1 for if
}

int partitionLAS(int arr[], int start, int end) // Lamuto
{

  int pivot = arr[end];
  steps++; // +1 to assign variable
  int j = start - 1;
  steps++; // +1 to assign variable
  for (int i = start; i <= end - 1; i++)
  {
    steps += 3; // +3 for loop
    if (arr[i] <= pivot)
    {
      j++;
      steps++; // +1 for variable incrementation
      swap(arr[j], arr[i]);
      steps += 3; // +3 for swap
    }
    steps++; // +1 for if
  }
  swap(arr[j + 1], arr[end]);
  steps += 3; // +3 for swap
  return (j + 1);
  steps++; // +1 for return
}

void QuicksortLAS(int arr[], int start, int end)
{
  steps++; // initialize step
  if (start < end)
  {
    int partIndex = partitionLAS(arr, start, end);
    steps++; // +1 to assign variable
    steps++; // +1 for function call
    QuicksortLAS(arr, start, partIndex - 1);
    steps++; // +1 for function call
    QuicksortLAS(arr, partIndex + 1, end);
    steps++; // +1 for function call
  }
  steps++; // +1 for if
}

int partitionLBS(int arr[], int start, int end)
{

  int pivot = arr[end];
  steps++; // +1 to assign variable
  int j = start - 1;
  steps++; // +1 to intialize variable
  for (int i = start; i <= end - 1; i++)
  {
    steps += 3; // +3 for loop
    if (arr[i] >= pivot)
    {
      j++;
      steps++; // +1 for variable incrementation
      swap(arr[j], arr[i]);
      steps += 3; // +3 for swap
    }
    steps++; // +1 for if
  }
  swap(arr[j + 1], arr[end]);
  steps += 3; // +3 for swap
  return (j + 1);
  steps++; // +1 for function call
}

void QuicksortLBS(int arr[], int start, int end)
{
  if (start < end)
  {
    int partIndex = partitionLB(arr, start, end);
    steps++; // +1 for function call
    steps++; // +1 to assign variable
    QuicksortLBS(arr, start, partIndex - 1);
    steps++; // +1 for function call
    QuicksortLBS(arr, partIndex + 1, end);
    steps++; // +1 for function call
  }
  steps++; // +1 for if
}