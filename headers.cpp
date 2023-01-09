// FUNCTION NAMING GUIDE
/*
A = Smallest to largest
B = Largest to smallest
S = With step counter
Quicksort H = Hoarse / L = Lamuto Partition
*/
// ============BUBBLE SORT============

// without steps
void bubbleSortA(long int arr[], int n);
void bubbleSortB(long int arr[], int n);

// with steps
void bubbleSortAS(int arr[], int n);
void bubbleSortBS(int arr[], int n);

// =============HEAP SORT==============

// without steps
void max_heap(int arr[], int n, int i);
void min_heap(int arr[], int n, int i);
void heapSortA(int arr[], int n);
void heapSortB(int arr[], int n);

// with steps
void max_heapS(int arr[], int n, int i);
void min_heapS(int arr[], int n, int i);
void heapSortAS(int arr[], int n);
void heapSortBS(int arr[], int n);

// ============INSERTION SORT=============

// without steps
void insertionSortA(int arr[], int n);
void insertionSortB(int arr[], int n);
// with steps
void insertionSortAS(int arr[], int n);
void insertionSortBS(int arr[], int n);

// =============MERGE SORT=================

// without steps
void mergeA(int arr[], int start, int mid, int end);
void mergeB(int arr[], int start, int mid, int end);
void mergeSortA(int arr[], int start, int end);
void mergeSortB(int arr[], int start, int end);
void insertionSortAIns(int arr[], int start, int end); // Insertion Sort for merge-insertion algorithm
void insertionSortBIns(int arr[], int start, int end);
void mergeInsertionSortA(int arr[], int start, int stop, int k);
void mergeInsertionSortB(int arr[], int start, int stop, int k);
// with steps
void mergeAS(int arr[], int start, int mid, int end);
void mergeBS(int arr[], int start, int mid, int end);
void mergeSortAS(int arr[], int start, int end);
void mergeSortBS(int arr[], int start, int end);
void insertionSortAInsS(int arr[], int start, int end);
void insertionSortBInsS(int arr[], int start, int end);
void mergeInsertionSortAS(int arr[], int start, int stop, int k);
void mergeInsertionSortBS(int arr[], int start, int stop, int k);

// ===========QUICK SORT===================

// without steps
int partitionHA(int arr[], int start, int end); // Hoarse
void quickSortHA(int arr[], int start, int end);
int partitionHB(int arr[], int start, int end);
void quickSortHB(int arr[], int start, int end);
int partitionLA(int arr[], int start, int end); // Lamuto
void QuicksortLA(int arr[], int start, int end);
int partitionLB(int arr[], int start, int end);
void QuicksortLB(int arr[], int start, int end);
// with steps
int partitionHAS(int arr[], int start, int end);
void quickSortHAS(int arr[], int start, int end);
int partitionHBS(int arr[], int start, int end);
void quickSortHBS(int arr[], int start, int end);
int partitionLAS(int arr[], int start, int end);
void QuicksortLAS(int arr[], int start, int end);
int partitionLBS(int arr[], int start, int end);
void QuicksortLBS(int arr[], int start, int end);

//============SELECTION SORT=================

// without steps
void selectionSortA(int arr[], int n);
void selectionSortB(int arr[], int n);

// with steps
void selectionSortAS(int arr[], int n);
void selectionSortBS(int arr[], int n);

//==========UTILITY FUNCTIONS=================

int *newPermutArray(int n);
int *newRandArray(int n);
void remakeArray(int arr[]);
void printArray(int arr[], int n);
void func_eval(int arr[], int n, void (*func)(int[], int));              // Runs function and returns runtime
void func_eval2(int arr[], int n, int m, void (*func)(int[], int, int)); // for merge and quicksort
void func_evalMergeIns(int arr[], int n, int m, int k, void (*func)(int[], int, int, int));
void func_evalMergeInsSteps(int arr[], int n, int m, int k, void (*func)(int[], int, int, int));
void func_evalStepsMQ(int arr[], int n, int m, void (*func)(int[], int, int));
