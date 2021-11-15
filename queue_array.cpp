#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;

template<typename T>
class Queue{
    T *ele;
    int front = 0, rear = 0; 
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
        return (sz == 0);
    }

    bool isFull(){
        return sz == max_size;
    }


    void enqueue(T element){

        if(isFull()){
            cout << "Overflow! queue is full.\n";
            return;
        }
        
        sz++;
        ele[rear++] = element;
        
    }

    void dequeue(){

        if(isEmpty()){
            cout << "Underflow! queue is empty.\n";
            return;
        }
        cout << "Dequeued element is = " << ele[front] << '\n';

        sz--;
        front++;
    }

    void display(){

        cout << "\nThe elements in queue are : \n";

        for(int i = front; i < rear; i++){
            
            if(i == front){
                cout << ele[i] << " <-- front\n";

            }else if(i ==  rear - 1){
                cout << ele[i] << " <-- rear\n";

            }else{
                cout << ele[i] << '\n';
            }
            
        }
    }

    T peek(){
        
        if(isEmpty()){
            throw "Underflow! queue is empty\n";
        }

        return ele[front];
    }
};


int main(){
    int n, ch, x, res;
    cout << "Enter size of queue : ";
    cin >> n;

    Queue<int> qu(n);

    while(true){
        std::cout << "1. Insertion\n2. Deletion\n3. Display\n4. Peek\n5. Exit\n\n";
        std::cout << "Enter your choice : ";
        std::cin >> ch;

        if(ch == 1){
            std::cout << "Enter the number to be inserted : ";
            std::cin >> x;  
            qu.enqueue(x);

        }else if (ch == 2){
            qu.dequeue();
            
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