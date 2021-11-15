#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
#include <queue>

#define ll long long
#define ull unsigned long long long

using namespace std;

// template <typename T>
// struct Node{

//     T value;
//     Node* next;

//     Node(T data) : value(data), next(nullptr) { }

//     Node() { }
// };

template <typename T>
class Graph{

    
    int sz;
    // vector<Node<T>*> lists; // to hold rear elements of heads
    // vector<Node<T>*> heads;

    map<T, list<T>> heads;

    vector<vector<int>> adjacency_matrix;
    unordered_map<T, bool> visited;
    // typename list<T>::iterator it;

    void DFS_util(T node){
        visited[node] = 1;

        cout << node << "\t";

        typename list<T>::iterator it = heads[node].begin();

        for(; it != heads[node].end(); ++it){
            
            if(visited.find(*it) == visited.end()){
                DFS_util(*it);
            }
        }
    }
    

    void BFS_util(T node){
        visited[node] = 1;

        T tmp;
        queue<T> next;
        next.push(node);

        cout << node << "\t";
        bool flag;

        while(!next.empty()){
            flag = 0;
        
            tmp = next.front();
                       
            next.pop();
            
            typename list<T>::iterator it = heads[tmp].begin();

            for(; it != heads[tmp].end(); it++){

                if(visited.find(*it) == visited.end()){
                    flag = 1;
                    next.push(*it);   
                    cout << *it << "\t";
                    visited[*it] = 1;
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
    Graph(int v, vector<T>& vertices){
        sz = v;
        // Node<T> *tmp;

        for(int i = 0; i < sz; i++){
            
            heads[vertices[i]].push_back(vertices[i]);
        }
        
        // adjacency matrix initializing
        adjacency_matrix.resize(sz, vector<int>(sz));
    }


    void add_edge(T ver, T edge){


        if(heads.find(ver) == heads.end()){
            heads[ver].push_back(ver);
            return;
        }

        if(heads.find(edge) == heads.end()){
            heads[edge].push_back(edge);
            return;
        }

        heads[ver].push_back(edge);
        heads[edge].push_back(ver);
        

        // updating adjacency matrix
        adjacency_matrix[ver - 'A'][edge - 'A'] = 1;
        adjacency_matrix[edge - 'A'][ver - 'A'] = 1;
        return;
    }

    void print_graph_representation(){
        typename list<T>::iterator it;

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for(pair<T, list<T>> key : heads){
            

            for(auto it = key.second.begin(); it != key.second.end(); it++){
                cout << *it << " -> ";
            }
            cout << " NULL \n";

        }
        cout << '\n';
    }


    void print_matrix_representation(){
        cout << "\nThe adjacency matrix representation of graph is :: \n";

        int i;
        int sz = heads.size();

        for(pair<T, list<T>> key : heads){
            cout << "Vertex " << key.second.front() << " :: (";

            i = key.first - 'A';

            for(int j = 0; j < sz - 1; j++){
                cout << adjacency_matrix[i][j] << ", ";
            }
            cout << adjacency_matrix[i][sz - 1] << ")\n";
        }

        cout << '\n';
    }


    void DFS(T node_val){
        visited.clear();
        
        cout << "\nThe Depth First Search traversal is : \n";
        DFS_util(node_val); 

        // dfs for disconnected

        for(pair<T, list<T>> key : heads){
            if(visited.find(key.first) == visited.end()){
                DFS_util(key.first);
            }
        }
        cout << "\n\n";

    }


    void BFS(T node_val){
        visited.clear();
        
        cout << "\nThe Breadth First Search is : \n";

        BFS_util(node_val); 

        // dfs for disconnected

        for(pair<T, list<T>> key : heads){
            if(visited.find(key.first) == visited.end()){
                DFS_util(key.first);
            }
        }

        cout << "\n\n";
    }
    
};


int main(){
    int n = 7;


    vector<char> vertices(n);

    for(int i = 0; i < n; i++){
        vertices[i] = 'A' + i;
        // cout << vertices[i] << " ";
    }

    Graph<char> graph_ll(n, vertices);

    graph_ll.add_edge('A', 'B');
    graph_ll.add_edge('A', 'C');
    graph_ll.add_edge('A', 'D');
    graph_ll.add_edge('B', 'E');
    graph_ll.add_edge('C', 'D');
    graph_ll.add_edge('D', 'E');
    graph_ll.add_edge('D', 'G');
    graph_ll.add_edge('E', 'F');
    graph_ll.add_edge('F', 'G');


    graph_ll.print_graph_representation();
    graph_ll.print_matrix_representation();
    
    char vertex;
    cout << "Enter vertex to start DFS from : ";
    cin >> vertex;

    graph_ll.DFS(vertex);

    cout << "Enter vertex to start BFS from : ";
    cin >> vertex;

    graph_ll.BFS(vertex);

    return 0;
}