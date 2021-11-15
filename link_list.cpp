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

    Node(T data) : value(data), next(nullptr) { }

    Node() { }
};

template<typename T>
class link_list : protected Node<T> {

    Node<T> *head, *newNode, *nextNode;
    int sz;

public:

    link_list<T>() : head(nullptr), sz(0) { }

    ~link_list(){
        cout << "\nDestructor called.\n";
        delete head, newNode, nextNode;

    }


    void push_back(T data){
        newNode = new Node<T>(data);

        if(head == nullptr){ 
            head = newNode;
            nextNode = head;
            sz++;

            cout << "Element " << data << " inserted succesfully.\n";
            return;
        }

        nextNode->next = newNode;
        nextNode = newNode;
        sz++;
        cout << "Element " << data << " inserted succesfully.\n";
    }

    void push_front(T data){
        newNode = new Node<T>(data);

        if(head == NULL){
            head = newNode;
            nextNode = head;
            sz++;
            cout << "Element " << data << " inserted succesfully at front/head.\n\n";
            return;
        }


        newNode->next = head;
        head = newNode;
        sz++;
        cout << "Element " << data << " inserted succesfully at front/head.\n\n";
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

        int  count = this->get_size();
        
        newNode = head;

        for(int i = 0; newNode != nullptr && i < count - 2; i++){
            newNode = newNode->next;
        }

        cout << "Second last node : " << newNode->value << "\n\n";
        
        Node<T> *tmp = newNode->next;
        newNode->next = nullptr;

        delete tmp;
        sz--;
    }
    
    size_t get_size(){
        return sz;
    }
};

int main(){
    link_list<int> list;

    list.push_back(2);
    list.push_back(3);
    list.push_back(5);

    list.display();
    
    list.pop_front();

    list.push_front(7);

    list.display();

    list.push_back(6);
    list.pop_middle(3);

    list.push_back(10);
    list.push_front(11);

    list.display();

    list.pop_middle(10);
    list.display();

    list.pop_back();

    list.display();
    return 0;
}


