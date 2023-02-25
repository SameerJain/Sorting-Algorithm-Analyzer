// Selection Sort
// =================================================================
void selectionSortA(int arr[], int n)
{ // selection sort algorithm
  for (int i = 0; i < n; i++)
  {
    int smallest = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[smallest])
        smallest = j;
    }
    if (smallest != i)
      swap(arr[i], arr[smallest]);
  }
}

void selectionSortB(int arr[], int n)
{ // selection sort algorithm
  for (int i = 0; i < n; i++)
  {
    int largest = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] > arr[largest])
        largest = j;
    }
    if (largest != i)
      swap(arr[i], arr[largest]);
  }
}

// Versions with Steps===================================================

void selectionSortAS(int arr[], int n)
{ // selection sort algorithm
  steps = 0;
  steps++; // initial i to 0
  for (int i = 0; i < n; i++)
  {
    steps += 2; // for the for loop
    int smallest = i;
    steps++; // for int smallest
    steps++; // initial i to 0
    for (int j = i; j < n; j++)
    {
      steps += 2; // for loop
      steps++;    // for if statement
      if (arr[j] < arr[smallest])
      {
        smallest = j;
        steps++; // assignment
      }
    }
    steps++; // for if statement
    if (smallest != i)
    {
      swap(arr[i], arr[smallest]);
      steps += 3; // swap func
    }
  }
  cout << "selectionSortAS steps:" << steps << endl;
}

void selectionSortBS(int arr[], int n)
{ // selection sort algorithm
  steps = 0;
  steps++; // initial i to 0
  for (int i = 0; i < n; i++)
  {
    steps += 2; // for the for loop
    int largest = i;
    steps++; // for int smallest
    steps++; // initial i to 0
    for (int j = i; j < n; j++)
    {
      steps += 2; // for loop
      steps++;    // for if statement
      if (arr[j] > arr[largest])
      {
        largest = j;
        steps++; // assignment
      }
    }
    steps++; // for if statement
    if (largest != i)
    {
      swap(arr[i], arr[largest]);
      steps += 3; // swap func
    }
  }
  cout << "selectionSortBS steps:" << steps << endl;
}
