#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

#define ll long long
#define ull unsigned long long long

using namespace std;

int n;

void print_arr(int *arr, int start, int end){

    for(int i = start; i < end; i++){
        if(i == end - 1)
            cout << arr[i] << " ";
        else
            cout << arr[i] << ", ";
    }
    cout << "\n";
}


void _merge(int *arr, size_t left, size_t mid, size_t right){

    size_t n1 = mid - left;
    size_t n2 = right - mid + 1;

    int *arr1 = new int[n1], *arr2 = new int[n2];

    for(size_t i = 0; i < n1; i++){
        arr1[i] = arr[left + i];
    }

    for(size_t i = 0; i < n2; i++){
        arr2[i] = arr[mid + i];
    }

    size_t c = left;

    for(size_t i = 0, j = 0; i < n1 || j < n2; ){

        if(i >= n1){
            arr[c++] = arr2[j++];
            continue;
        }

        if(j >= n2){
            arr[c++] = arr1[i++];
            continue;
        }

        if(arr1[i] < arr2[j]){
            arr[c++] = arr1[i++];
        }else{
            arr[c++] = arr2[j++];
        }
    }

    cout << "Arrays to be mereged are :: \n";
    print_arr(arr1, 0, n1);
    print_arr(arr2, 0, n2);

    cout << "Array after merging to original is :: ";
    print_arr(arr, 0, n);

    cout << "---------------------\n";

    delete arr1, arr2;
}


void merge_sort(int *arr, size_t l, size_t r){

    if(l >= r)
        return;


    if(r - l <= 1){
        if(r - l == 1){
            if(arr[l] > arr[r])
                std::swap(arr[l], arr[r]);
        }
        return;
    }

    size_t mid = l + (r - l) / 2;

    merge_sort(arr, l, mid - 1);
    merge_sort(arr, mid, r);

    _merge(arr, l, mid, r);
}


int main(){

    srand(time(NULL)); // for a random seed each execution

    int *arr;
    cout << "Enter size of array :: ";
    cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100 - 50;
    }

    cout << "\nThe original array elements is\n";
    print_arr(arr, 0, n);

    merge_sort(arr, 0, n - 1);

    cout << "\nThe array elements after sorting is\n";
    print_arr(arr, 0, n);

    delete arr;
    return 0;
}