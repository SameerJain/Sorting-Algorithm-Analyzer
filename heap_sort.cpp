// Heap Sort =================================================================
void max_heap(int arr[], int n, int i)
{

  // make largest element the root of tree
  int largest = i;

  // left child index is twice the parent's
  int l = 2 * i;

  // right child index is the parent's + 1
  int r = 2 * i + 1;

  //  if left child exists in the array and is larger than root
  if (l < n && arr[l] > arr[largest])
  {
    largest = l;
  }
  // if right child exists in the array and is larger than root
  if (r < n && arr[r] > arr[largest])
  {
    largest = r;
  }

  // if current largest element is not the root
  if (largest != i)
  {
    swap(arr[i], arr[largest]);

    // then keep recursively heapifying until it is the largest
    max_heap(arr, n, largest);
  }
}
void min_heap(int arr[], int n, int i)
{

  // make smallest element the root of tree
  int smallest = i;

  // left child index is twice the parent's
  int l = 2 * i;

  // right child index is the parent's
  int r = 2 * i + 1;

  // if left child exists in the array and is smaller than root
  if (l < n && arr[l] < arr[smallest])
  {
    smallest = l;
  }
  // if right child exists in the array and is smaller than root
  if (r < n && arr[r] < arr[smallest])
  {
    smallest = r;
  }

  // if current smallest element is not the root
  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);

    // then keep recursively heapifying until it is the smallest

    min_heap(arr, n, smallest);
  }
}

void heapSortA(int arr[], int n)
{
  // Build initial heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    max_heap(arr, n, i);
  }

  // until the loop goes thru all elements in the array
  for (int i = n - 1; i >= 0; i--)
  {
    // move the max element to the back as its sorted
    swap(arr[0], arr[i]);

    // then heapify the rest of the array
    max_heap(arr, i, 0);
  }
}

void heapSortB(int arr[], int n)
{

  // Build initial heap
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    min_heap(arr, n, i);
  }

  // until the loop goes thru all elements in the array
  for (int i = n - 1; i >= 0; i--)
  {

    // move the min element to the back as its sorted
    swap(arr[0], arr[i]);

    // then heapify the rest of the array
    min_heap(arr, i, 0);
  }
}

// Versions with Steps===================================================
void max_heapS(int arr[], int n, int i)
{
  steps++; // +1 to intialize variable
  int largest = i;
  steps++; // +1 to intialize variable
  int l = 2 * i;
  steps += 2; // +2 for variable assignment
  int r = 2 * i + 1;
  steps += 3; // +3 for variable assignment
  if (l < n && r < n && arr[l] > arr[largest] && arr[r] > arr[largest])
  {
    if (arr[l] >= arr[r])
    {
      largest = l;
    }
    else
    {
      largest = r;
    }
    steps += 4; // +4 for if
  }
  else
  {
    if (l < n && arr[l] > arr[largest])
    {
      largest = l;
      steps++; // +1 to intialize variable
    }
    steps += 2; // +2 for if statement
    if (r < n && arr[r] > arr[largest])
    {
      largest = r;
      steps++; // +1 to intialize variable
    }
  }
  steps += 2; // +2 for if statement
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    steps += 3; // +3 for swap

    max_heapS(arr, n, largest);
    steps++; // +1 for function call
  }
  steps++; // +1 for if
}

void heapSortAS(int arr[], int n)
{
  steps = 0;
  steps++; // initialize step
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    steps += 3; // +3 for loop
    max_heapS(arr, n, i);
    steps++; // +1 for function call
  }
  steps++; // +1 for end of loop
  for (int i = n - 1; i >= 0; i--)
  {
    steps += 3; // +3 for loop
    swap(arr[0], arr[i]);
    steps += 3; // +3 for swap
    max_heapS(arr, i, 0);
    steps++; // +1 for function call
  }
  steps++; // +1 for end of loop

  cout << "heapSortAS steps:" << steps << endl;
}

void min_heapS(int arr[], int n, int i)
{
  steps++; // +1 to intialize variable
  int smallest = i;
  steps++; // +1 to intialize variable
  int l = 2 * i;
  steps += 2; // +2 for variable assignment
  int r = 2 * i + 1;
  steps += 3; // +3 for variable assignment
  if (l > n && r > n && arr[l] < arr[smallest] && arr[r] > arr[smallest])
  {
    if (arr[l] <= arr[r])
    {
      smallest = l;
      steps++; // +1 to assign variable
    }
    else
    {
      smallest = r;
      steps++; // +1 to assign variable
    }
    steps++; // +1 for if
  }

  else
  {
    if (l < n && arr[l] < arr[smallest])
    {
      smallest = l;
      steps++; // +1 to assign variable
    }
    steps++; // +1 for if
    if (r < n && arr[r] < arr[smallest])
    {
      smallest = r;
      steps++; // +1 to intialize variable
    }
    steps += 2; // +2 for if
  }
  steps += 4; // +4 for if

  if (smallest != i)
  {
    swap(arr[i], arr[smallest]);
    steps += 3; // +3 for swap
    steps++;    // +1 for function call
    min_heap(arr, n, smallest);
  }

  steps++; // +1 for if
}
void heapSortBS(int arr[], int n)
{

  steps = 0;
  steps++; // initialize step
  for (int i = n / 2 - 1; i >= 0; i--)
  {
    steps += 3; // +3 for loop
    min_heapS(arr, n, i);
    steps++; // +1 for function call
  }
  steps++; // +1 for end of loop
  for (int i = n - 1; i >= 0; i--)
  {
    steps += 3; // +3 for loop
    swap(arr[0], arr[i]);
    steps += 3; // +3 for swap
    steps++;    // +1 for function call
    min_heapS(arr, i, 0);
  }

  steps++; // +1 for end of loop

  cout << "heapSortBS steps:" << steps << endl;
}