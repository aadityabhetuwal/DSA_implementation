#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define ll long long
#define ull unsigned long long


using namespace std;

// overloading cout to print array/vector of type T
template<typename T>
ostream& operator <<(ostream& os, vector<T>& ve){
    
    for(const auto i : ve){
        os << i << "  ";
    }
    return os;
}

//function to swap two elements
template <typename T>
void Swap(T *a, T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// selection sort algorithm
template <typename T>
void selection_sort(vector<T>& ve){
    long long j;
    size_t n = ve.size();
    size_t min_index;
    T tmp;

    cout << "\nThe process of sorting the given array using selection sort : \n";

    for(size_t i = 0; i < n - 1; i++){
        min_index = i;

        cout << "\ni = " << i << "\n" << ve << "\n";
        
        for(size_t j = i + 1; j < n; j++){

            if(ve[j] < ve[min_index]){
                min_index = j;
            }
            // cout << ve << '\n';
        }
        
        cout << "minimum index = " << min_index << " swapping 'i' and minimum index"<< "\n";

        Swap(&ve[i], &ve[min_index]);

        cout << ve << "\n";
        cout << "\n---------------------------------------------------------------\n";
    }
}

int main(){
    srand(time(NULL));

    int n;
    cout << "Enter number of elements in an array : ";
    cin >> n;

    vector<int> ve(n);

    // cout << "Enter array elements : \n";

    for(int i = 0; i < n; i++){
        ve[i] = -50 + rand() % 150; // random number between -50 and 100
    }
    
    cout << "\nArray elements before sorting : \n" << ve << '\n';
    selection_sort<int>(ve);

    cout << "After sorting\n" << ve << '\n';

    return 0;
}