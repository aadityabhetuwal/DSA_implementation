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


int partition(int *arr, int left, int right){
    int pivot = arr[right];

    int ind = left;

    cout << "The pivot element is : " << pivot << '\n';

    for(int i = left; i < right; i++){

        if(arr[i] < pivot){
            std::swap(arr[ind++], arr[i]);
        }
    }

    std::swap(arr[ind], arr[right]);

    cout << "Elements less than pivot is : ";
    print_arr(arr, left, ind);

    cout << "Elements greater than or equal to pivot is : ";
    print_arr(arr, ind, right + 1);

    return ind;
}

void QuickSort(int *arr, int left, int right){

    if(left >= right){
        return;
    }  

    cout << "\n-----------------------\nThe status of array is :: ";
    print_arr(arr, 0, n);

    int pi = partition(arr, left, right);

    //cout << left << "\t" << pi << "\t" << right << '\n';

    QuickSort(arr, left, pi - 1);
    QuickSort(arr, pi + 1, right);
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
    print_arr(arr, 0, n);

    QuickSort(arr, 0, n - 1);

    cout << "\nThe array elements after sorting is\n";
    print_arr(arr, 0, n);

    delete arr;

    return 0;
}