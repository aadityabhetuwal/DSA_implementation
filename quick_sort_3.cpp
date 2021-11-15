#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

#define ll long long
#define ull unsigned long long long

using namespace std;


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

    for(int i = start; i <= end; i++){
        if(i == end - 1)
            cout << arr[i] << " ";
        else
            cout << arr[i] << ", ";
    }
    cout << "\n";
}


template <typename T>
int partition_from_back(T *arr, int left, int right, int *m1, int *m2){
    T pivot = arr[right];

    int ind = left;
    int r = right;
    // int i = left, j = right;

    for(; ind <= right; ind++){
        
        if(arr[ind] > pivot){
            Swap<T>(arr + ind, arr + right--);
        }else if(arr[ind] == pivot){
            // ind++;
        }else{
            Swap<T>(arr + ind, arr+ left++);
        }

        cout << ind << " " << left << " " << right << '\n';
    }

    *m1 = left;
    *m2 = ind + 1;

    //Swap(&arr[ind], &arr[right]);
    cout << "\nleft : ";
    print_arr(arr, 0, *m1);
    cout << "mid : ";
    print_arr(arr, *m1, *m2 - 1);
    cout << "right : ";
    print_arr(arr, *m2, r);
    cout << "\n\n";

    return ind;
}

template <typename T>
void Qsort(T *arr, int left, int right){


    if(left >= right){
        return;
    }  

    print_arr(arr, left, right);

    int m1, m2;

    int pi = partition_from_back(arr, left, right, &m1, &m2);

    // cout << left << "\t" << pi << "\t" << right << '\n';

    Qsort(arr, left, m1 - 1);
    Qsort(arr, m2, right);
}

int n;


int main(){
    int *arr, *arr1;
    cout << "Enter size of array : ";
    cin >> n;

    arr = new int[n];
    arr1 = new int[n];
    
    // srand(time(NULL));

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100 - 50;
    }

    memcpy(arr1, arr, n * sizeof(int));
    print_arr<int>(arr, n);

    Qsort<int>(arr, 0, n - 1);

    print_arr<int>(arr, n);

    sort(arr1, arr1 + n);

    for(size_t i = 0; i < n; i++){
        if(arr[i] != arr1[i]){
            cout << "not equal\n";
            exit(1);
        }
    }

    cout << "Equal\n";

    return 0;
}