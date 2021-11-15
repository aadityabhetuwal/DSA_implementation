#include <iostream>
#include <vector>
#include <cmath>

#define ll long long
#define ull unsigned long long

using namespace std;

template <typename T>
struct Node{

    T value;
    Node* next;
    Node *prev;

    Node(T data) : value(data), next(nullptr), prev(nullptr) { }

    Node() { }
};


template<typename T>
class link_list : protected Node<T> {

    Node<T> *head, *newNode, *nextNode, *rear;
    int sz;

public:

    link_list<T>() : head(nullptr), sz(0), rear(nullptr) { }

    link_list<T>(int size) : head(nullptr), sz(0), rear(nullptr) {
        int dummy = 1e9;

        for(int i = 0; i < size; i++){
            newNode = new Node<T>(dummy);
            
            if(head == nullptr){ 
                head = newNode;
                nextNode = head;
                rear = head;

                // cout << "Element " << data << " inserted succesfully.\n";
                continue;
            }  

            nextNode->next = newNode;
            newNode->prev = nextNode;
            nextNode = newNode;
            rear = nextNode; 
        }

        cout << "Linked list of size " << size << " created successfully\n";
        sz = size;

        nextNode = head;
    }

    ~link_list(){
        // cout << "\nDestructor called.\n";
        delete head, newNode, nextNode, rear;

    }


    void push_back(T data){
        newNode = new Node<T>(data);
        
        if(head == nullptr){ 
            head = newNode;
            nextNode = head;
            rear = head;
            sz++;

            // cout << "Element " << data << " inserted succesfully.\n";
            return;
        }

        if(nextNode->value == 1e9){
            nextNode->value = data;
            nextNode = nextNode->next;
            return;
        }

        nextNode->next = newNode;
        newNode->prev = nextNode;
        nextNode = newNode;
        rear = nextNode;

        sz++;
        // cout << "Element " << data << " inserted succesfully.\n";
    }

    void push_front(T data){
        newNode = new Node<T>(data);

        if(head == NULL){
            head = newNode;
            nextNode = head;
            rear = nextNode;
            sz++;
            // cout << "Element " << data << " inserted succesfully at front/head.\n\n";
            return;
        }

        newNode->next = head;
        head = newNode;

        sz++;
        // cout << "Element " << data << " inserted succesfully at front/head.\n\n";
    }
    
    void insert_with_cond(T data){

        if(rear->value > 10){
            this->push_back(data);
        }else{
            this->push_front(data);
        }
    }

    void push_at_index(int ind, T data){
        
        Node<T> *tmp = head;

        newNode = new Node<T>(data);

        int c = 1;

        while(tmp != nullptr){
            
            if(c == ind - 1){
                newNode->next = tmp->next;
                newNode->prev = tmp;
                tmp->next = newNode;
                sz++;

                // cout << "Element " << data << " inserted succesfully at given index " << ind << "\n\n";
                return;
            }

            c++;
            tmp = tmp->next;
        }

        push_back(data);
    }
    
    void push_middle(T data){
        int mid = sz / 2;

        this->push_at_index(mid, data);
    }

    void display(){
        cout << "\nData in link list is : \n";
        
        newNode = head;

        while(newNode != nullptr){
            cout << "Data : " << newNode->value << '\n';
            newNode = newNode->next;
        }
        cout << '\n';
    }

    

    void display_greater_nodes(T data){
        cout << "\nData greater than " << data << " in reverse order is : ";
        
        link_list<T> tmp;

        newNode = head;

        while(newNode != nullptr){
            // cout << "Data : " << newNode->value << '\n';
            if(newNode->value > data){
                tmp.push_back(newNode->value);
            }
            newNode = newNode->next;
        }

        newNode = tmp.rear;

        while(newNode != nullptr){
            cout << newNode->value << " ";
            newNode = newNode->prev;
        }
        cout << '\n';

    }   


    void delete_nodes(T data){
        newNode = head;

        while(newNode != nullptr){
            // cout << "Data : " << newNode->value << '\n';
            if(newNode->value > data){
                Node<T> *tmp = newNode;
                
                newNode = newNode->prev;
                // tmp->next = newNode;
                newNode->next = tmp->next;
                tmp->next->prev = newNode;
                sz--;
                delete tmp;
                
            }
            newNode = newNode->next;
        }
    }

    void pop_front(){        
        Node<T> *tmp = head;
        head = head->next;

        cout << "Popped head : " << tmp->value << "\n\n";

        delete tmp;
        sz--;
    }

    void pop_middle(T elem){

        newNode = head;

        while(newNode->next != nullptr){

            if(newNode->next->value == elem){
                Node<T> *tmp = newNode->next;
                T val = tmp->value;

                newNode->next = tmp->next;
                cout << "Removed element : " << val << "\n\n";

                delete tmp;
                sz--;

                return;
            }

            newNode = newNode->next;
        }

        cout << "Element not found!\n\n";
    }

    void pop_back(){

        // int  count = this->get_size();    

        // for(int i = 0; newNode != nullptr && i < count - 2; i++){
        //     newNode = newNode->next;
        // }
        
        Node<T> *tmp = rear;

        newNode = rear->prev;
        newNode->next = nullptr;
        rear = newNode;

        cout << "last node : " << tmp->value << " deleted successfullly\n\n";

        delete tmp;
        sz--;
    }
    
    size_t get_size(){
        return sz;
    }
};

int main(){
    link_list<int> list(5);

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.display();

    list.push_at_index(3, 7);
    list.push_at_index(5, 8);

    list.insert_with_cond(9);

    list.display();

    list.pop_front();
    list.pop_back();

    list.display();

    list.push_middle(12);
    list.push_middle(13);

    list.display();

    list.display_greater_nodes(5);

    list.delete_nodes(5);

    list.display();

    return 0;
}
