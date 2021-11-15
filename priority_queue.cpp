#include <iostream>
#include <string>
#include <unordered_map>

#define ll long long
#define ull unsigned long long long

using namespace std;

unordered_map<char, string> process_map = {
    {'S', "'system process' "},
    {'U', "'user process' "}
};

template <typename T>
struct Item {
    T value;
    char process_type;
    int time_req;
    int priority;
};


template <typename T>
bool cmp_items(Item<T> item1, Item<T> high_item){

    if(item1.priority == high_item.priority){
        if(item1.process_type == high_item.process_type)
            return item1.time_req < high_item.time_req;
        
        return item1.process_type < high_item.process_type; // since 'S' < 'U'
    }

    return item1.priority > high_item.priority;
}


template<typename T>
class PriorityQueue {
    Item<T> *processes;
    int size = -1, max_size;

public:
    PriorityQueue() { }

    PriorityQueue(int size){
        max_size = size;
        processes = new Item<T>[max_size];
    }

    ~PriorityQueue(){ 
        delete[] processes; 
    }

    bool isEmpty(){
        return size == -1;
    }

    bool isFull(){
        return size == max_size - 1;
    }

    void push(Item<T> it){

        if(isFull()){
            cout << "Overflow! queue is full.\n";
            return;
        }
        
        cout << "\nInserted " << process_map[it.process_type] << "= " << it.value\
            << ", which takes time = " << it.time_req \
            << "ms, with priority = " << it.priority << "\n\n";

        processes[++size] = it;
        
    }

    void pop(){

        if(isEmpty()){
            cout << "Underflow!, queue is empty.\n";
        }

        int max_pri = peek_util();
        
        cout << "\nPopped " << process_map[processes[max_pri].process_type] << "= " << processes[max_pri].value \
            << ", which takes time = " << processes[max_pri].time_req \
            << "ms , with priority = " << processes[max_pri].priority << "\n\n";

        for(int i = max_pri; i < size; i++){
            processes[i] = processes[i + 1];
        }

        size--;
    }

    int peek_util(){
        int max_ind = -1;

        if(isEmpty()){
            throw "Underflow!, queue is empty.\n";
        }
        
        max_ind = 0;

        for(int i = 1; i <= size; i++){
            
            if(cmp_items<T>(processes[i], processes[max_ind])){
                max_ind = i;
            }
            
        }

        return max_ind;
    }

    Item<T> peek(){
        return processes[peek_util()];
    }

    void display(){

        cout << "\nThe elements in queue are : \n";
        int max_pri = peek_util();

        for(int i = 0; i <= size; i++){

            if(max_pri == i){
                cout << process_map[processes[i].process_type] << "= " << processes[i].value << 
                    "\tTime taken = " << processes[i].time_req << "ms" << 
                    "\tPriority = " << processes[i].priority << " <-- highest priority" << "\n";
                continue;
            }
            cout << process_map[processes[i].process_type] << "= " << processes[i].value << 
                    "\tTime taken = " << processes[i].time_req << "ms" <<
                    "\tPriority = " << processes[i].priority << "\n";

        }

        cout << "\n\n";
    }
};


int main(){
    int n, ch;
    int time_taken, pri;
    string proc;
    char type;

    cout << "Enter size of queue : ";
    cin >> n;

    PriorityQueue<string> qu(n);
    Item<string> it;

    while(true){
        std::cout << "1. Enqueue\n2. Dequque\n3. Display\n4. Peek\n5. Exit\n\n";
        std::cout << "Enter your choice : ";
        std::cin >> ch;

        if(ch == 1){
            std::cout << "Enter name of process : ";
            std::cin >> proc;

            std::cout << "Enter type of process system or user[S/U] : ";
            std::cin >> type;

            std::cout << "Enter time required for process(ms): ";
            std::cin >> time_taken;
            
            std::cout << "Enter priority process : ";
            std::cin >> pri;

            qu.push({proc, type, time_taken, pri});

        }else if (ch == 2){
            qu.pop();
            
        }else if (ch == 3){
            qu.display();
        
        }else if(ch == 4){

            try{
                it = qu.peek();
                cout << "Highest priority item has\n";
                cout << process_map[it.process_type] << "= " << it.value << 
                    "\tTime taken = " << it.time_req << 
                    "\t Priority = " << it.priority << "\n";
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