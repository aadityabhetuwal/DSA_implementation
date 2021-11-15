#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

#define ll long long
#define ull unsigned long long long

using namespace std;

int n;


template <typename T>
void Swap (T *a, T *b){
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

template <typename T>
int partition_from_back(T *arr, int left, int right){
    T pivot = arr[right];

    int ind = left;

    cout << "The pivot element is : " << pivot << '\n';

    for(int i = left; i < right; i++){

        if(arr[i] < pivot){
            Swap<int>(&arr[ind++], &arr[i]);
        }
    }

    Swap(&arr[ind], &arr[right]);

    cout << "Elements less than pivot is : ";
    print_arr(arr, left, ind);

    cout << "Elements greater than or equal to pivot is : ";
    print_arr(arr, ind, right + 1);

    cout << "\n---------------------------\n";

    return ind;
}

template <typename T>
void Qsort(T *arr, int left, int right){

    cout << "\n-----------------------\nThe status of array is :: ";
    print_arr(arr, 0, n);

    if(left >= right){
        return;
    }  

    int pi = partition_from_back(arr, left, right);

    //cout << left << "\t" << pi << "\t" << right << '\n';

    Qsort(arr, left, pi - 1);
    Qsort(arr, pi + 1, right);
}



int main(){
    int *arr;

    cout << "Enter size of array : ";
    cin >> n;

    arr = new int[n];
    // arr1 = new int[n];
    
    srand(time(NULL)); // random seed generation

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100 - 50;
    }

    cout << "\nThe original array elements is\n";
    print_arr<int>(arr, n);

    Qsort<int>(arr, 0, n - 1);

    cout << "\nThe array elements after sorting is\n";
    print_arr<int>(arr, n);

    delete arr;

    return 0;
}