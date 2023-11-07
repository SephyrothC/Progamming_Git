#include <iostream>
#include <vector>

using namespace std;

void compare_arrays(int arr1[], int arr2[], int size) {
  // loop through the elements of the arrays
  for (int i = 0; i < size; i++) {
    // if the elements are not equal, return false
    if (arr1[i] != arr2[i]) {
      cout << "The arrays are not equal" << endl;
      return;
    }
  }
  // if the loop finishes, the arrays are equal, return true
  cout << "The arrays are equal" << endl;
}

void compare_vector(vector<int> vec1, vector<int> vec2) {
  // compare the vectors using == operator
  if (vec1 == vec2) {
    cout << "The vectors are equal" << endl;
  } else {
    cout << "The vectors are not equal" << endl;
  }
}

// A function to perform bubble sort on an array
int *bubbleSort(int arr[], int n) {
  // loop through the array n-1 times
  for (int i = 0; i < n - 1; i++) {
    // flag to check if any swap occurred in this iteration
    bool swapped = false;
    // loop through the unsorted part of the array
    for (int j = 0; j < n - i - 1; j++) {
      // compare two adjacent elements and swap them if they are in wrong order
      if (arr[j] > arr[j + 1]) {
        // swap the elements
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        // set the flag to true
        swapped = true;
      }
    }
    // if no swap occurred in this iteration, the array is already sorted
    if (!swapped) {
      break;
    }
  }
  return arr;
}

int main(int argc, const char **argv) {

  cout << "Q16 :" << endl;

  int arr1[] = {1, 2, 3}, arr2[] = {1, 2, 3}, arr3[] = {4, 5, 6}, size = 3;
  compare_arrays(arr1, arr2, size);
  compare_arrays(arr1, arr3, size);

  vector<int> vec1 = {1, 2, 3}, vec2 = {1, 2, 3}, vec3 = {4, 5, 6};
  compare_vector(vec1, vec2);
  compare_vector(vec1, vec3);

  cout << endl;
  cout << "Q21 :" << endl;

  int arr[] = {5, 4, 1, 2, 3};
  int *arr_sol = bubbleSort(arr, 5);
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr_sol[i]);
  }

  return 0;
}
