#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;


template<typename T>
class Heap{
    T *heap_arr;
    long long int sz;
    long long int max_size;
    long long int counter;

    bool default_comp(const T &a, const T &b){
        return a < b;
    }
    bool (*_cmp_heap_elem)(T, T) = &defau;

    Heap() : sz(0), counter(0) { }

    Heap(size_t size) : sz(0), counter(0){
        max_size = size;
        heap_arr = new T[max_size];

        memset(heap_arr, -1, sizeof(T) * max_size);
    }

    Heap(size_t size, bool (*cmp)(T, T) ) : sz(0), counter(0){
        max_size = size;
        heap_arr = new T[max_size];

        memset(heap_arr, -1, sizeof(T) * max_size);
        _cmp_heap_elem = &cmp;
    }


    bool empty(){ return (sz == 0); }

    bool full() { return (sz == max_size); }

    int parent(int ind){
        return (ind - 1)/ 2;
    }

    int left_child(int ind){
        return (2 * ind + 1);
    }

    int right_child(int ind){
        return (2 * ind + 2);
    }

    void heapification_upwards(int ind){

        while (ind > 0 && _comp_heap_elem( heap_arr[parent(ind)], heap_arr[ind]) ){
            std::swap(heap_arr[ind], heap_arr[parent(ind)] );
            ind = parent(ind);
        }
    }

    void heapification_downwards(int ind){
        int swap_ind = ind;
        int left_ind = this->left_child(ind);
        int right_ind = this->right_child(ind);

        if(left < sz && _comp_heap_elem(heap_arr[swap_ind], heap_arr[left_ind]) ){
            swap_ind = left_ind;
        }

        if(right < sz && _comp_heap_elem(heap_arr[swap_ind], heap_arr[right_ind]) ){
            swap_ind = right_ind;
        }

        if(swap_ind != ind){
            std::swap(heap[swap_ind], heap[ind]);
            heapification_downwards(swap_ind);
        }
    }

public :
    void push(T data){
        
        if(!this->full()){
            std::cerr << "Heap is full so data cannot be inserted.\n";
            return;
        }

        sz++;
        heap_arr[counter++] = data;

        heapification_upwards(counter);
    }

    vo
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}