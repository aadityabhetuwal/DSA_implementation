#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long


using namespace std;

template <typename T>
class MyStack{

    T *ele;
    size_t size;
    int top;
    T minEle; // minimum value in stack

public:

    MyStack(){
        top = -1;
        size = 0;
    }

    MyStack(int sz){
        size = sz;
        ele = (T *) malloc(size * sizeof(T));

        top = -1;
    }

    ~MyStack(){
        free(ele);
    }

    bool is_empty(){ 
        return (top == -1); 
    }

    bool is_full(){
        return (top == size);
    }

    void push_back(T element){

        if(is_full()){
            printf("Overlfow!, Stack is full.\n");
            return;
        }
        top++;

        if(is_empty()) //since no stack is big enough to reach string::npos
            minEle = element;
        
        if(element < minEle){
            minEle = element;
            ele[top] = 2*element - minEle;

        }else{
            ele[top] = element;
        }
    }

    T pop_back(){

        if(is_empty()){
            throw "a";
        }
        T tmp = top;
        top--;

        if(tmp < minEle){
            minEle = 2*minEle - t;
        }
        
        return ele[top + 1];
    }

    void peek(){

        if(is_empty()){
            cout << "Unerflow!, stack is empty.\n";
            return;
        }

        cout << "Top element is : " << ele[top] << '\n';
    }

    T get_minElem(){
        return minEle;
    }
};

int main(){
    int n, tmp;
    cout << "Enter size of stack : ";
    cin >> n;


    MyStack<int> stack(n);

    cout << "Enter stack elements : \n";

    for(int i = 0; i < n; i++){
        cin >> tmp;
        stack.push_back(tmp);
    }

    cout << "Minimum element in stack is : " << stack.get_minElem() << "\n";

    return 0;
}

