// Bubble Sort
// ===================================================================
void bubbleSortA(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) { // for the entire array
    for (int j = 0; j < n - 1 - i;
         j++) {                   // until the last element that isnt ran thru
      if (arr[j] > arr[j + 1]) {  // if the the current element is greater than
                                  // the one after it
        swap(arr[j], arr[j + 1]); // swap the element with the one after it
      }
    }
  }
}

void bubbleSortB(int arr[], int n) {

  for (int i = 0; i < n - 1; i++) { // for the entire array
    for (int j = 0; j < n - 1 - i;
         j++) {                   // until the last element that isnt ran thru
      if (arr[j] < arr[j + 1]) {  // if the the current element is less than the
                                  // one after it
        swap(arr[j], arr[j + 1]); // swap the element with the one after it
      }
    }
  }
}

// Versions with Steps===================================================

void bubbleSortAS(int arr[], int n) {
  steps = 0;
  steps++; // initialize step
  for (int i = 0; i < n - 1; i++) {
    steps += 3; // +3 for loop
    for (int j = 0; j < n - 1 - i; j++) {
      steps += 3; // +3 for loop
      if (arr[j] > arr[j + 1]) {

        swap(arr[j], arr[j + 1]);
        steps += 3; // +3 for swap
      }
      steps++; // +1 for if
    }
    steps++; // +1 for end of loop
  }
  steps++; // +1 for end of loop

  cout << "bubbleSortAS steps:" << steps << endl;
}

void bubbleSortBS(int arr[], int n) {

  steps = 0;
  steps++; // initialize step
  for (int i = 0; i < n - 1; i++) {
    steps += 3; // +3 for loop
    for (int j = 0; j < n - 1 - i; j++) {
      steps += 3; // +3 for loop
      if (arr[j] < arr[j + 1]) {

        swap(arr[j], arr[j + 1]);
        steps += 3; // +3 for swap
      }
      steps++; // +1 for if
    }
    steps++; // +1 for end of loop
  }
  steps++; // +1 for end of loop
  cout << "bubbleSortBS steps:" << steps << endl;
}
