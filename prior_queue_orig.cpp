#include <iostream>
#include <unordered_map>


using namespace std;

unordered_map<char, string> process = { {'S', " 'system process'"}, {'U', " 'user process'"}};

struct Item {
    char data;
    int time_req;
    int priority;
};

// item1 is comparing function

bool cmp(Item item1, Item high_item){

    if(item1.priority == high_item.priority){
        if(item1.time_req == high_item.time_req){
            return item1.data < high_item.data;
        }
        return item1.time_req < high_item.time_req;
    }

    return item1.priority > high_item.priority;
}


class PriorityQueue {
    Item *ele;
    int sz = 0, max_size;

public:
    PriorityQueue() { }

    PriorityQueue(int size){
        max_size = size;
        ele = new Item[max_size];
    }

    ~PriorityQueue(){ 
        delete[] ele; 
    }

    bool isEmpty(){
        return sz == 0;
    }

    bool isFull(){
        return sz == max_size - 1;
    }

    void push(char element, int time_taken, int pr){

        if(isFull()){
            cout << "Overflow! queue is full.\n";
            return;
        }
        
    
        string log_msg = "Inserted" + process[element] + ", which takes time = " \
                + to_string(time_taken) + ", with priority = " + to_string(pr);
        cout << log_msg << "\n\n";

        ele[sz++] = {element, time_taken, pr};
        
    }

    void pop(){

        if(isEmpty()){
            cout << "Underflow!, queue is empty.\n";
        }

        int max_pri = peek_util();
        
        string log_msg = "Popped" + process[ele[max_pri].data] + ", which takes time = " \
                + to_string(ele[max_pri].time_req) + ", with priority = " + to_string(ele[max_pri].priority);
        cout << log_msg << "\n\n";

        for(int i = max_pri; i < sz; i++){
            ele[i] = ele[i + 1];
        }

        sz--;
    }

    int peek_util(){
        int max_ind = -1;

        if(isEmpty()){
            throw "Underflow!, queue is empty.\n";
        }
        
        max_ind = 0;

        for(int i = 1; i < sz; i++){
            
            if(cmp(ele[i], ele[max_ind])){
                max_ind = i;
            }
            
        }

        return max_ind;
    }

    Item peek(int ind){
        return ele[ind];
    }

    void display(){

        cout << "\nThe elements in queue are : \n";
        int ind = peek_util();

        for(int i = 0; i < sz; i++){

            if(ind == i){
                cout << process[ele[i].data] << 
                    "\tTime taken = " << ele[i].time_req << 
                    "\t Priority = " << ele[i].priority << " <-- highest priority" << "\n";
                continue;
            }
            cout << process[ele[i].data] << 
                    "\tTime taken = " << ele[i].time_req << 
                    "\t Priority = " << ele[i].priority << "\n";

        }

        cout << "\n\n";
    }
};

int main(){

    PriorityQueue qu(10);

    qu.push('S', 20, 2);
    qu.push('S', 30, 3);
    qu.push('U', 20, 3);
    
    qu.display();

    qu.pop();

    qu.pop();

    qu.push('U', 40, 5);
    qu.push('S', 50, 4);

    qu.pop();

    qu.display();
    return 0;
}
