#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;

template<typename T>
class Circular_Queue{
    T *ele;
    int front = -1, rear = -1; 
    int sz = 0, max_size;

public:
    Queue() { }

    Queue(int size){
        max_size = size;
        ele = (T*) malloc(max_size * sizeof(T));
    }

    ~Queue(){ 
        free(ele); 
    }

    bool isEmpty(){
        return sz == 0;
    }

    bool isFull(){
        return sz == max_size;
    }

    void push(T element){

        if(isFull()){
            cout << "Overflow! queue is full.\n";
            return;
        }
        
        front = (front == -1) ? 0 : front;
        
        sz++;
       
        rear = (rear + 1) % max_size;
        ele[rear] = element;
        
        cout << "Element " << element << " inserted at index " << rear << "\n\n";
    }

    void pop(){

        if(isEmpty()){
            cout << "Underflow!, queue is empty.\n";
        }

        cout << "Popped element : " << ele[front] << " at index " << front << "\n\n";

        ele[front] = 1e9;
        sz--;
        front = (++front) % max_size;

    }

    T peek(){
        
        if(isEmpty()){
            throw "Underflow!, queue is empty.\n";
        }

        return ele[front];
    }

    void display(){

        cout << "\nThe elements in queue are : \n";

        for(int i = 0; i < max_size; i++){
            
            if(ele[i] == (int)1e9){
                continue;

            }else if(i == front){
                cout << ele[i] << " <-- front\n";

            }else if(i ==  rear){
                cout << ele[i] << " <-- rear\n";

            }else{
                cout << ele[i] << '\n';
            }
            
        }
    }
};

int main(){
    int n, ch, x, res;
    cout << "Enter size of queue : ";
    cin >> n;

    Queue<int> qu(n);

    while(true){
        std::cout << "1. Enqueue\n2. Dequque\n3. Display\n4. Peek\n5. Exit\n\n";
        std::cout << "Enter your choice : ";
        std::cin >> ch;

        if(ch == 1){
            std::cout << "Enter the number to be inserted : ";
            std::cin >> x;  
            qu.push(x);

        }else if (ch == 2){
            qu.pop();
            
        }else if (ch == 3){
            qu.display();
        
        }else if(ch == 4){

            try{
                res = qu.peek();
                cout << res << " < -- front\n";
            }catch(const string st){
                cout << st << '\n';
            }

        }else if(ch == 5){
            break;
        
        } else {
            std::cout << "Invalid choice\n";
        
        }
        std::cout << "\n\n";
    }

    return 0;
}