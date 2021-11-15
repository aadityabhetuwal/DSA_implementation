#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

#define ll long long
#define ull unsigned long long long

using namespace std;

int n;


template<typename T>
void my_swap(T *a, T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}


template <typename T>
void print_arr(T *arr, int n){
    cout << '(';
    for(int i = 0; i < n - 1; i++){
        cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << ")\n";
}


template <typename T>
void print_arr(T *arr, int start, int end){

    for(int i = start; i < end; i++){
        if(i == end - 1)
            cout << arr[i] << " ";
        else
            cout << arr[i] << ", ";
    }
    cout << "\n";
}


template<typename T>
void _merge(T *arr, size_t left, size_t mid, size_t right){

    size_t n1 = mid - left;
    size_t n2 = right - mid + 1;

    T *arr1 = new T[n1], *arr2 = new T[n2];

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

    cout << "Arrays to be mereged were :: \n";
    print_arr(arr1, 0, n1);
    print_arr(arr2, 0, n2);

    cout << "Array after merging to original is :: ";
    print_arr(arr, 0, n);

    cout << "---------------------\n";

    delete arr1, arr2;
}


template<typename T>
void merge_sort(T *arr, size_t l, size_t r){


    if(l >= r)
        return;

    cout << "\n-----------------------\nThe status of array is :: ";
    print_arr(arr, l, r);

    if(r - l <= 1){
        if(r - l == 1){
            if(arr[l] > arr[r])
                my_swap<T>(arr + l, arr + r);
        }
        return;
    }

    size_t mid = l + (r - l) / 2;

    merge_sort(arr, l, mid - 1);
    merge_sort(arr, mid, r);

    _merge<T>(arr, l, mid, r);
}


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    srand(time(NULL)); // for a random seed each execution

    // int *arr;
    cout << "Enter size of array :: ";
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100 - 50;
    }

    cout << "\nThe original array elements is\n";
    print_arr<int>(arr, n);

    merge_sort<int>(arr, 0, n - 1);

    cout << "\nThe array elements after sorting is\n";
    print_arr<int>(arr, n);

    int *arr1 = new int[n];
    memcpy(arr1, arr, n * sizeof(int));

    sort(arr1, arr1 + n);

    // for(int i = 0; i < n; i++){
    //     if (arr1[i] != arr[i]){
    //         cout << "Not equal\n";
    //         exit(1);
    //     }
    // }

    // cout << "Equal\n";

    delete arr, arr1;
    return 0;
}