#include <iostream>

/*
Merges two subarrays of arr[]
First subarray is arr[l...m]
Second subarray is arr[m+1...r]
*/
void merge(int arr[], int l, int m, int r){
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temp arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (int i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];


  int i = 0;    // Initial Index of L[]
  int j = 0;    // Initial Index of R[]
  int k = l;    // Initial Index of Merged subarray

  // Merge temp arrays back into arr[l...r]
  while (i < n1 && j < n2){
    if (L[i] <= R[j]){
      arr[k] = L[i];
      i++;
    }else{
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[] if there are any
  while (i < n1){
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[] if there are any
  while (j < n2){
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int l, int r){
  if (l < r){
    int m = l + (r - l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m+1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  int arr[] = {5, 2, 3, 4, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  mergesort(arr, 0, n-1);

  for (int i = 0; i < n; i++)
    std::cout << arr[i] << " ";
}