#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
size_t binary_search(T *arr, T elem, int lo, int hi, bool *found){
    int mid;

    if(lo <= hi){
        mid = lo + (hi - lo) / 2;

        if(arr[mid] == elem){
            *found = 1;
            return mid;
        }else if (elem < arr[mid]){
            return binary_search(arr, elem, lo, mid - 1, found);
        }else{    
            return binary_search(arr, elem, mid + 1, hi, found);
        }
    }

    *found = 0;

    if(elem < arr[lo])
        return lo;
    return lo + 1;
}


template<typename T>
void binary_search_util(T *arr, T elem, size_t sz){
    bool found_elem;
    int pos;

    if(sz == 0){
        // cerr is standard error stream

        std::cerr << "Error : The size of the array cannot be zero.\n";
        return; 
    }

    pos = binary_search(arr, elem, 0, sz - 1, &found_elem);

    if(found_elem){
        std::cout << "Element '" << elem << "' found at index '" << pos 
                << "' in the given array.\n";
    }else{
        std::cout << "Element '" << elem << "' was not found but it can be inserted in index '" << pos 
                << "' in the given array.\n";
    }
}

template<typename T>
void printarr(T *arr, size_t n){
    std::cout << '(';

    for(int i = 0; i < n - 1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n - 1] << ")\n";

}


int main(int argc, char** argv){
    int n, elem, pos, tests;
    int *arr;
    bool found_elem;

    cout << "Enter size of list : ";
    cin >> n;

    arr = new int[n];

    srand(time(NULL)); // for a random seed each time

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 26 - 10; // range from -10 to 15
    }

    std::sort(arr, arr + n); // sorting array before binary search


    std::cout << "Enter number of test cases : ";
    std::cin >> tests;

    while(tests--){
        std::cout << "\n--------\nThe given array for searching is : " << '\n';
        printarr(arr, n);

        std::cout << "Enter element to be searched : ";
        std::cin >> elem;

        binary_search_util(arr, elem, n);
    }

    delete arr;
    return 0;
}