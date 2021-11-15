#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>

#define ll long long
#define ull unsigned long long


using namespace std;

struct Node{

    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node() {}
};

class link_list {

    Node *head, *node, *nextNode;
    int size, max_size;

public:

    link_list<T>() 
            : head(nullptr), sz(-1) { }

    link_list<T>(int size) 
            : head(nullptr), sz(-1), max_size(size) {}

    ~link_list(){
        delete head, node, nextNode;
    }

    bool isFull(){
        return sz == max_size - 1;
    }

    bool isEmpty(){
        return sz == -1;
    }

    void push_front(T data){
        node = new Node<T>(data);

        if(isFull()){
            cout << "Overflow!, Stack if full.\n";
            return;
        }

        if(head == NULL){
            head = node;
            nextNode = head;
            sz++;

            cout << "Element " << data << " inserted succesfully.\n\n";
            return;
        }


        node->next = head;
        head = node;
        sz++;

        cout << "Element " << data << " inserted succesfully.\n\n";

    }

    void display(){
        node = head;

        while(node != nullptr){
            cout << node->value << '\n';
            node = node->next;
        }
        cout << '\n';
    }

    void pop_front(){   

        if(isEmpty()){
            cout << "Underflow!, Stack if full.\n";
            return;
        }   

        Node<T> *tmp = head;
        head = head->next;

        delete tmp;
        sz--;
    }

    T peek(){
        return head->value;
    }

    size_t get_size(){
        return sz;
    }

};

int main(){
    string dob, buff;

    cout << "Enter your dob in dd/mm/yyyy format : ";
    cin >> dob;

    int n = 3, day, month, year;
    char tmp;

    link_list<int> LLstack(n); // since there will be max 3 elements in stack day, month and year

    stringstream ss(dob);
    ss >> day >> tmp >> month >> tmp >> year >> tmp;

    cout << "\nPushing the elements to stack : \n";
    LLstack.push_front(day);
    LLstack.push_front(month);
    LLstack.push_front(year);

    cout << "\nElements in stack are : \n";

    LLstack.display();

    cout << "Your birthdate in yyyy-mm-dd format is : \n";

    for(int i = 0; i < n; i++){
        buff = to_string(LLstack.peek());

        if(buff.size() < 2)
            buff = "0" + buff;

        if(i != n - 1)
            cout << buff << '-';
        else
            cout << buff;

        LLstack.pop_front();
    }
    cout << '\n';

    return 0;
}