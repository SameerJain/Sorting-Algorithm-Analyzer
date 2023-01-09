// Insertion Sort
// =================================================================
void insertionSortA(int arr[], int n) {
  int key, i, j;          // key is needed for insertion sort
  for (i = 1; i < n; i++) // i is the index of the current key
  {
    key = arr[i]; // key is from arr[1] to arr[n-1]
    j = i - 1;    // j is for element before the current key

    while (j >= 0 && arr[j] > key) // this loop sorts elements BEFORE key
    {
      arr[j + 1] = arr[j]; // j + 1 shifts the element to the place after
      j = j - 1; // decriment to compare the element we are sorting with the
                 // previous elements
    }
    arr[j + 1] = key; // makes the key the location that was just emptied via
                      // the shift on line 36 // this is the swapping of a key
                      // and element that is larger then the key
  }
}

void insertionSortB(int arr[], int n) {
  int key, i, j;               // key is needed for insertion sort
  for (i = n - 2; i >= 0; i--) // i is the index of the current key
  {
    key = arr[i]; // key is from arr[1] to arr[n-1]
    j = i + 1;    // j is for element before the current key

    while (j < n && arr[j] <= key) // this loop sorts elements BEFORE key
    {
      arr[j - 1] = arr[j]; // j + 1 shifts the element to the place after
      j = j + 1; // incriment to compare the element we are sorting with the
                 // previous elements
    }
    arr[j - 1] = key; // makes the key the location that was just emptied via
                      // the shift on line 36 // this is the swapping of a key
                      // and element that is larger then the key
  }
}

// Versions with Steps===================================================
void insertionSortAS(int arr[], int n) {
  steps = 0;
  steps++; // initialize step

  int key, i, j;
  steps++; // +1 to intialize variable
  steps++; // +1 to intialize variable
  steps++; // +1 to intialize variable
  for (i = 1; i < n; i++)
  {
    steps += 3; // +3 for loop
    key = arr[i];
    steps++; // +1 to assign variable
    j = i - 1;
    steps++; // +1 to assign variable

    while (j >= 0 && arr[j] > key) {
      steps += 2; // +3 for loop
      arr[j + 1] = arr[j];
      steps++; // +1 to assign variable
      j = j - 1;
      steps++; // +1 to assign variable
    }
    steps++; // +1 for end of loop
    arr[j + 1] = key;
    steps++; // +1 to assign variable
  }
  steps += 1; // +1 for loop
  cout << "insertionSortAS steps:" << steps << endl;
}

void insertionSortBS(int arr[], int n) {
  steps = 0;
  steps++; // initialize step
  int key, i, j;
  steps++; // +1 to assign variable
  steps++; // +1 to assign variable
  steps++; // +1 to assign variable
  for (i = n - 2; i >= 0; i--) {

    steps += 3; // +3 for loop

    key = arr[i];
    steps++; // +1 to assign variable
    j = i + 1;
    steps++; // +1 to assign variable

    while (j < n && arr[j] <= key) {
      steps += 2; // +2 for while loop
      arr[j - 1] = arr[j];
      steps++; // +1 to assign variable
      j = j + 1;
      steps++; // +1 to assign variable
    }
    steps++; // +1 for end of loop
    arr[j - 1] = key;
    steps++; // +1 to assign variable
  }
  cout << "insertionSortBS steps:" << steps << endl;
}