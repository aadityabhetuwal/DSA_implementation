#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define ll long long
#define ull unsigned long long long

using namespace std;

template<typename T>
bool cmp(T a, T b) { return a < b; }

/* Heap implementation with custom comparision operator for MinHeap and MaxHeap */
template<typename T>
class Heap{
    T *heap_arr;
    int sz;
    int max_size;
    int counter;


    static bool default_comp(T a, T b){
        return a < b;
    }

    bool (*_cmp_heap_elem)(T, T) = default_comp;


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

        while (ind > 0 && (*_cmp_heap_elem)( heap_arr[parent(ind)], heap_arr[ind]) ){
            std::swap(heap_arr[ind], heap_arr[parent(ind)] );
            ind = parent(ind);
        }
    }

    void heapification_downwards(int ind){
        int swap_ind = ind;
        int left_ind = this->left_child(ind);
        int right_ind = this->right_child(ind);

        if(left_ind < sz && (*_cmp_heap_elem)(heap_arr[swap_ind], heap_arr[left_ind]) ){
            swap_ind = left_ind;
        }

        if(right_ind < sz && (*_cmp_heap_elem)(heap_arr[swap_ind], heap_arr[right_ind]) ){
            swap_ind = right_ind;
        }

        if(swap_ind != ind){
            std::swap(heap_arr[swap_ind], heap_arr[ind]);
            heapification_downwards(swap_ind);
        }
    }

    
public :

    Heap() : sz(0), counter(0) { }

    Heap(int size) : sz(0), counter(0){
        max_size = size;
        heap_arr = new T[max_size];

        memset(heap_arr, -1, sizeof(T) * max_size);
    }

    Heap(int size, bool (*cmp)(T, T) ) : sz(0), counter(0){
        max_size = size;
        heap_arr = new T[max_size];

        memset(heap_arr, -1, sizeof(T) * max_size);

        _cmp_heap_elem = cmp;
    }

    ~Heap(){
        delete heap_arr;
    }

    void push(T data){
        
        if(this->full()){
            std::cerr << "Error : Cannot insert element into a full heap.\n";
            return;
        }

        sz++;
        heap_arr[counter] = data;

        heapification_upwards(counter);
        counter++;
    }

    T top(){
        return heap_arr[0];
    }

    void pop_index(int ind){

        if(this->empty()){
            std::cerr << "Error: Cannot remove element from empty heap.\n";
            return;
        }

        this->heap_arr[ind] = this->heap_arr[counter];
        this->sz--;
        this->counter--;

        this->heapification_downwards(ind);
    }

    void pop_root(){
        int i = 0;
        this->pop_index(0);
    }

    void display(){
        std::cout << "Heap elements in order are :\n[";

        for(int i = 0; i < sz - 1; i++){
            std::cout << heap_arr[i] << ", ";
        }
        std::cout << heap_arr[sz - 1] << "]\n";
    }
};

int main(){

    Heap<int> he(9, cmp);

    he.push(45);
    he.push(40);

    he.display();

    he.push(75);

    he.display();


    return 0;
}