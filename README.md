# Sorting-Algorithm-Analyzer
Sameer Jain - Project leader 

• Organized meetings and coordinated project to completion, Final grade: 100%.

• Assembled 61 C++ algorithm variations to sort data sets with a max size of 50,000.

• Compared CPU run time, read step counts, and analyzed trade-offs to find the most efficient algorithms.

Presentation:
https://docs.google.com/presentation/d/1dUqu7pfOn9Nu4loHAPI2E4TWEKYWjL3cYrdwhP6J-YY/edit?usp=sharing

CPU Data:
https://docs.google.com/spreadsheets/d/1vWTPmyX2VwndZPcjbfmm-3cxkEMoKYH00fI44v1fscg/edit?usp=sharing

Video Demonstration:
https://youtu.be/8OGSf1p1Aqs

To Compile:
step 1: Copy code for desired part (1 or 2) and paste into main
step 2: g++ main.cpp -o main
step 3: ./main

Input this into int main(): 

```
  // TASK 1 OUTPUT
  cout << "=========TASK 1==============\n";

  for (int i = 0; i <= 7; i++)
  {
    // Initialization and printArray
    Size = dataSetSizes[i];
    cout << "Current Size:" << Size << endl;
    int *tempArr = newPermutArray(Size);
    cout << "Original Array:\n";
    printArray(tempArr, Size);
    // BUBBLE SORT
    cout << "=======BUBBLE SORT:============\n";
    cout << "Bubble Sort A = ";
    func_eval(tempArr, Size, bubbleSortA);
    bubbleSortAS(tempArr, Size);
    cout << "Bubble Sort B = ";
    func_eval(tempArr, Size, bubbleSortB);
    bubbleSortBS(tempArr, Size);
    // INSERTION SORT
    cout << "=======INSERTION SORT:============\n";
    cout << "Insertion Sort A = ";
    func_eval(tempArr, Size, insertionSortA);
    insertionSortAS(tempArr, Size);
    cout << "Insertion Sort B = ";
    func_eval(tempArr, Size, insertionSortB);
    insertionSortBS(tempArr, Size);
    // SELECTION SORT
    cout << "=======SELECTION SORT:============\n";
    cout << "Selection Sort A = ";
    func_eval(tempArr, Size, selectionSortA);
    selectionSortAS(tempArr, Size);
    cout << "Selection Sort B = ";
    func_eval(tempArr, Size, selectionSortB);
    selectionSortBS(tempArr, Size);
    // HEAP SORT
    cout << "=======HEAP SORT:================\n";
    cout << "Heap Sort A = ";
    func_eval(tempArr, Size, heapSortA);
    heapSortAS(tempArr, Size);
    cout << "Heap Sort B = ";
    func_eval(tempArr, Size, heapSortB);
    heapSortBS(tempArr, Size);
    // MERGESORT
    cout << "=======MERGESORT:================\n";
    cout << "Merge Sort A = ";
    func_eval2(tempArr, 0, Size - 1, mergeSortA);
    func_evalStepsMQ(tempArr, 0, Size - 1, mergeSortAS);
    cout << "Merge Sort B = ";
    func_eval2(tempArr, 0, Size - 1, mergeSortB);
    func_evalStepsMQ(tempArr, 0, Size - 1, mergeSortBS);
    // Merge Insertion
    cout << "Merge-Insertion Sort A = ";
    func_evalMergeIns(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortA);
    func_evalMergeInsSteps(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortAS);
    cout << "Merge-Insertion Sort B = ";
    func_evalMergeIns(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortB);
    func_evalMergeInsSteps(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortBS);
    // QUICKSORT
    cout << "=======QUICKSORT:================\n";
    // Hoarse
    cout << "Quick Sort A (HOARSE)= ";
    func_eval2(tempArr, 0, Size - 1, quickSortHA);
    func_evalStepsMQ(tempArr, 0, Size - 1, quickSortHAS);
    cout << "Quick Sort B (HOARSE)= ";
    func_eval2(tempArr, 0, Size - 1, quickSortHB);
    func_evalStepsMQ(tempArr, 0, Size - 1, quickSortHBS);
    //  Lamuto
    cout << "Quick Sort A (LAMUTO)= ";
    func_eval2(tempArr, 0, Size - 1, QuicksortLA);
    func_evalStepsMQ(tempArr, 0, Size - 1, QuicksortLAS);
    cout << "Quick Sort B (LAMUTO)= ";
    func_eval2(tempArr, 0, Size - 1, QuicksortLB);
    func_evalStepsMQ(tempArr, 0, Size - 1, QuicksortLBS);

    delete[] tempArr;
    BaseArr.clear();
  } ```

// PART 2 

  cout << "=========TASK 2==============\n";
  for (int i = 0; i < 8; i++)
  {
    Size = dataSetSizes[i];

    cout << "\n\n\nCurrent Size: " << Size << endl
         << endl;

    for (int j = 1; j <= 50; j++)
    {
      int *tempArr = newRandArray(Size);
      // BUBBLE SORT
      cout << "=======BUBBLE SORT:============\n";
      cout << "Time\n";
      func_eval(tempArr, Size, bubbleSortA);
      cout << "Steps\n";
      bubbleSortAS(tempArr, Size);
      // INSERTION SORT
      cout << "=======INSERTION SORT:============\n";
      cout << "Time\n";
      func_eval(tempArr, Size, insertionSortA);
      cout << "Steps\n";
      insertionSortAS(tempArr, Size);

      // SELECTION SORT
      cout << "=======SELECTION SORT:============\n";
      cout << "Time\n";
      func_eval(tempArr, Size, selectionSortA);
      cout << "Steps\n";
      selectionSortAS(tempArr, Size);

      // HEAP SORT
      cout << "=======HEAP SORT:============\n";
      cout << "Time\n";
      func_eval(tempArr, Size, heapSortA);
      cout << "Steps\n";
      heapSortAS(tempArr, Size);

      // MERGE SORT
      cout << "=======MERGE SORT:============\n";
      cout << "Time\n";
      func_eval2(tempArr, 0, Size - 1, mergeSortA);
      cout << "Steps\n";
      func_evalStepsMQ(tempArr, 0, Size - 1, mergeSortAS);

      // MERGE-Insertion SORT
      cout << "=======MERGE INSERTION SORT:============\n";
      cout << "Time\n";
      func_evalMergeIns(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortA);
      cout << "Steps\n";
      func_evalMergeInsSteps(tempArr, 0, Size - 1, Size * 0.01, mergeInsertionSortAS);

      // QUICKSORT SORT HOARSE
      cout << "=======QUICK SORT HOARSE:============\n";
      cout << "Time\n";
      func_eval2(tempArr, 0, Size - 1, quickSortHA);
      cout << "Steps\n";
      func_evalStepsMQ(tempArr, 0, Size - 1, quickSortHAS);

      // QUICKSORT SORT LAMUTO
      cout << "=======QUICK SORT LAMUTO:============\n";
      cout << "Time\n";
      func_eval2(tempArr, 0, Size - 1, QuicksortLA);
      cout << "Steps\n";
      func_evalStepsMQ(tempArr, 0, Size - 1, QuicksortLAS);

      delete[] tempArr;
      BaseArr.clear();
    }
  }
