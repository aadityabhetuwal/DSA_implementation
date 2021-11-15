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
        os << i << ' ';
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

// insertion sort algorithm
template <typename T>
void insertion_sort(vector<T>& ve, bool asc){
    long long j;
    size_t n = ve.size();
    T tmp;

    cout << "\nThe process of sorting the given array using insertion sort : \n";

    for(size_t i = 1; i < n; i++){
        j = i - 1;
        tmp = ve[i];

        cout << "\ni = " << i << " key = " << tmp << "\n" << ve << "\n";

        while (j >= 0 && cmp<T>(ve[j], tmp, asc)){
            ve[j + 1] = ve[j];
            j--;

            cout << ve << "\n";

        }
        cout << "----------------------------------------------------------\n";

        ve[j + 1] = tmp;
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
    insertion_sort<int>(ve, false);

    cout << "After sorting\n" << ve << '\n';


    return 0;
}


