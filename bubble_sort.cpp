#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define ll long long
#define ull unsigned long long


using namespace std;

template<typename T>
ostream& operator <<(ostream& os, vector<T>& ve){
    
    for(const auto i : ve){
        os << i << "  ";
    }
    return os;
}

// `asc` is False for descending order, `asc` is True for ascending order
template <typename T>
bool cmp(T a, T b, bool asc){ 
    if(asc)
        return (a < b);
    return (a > b);
}

//function to swap two elements
template <typename T>
void Swap(T *a, T *b){
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

// bubble sort algorithm
template <typename T>
void bubble_sort(vector<T>& ve, bool asc){
    long long j;
    size_t n = ve.size();
    T tmp;

    cout << "\nThe process of sorting the given array using bubble sort : \n";

    for(size_t i = 0; i < n - 1; i++){
        
        cout << "\ni = " << i << "\n" << ve << "\n";
        
        for(size_t j = 0; j < n - i - 1; j++){

            if(cmp(ve[j], ve[j + 1], asc)){
                Swap(&ve[j], &ve[j + 1]);
            }
            cout << ve << '\n';
        }
        cout << ve << " has been bubbled.\n";
        cout << "----------------------------------------------------------\n";

    }
}

int main(){
    srand(time(NULL));

    int n = 10;
    // cout << "Enter number of elements in an array : ";
    // cin >> n;

    vector<int> ve = {10, 6, 92, 70, 40, 87, 9, 2};

    // cout << "Enter array elements : \n";

    // for(int i = 0; i < n; i++){
    //     ve[i] = -50 + rand() % 150; // random number between -50 and 100
    // }
    
    cout << "\nArray elements before sorting : \n" << ve << '\n';
    bubble_sort<int>(ve, false);

    cout << "After sorting\n" << ve << '\n';

    return 0;
}