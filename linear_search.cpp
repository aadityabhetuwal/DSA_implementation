#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

template<typename T>
void printarr(T *arr, size_t n){
    std::cout << '(';

    for(int i = 0; i < n - 1; i++){
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[n - 1] << ")\n";

}

template<typename T>
int linear_search(T *arr,T elem, size_t sz){

    for(int i = 0; i < sz; i++)
        if(arr[i] == elem)
            return i;
    
    return -1;
}


int main(void){
    int n, elem, pos, tests;
    int *arr;

    std::cout << "Enter size of list : ";
    std::cin >> n;

    arr = new int[n];

    srand(time(NULL)); // for a random seed each time

    for(int i = 0; i < n; i++){
        arr[i] = rand() % 26 - 10; // range from -10 to 15
    }
    
    std::cout << "Enter number of test cases : ";
    std::cin >> tests;

    while(tests--){
        std::cout << "\n--------\nThe given array for searching is : " << '\n';
        printarr(arr, n);
        
        std::cout << "Enter element to be searched : ";
        std::cin >> elem;

        pos = linear_search<int>(arr, elem, n);

        if(pos == -1){
            std::cout << "Element " << elem << " not found.\n";
        }else{
            std::cout << "Element '" << elem << "' found at index = '" << pos << "'\n";
        }    
    }
    
    delete arr;
    return 0;
}