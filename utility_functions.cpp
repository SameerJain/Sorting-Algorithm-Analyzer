#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

// UTILITY FUNCTIONS======================================

// GLOBAL VARIABLES================================================

int Size;
int dataSetSizes[8]{100, 300, 500, 1000, 3000, 5000, 10000, 50000};
vector<int> BaseArr;
long long int steps;
long long int CPUTotal;
long long int StepTotal;

int *newPermutArray(int n) {
  int *arr = new int[Size];

  for (int i = 0; i < n; i++) {

    arr[i] = i + 1;
  }

  random_shuffle(arr, arr + Size);

  for (int i = 0; i < Size; i++) {
    BaseArr.push_back(arr[i]);
  }

  return arr;
}

void remakeArray(int arr[]) {

  for (int i = 0; i < Size; i++) {
    arr[i] = BaseArr[i];
  }
}

int *newRandArray(int n) {
  int *arr = new int[Size];
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % Size;
  }

  for (int i = 0; i < Size; i++) {
    BaseArr.push_back(arr[i]);
  }

  return arr;
}

void printArray(int arr[], int n) {
  cout << "(";
  for (int i = 0; i < n; ++i) {
    cout << arr[i];
    if (i != n - 1) {
      cout << ",";
    }
  }
  cout << ")"
       << "\n";
}

void func_eval(int arr[], int n,
               void (*func)(int[], int)) // Runs function and returns runtime
{
  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);
  cout << "CPU Time: " << duration.count() << endl;
}

void func_eval2(int arr[], int n, int m,
                void (*func)(int[], int, int)) // for merge and quicksort
{
  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n, m);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);
  cout << "CPU Time: " << duration.count() << endl;
}

void func_evalMergeIns(
    int arr[], int n, int m, int k,
    void (*func)(int[], int, int,
                 int)) // for merge ins sort, has extra parameter
{
  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n, m, k);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);
  cout << "CPU Time: " << duration.count() << endl;
}

void func_evalMergeInsSteps(
    int arr[], int n, int m, int k,
    void (*func)(int[], int, int,
                 int)) // for merge ins sort, has extra parameter
{
  steps = 0;
  remakeArray(arr);
  func(arr, n, m, k);
  remakeArray(arr);
  cout << "steps: " << steps << endl;
}

void func_evalStepsMQ(int arr[], int n, int m,
                      void (*func)(int[], int,
                                   int)) // stepcounter for merge and quicksort
{
  steps = 0;
  remakeArray(arr);
  func(arr, n, m);
  remakeArray(arr);
  cout << "steps: " << steps << endl;
}

/*
USED FOR PART 2:
void func_eval(int arr[], int n,
               void (*func)(int[], int)) // Runs function and returns runtime
{


  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);

  CPUTotal += duration.count();
}

void func_eval2(int arr[], int n, int m, void (*func)(int[], int, int)) // for
merge and quicksort
{
  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n, m);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);
  CPUTotal += duration.count();
}

void func_evalMergeIns(int arr[], int n, int m, int k, void (*func)(int[], int,
int, int)) // for merge ins sort, has extra parameter
{
  remakeArray(arr);
  auto start = high_resolution_clock::now();
  func(arr, n, m, k);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  remakeArray(arr);
  CPUTotal += duration.count();
}

void func_evalMergeInsSteps(int arr[], int n, int m, int k, void (*func)(int[],
int, int, int)) // for merge ins sort, has extra parameter
{
  steps = 0;
  remakeArray(arr);
  func(arr, n, m, k);
  remakeArray(arr);
  StepTotal += steps;
}

void func_evalStepsMQ(int arr[], int n, int m, void (*func)(int[], int, int)) //
stepcounter for merge and quicksort
{
  steps = 0;
  remakeArray(arr);
  func(arr, n, m);
  remakeArray(arr);
  StepTotal += steps;
}

*/