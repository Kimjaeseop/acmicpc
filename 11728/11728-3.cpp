#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

// 문제를 풀면서 느끼는건데 정말 문제를 꼼꼼히 읽는 습관을 들이자,,
// AVL tree, BST를 사용해도 시간 초과가나서 문제를 다시 읽어보았다
// 처음엔 단순히 두 개의 배열을 붙여서 정렬하는 문제인 줄 알았는데
// 자세히 읽어보니 두개의 정렬된 배열을 하나의 정렬된 배열로 만드는 것이 목표
// 이해하자마자 merge sort가 생각나서 일단 geeksforgeeks에서 긁어와서 구현해보니
// cpp로 vector에 때려넣고 sort, c언어에서 qsort 사실상 두 개다 퀵 정렬이지만
// 위 두개의 경우보다 merge sort가 빠르다..

// 그래도 620ms라는 큰 런타임을 갖고있어서 다른 사람들이 작성한 코드 중 200ms내에서
// 작동하는 코드를 보려니 이해 할 수 없는 코드들뿐 ,,,

int N, M, in;
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int l, int m, int r) 
{ 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays  
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays L[] and R[]  
    for(int i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for(int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back into arr[l..r] 
      
    // Initial index of first subarray 
    int i = 0;  
      
    // Initial index of second subarray 
    int j = 0;  
      
    // Initial index of merged subarray 
    int k = l; 
      
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])  
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // L[], if there are any  
    while (i < n1)  
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l is for left index and r is  
// right index of the sub-array 
// of arr to be sorted */ 
void mergeSort(int l, int r) 
{ 
    if (l < r) 
    { 
          
        // Same as (l+r)/2, but avoids  
        // overflow for large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        mergeSort(l, m); 
        mergeSort(m + 1, r); 
  
        merge(l, m, r); 
    } 
} 
  
// UTILITY FUNCTIONS  
// Function to print an array  
void printArray(int A[], int size) 
{ 
    for(int i = 0; i < size; i++) 
        cout << A[i] << " "; 
} 
  
int main(void)
{
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	freopen("input_2.txt", "r", stdin);

	cin >> N >> M;

	for (int i = 0; i < N+M; i++) {
		cin >> in;
		arr.push_back(in);
	}

	mergeSort(0, arr.size()-1);

	for (auto iter : arr) {
		cout << iter << " ";
	}

	return 0;
}
