#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ll long long
#define ull unsigned long long long

using namespace std;

template <typename T>
struct Node{

    T value;
    Node* next;

    Node(T data) : value(data), next(nullptr) { }

    Node() { }
};

template <typename T>
class Graph{

    int sz;
    vector<Node<T>*> lists; // to hold rear elements of heads
    vector<Node<T>*> heads;
    vector<vector<int>> adjacency_matrix;
    unordered_map<T, bool> visited;

    void DFS_util(Node<T>* node){
        visited[node->value] = 1;

        cout << node->value << "\t";
        
        Node<T>* it = heads[node->value];
        
        for(; it != nullptr; it = it->next){
            
            if(visited.find(it->value) == visited.end()){
                DFS_util(it);
            }
        }
    }


    void DFS_util1(Node<T>* node){
        visited[node->value] = 1;

        cout << node->value << "\t";
        
        Node<T>* it = heads[node->value];
        
        for(; it != nullptr; it = it->next){
            
            if(visited.find(it->value) == visited.end()){
                DFS_util(it);
            }
        }
    }
    

    void BFS_util(Node<T>* node){
        visited[node->value] = 1;

        T tmp = node->value;
        Node<T>* it, *i;

        queue<T> next;
        next.push(node->value);

        cout << tmp << "\t";
        bool flag;

        while(!next.empty()){
            flag = 0;
        
            tmp = next.front();
                       
            next.pop();
            
            // next.push_back(it);
            for(it = heads[tmp]; it != nullptr; it = it->next){

                if(visited.find(it->value) == visited.end()){
                    flag = 1;
                    next.push(it->value);   
                    cout << it->value << "\t";
                    visited[it->value] = 1;
                }
            }
            if(flag){
                cout << '\n';
            }
        }

    }


public:


    Graph() : sz(0) { }

    // n nodes/ vertices
    Graph(int v, vector<int>& vertices){
        sz = v;
        Node<T> *tmp;

        for(int i = 0; i < sz; i++){
            tmp = new Node<T>(vertices[i]);
            lists.push_back(tmp);
            heads.push_back(tmp);
        }
        
        // adjacency matrix initializing
        adjacency_matrix.resize(sz, vector<int>(sz));
    }


    void add_edge(int ver, int edge){
        // finding index of vertex
        // cannot enter non existing vertex
        int ind1 = -1, ind2 = -1;

        for(int i = 0; i < sz; i++){
            if(heads[i]->value == ver){
                ind1 = i;
            }

            if(heads[i]->value == edge){
                ind2 = i;
            }

            if(ind1 != -1 && ind2 != -1)
                break;
        }

        if(ind1 == -1 || ind2 == -1){
            cout << "Vertex of graph could not be found\n";
            return;
        }

        // loop till linklist->next == null to insert edge
        Node<T> *currVer = lists[ind1], *currEdge = lists[ind2];

        currVer->next = new Node<T>(edge);
        currVer = currVer->next;
        lists[ind1] = currVer;

        currEdge->next = new Node<T>(ver);
        currEdge = currEdge->next;
        lists[ind2] = currEdge;

        // updating adjacency matrix
        adjacency_matrix[ind1][ind2] = 1;
        adjacency_matrix[ind2][ind1] = 1;
        return;
    }

    void print_graph_representation(){
        Node<T> *hd;

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for(int i = 0; i < sz; i++){
            hd = heads[i];

            while(hd){
                cout << hd->value << " -> ";
                hd = hd->next;
            }
            cout << " NULL \n";

        }
        cout << '\n';
    }


    void print_matrix_representation(){
        cout << "\nThe adjacency matrix representation of graph is :: \n";

        for(int i = 0; i < sz; i++){
            cout << "Vertex " << heads[i]->value << " :: (";

            for(int j = 0; j < sz - 1; j++){
                cout << adjacency_matrix[i][j] << ", ";
            }
            cout << adjacency_matrix[i][sz - 1] << ")\n";
        }

        cout << '\n';
    }


    void DFS(int node_val){
        visited.clear();
        
        cout << "\nThe Depth First Search traversal is : \n";

        Node<T> *tmp = new Node<T>(node_val);

        DFS_util(tmp); 

        // dfs for disconnected

        for(Node<T>* it : heads){
            if(visited.find(it->value) == visited.end()){
                DFS_util(it);
            }
        }
        cout << "\n\n";

    }


    void BFS(int node_val){
        visited.clear();
        
        cout << "\nThe Breadth First Search is : \n";

        Node<T> *tmp = new Node<T>(node_val);

        BFS_util(tmp); 

        // dfs for disconnected

        for(Node<T>* it : heads){
            if(visited.find(it->value) == visited.end()){
                DFS_util(it);
            }
        }

        cout << "\n\n";
    }
    
};


int main(){
    int n = 14;


    vector<int> vertices(n);

    for(int i = 0; i < n; i++){
        vertices[i] = i;
    }

    Graph<int> graph_ll(n, vertices);

    // graph_ll.add_edge(0, 1);
    // graph_ll.add_edge(0, 3);
    // graph_ll.add_edge(0, 5);
    // graph_ll.add_edge(1, 2);
    // graph_ll.add_edge(1, 6);
    // graph_ll.add_edge(2, 5);
    // graph_ll.add_edge(2, 6);
    // graph_ll.add_edge(3, 4);
    // graph_ll.add_edge(3, 6);
    // graph_ll.add_edge(4, 5);
    // graph_ll.add_edge(8, 9);

    graph_ll.add_edge(0, 1);
    graph_ll.add_edge(0, 4);
    graph_ll.add_edge(0, 2);
    graph_ll.add_edge(1, 4);
    graph_ll.add_edge(2, 4);
    graph_ll.add_edge(2, 9);
    graph_ll.add_edge(2, 5);
    graph_ll.add_edge(2, 10);
    graph_ll.add_edge(5, 6);
    graph_ll.add_edge(5, 7);
    graph_ll.add_edge(5, 8);
    graph_ll.add_edge(7, 8);
    graph_ll.add_edge(9, 11);
    graph_ll.add_edge(10, 11);
    graph_ll.add_edge(3, 12);
    graph_ll.add_edge(12, 13);



    graph_ll.print_graph_representation();
    graph_ll.print_matrix_representation();
    
    int vertex;
    cout << "Enter vertex to start DFS from : ";
    cin >> vertex;

    graph_ll.DFS(vertex);

    cout << "Enter vertex to start BFS from : ";
    cin >> vertex;

    graph_ll.BFS(vertex);

    return 0;
}