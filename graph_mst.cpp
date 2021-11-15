#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <map>
#include <set>
#include <list>
#include <unordered_set>
#include <queue>
#include <utility>

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

template<typename T, typename U>
struct VertexEdgePair{
    T vertex;
    T edge;
    U weight;

    VertexEdgePair() { }

    VertexEdgePair(T ver, T edg, U wei){
        if(ver > edg){
            swap(ver, edg);
        }
        vertex = ver;
        edge = edg;
        weight = wei;
    }

};

template<typename T, typename U>
struct CompareWeights{
    bool operator() (VertexEdgePair<T, U> &p1, VertexEdgePair<T, U> &p2){

        if(p1.weight == p2.weight)
            return p1.vertex > p2.vertex;
        return p1.weight > p2.weight;
    }
};

template <typename T, typename U>
class Graph{

    
    int sz;
    // vector<Node<T>*> lists; // to hold rear elements of heads
    // vector<Node<T>*> heads;

    map<T, list<pair<T, U>> > heads;

    vector<vector<int>> adjacency_matrix;
    unordered_map<T, bool> visited;
    // typename list<T>::iterator it;

    // we need a priority queue to get the next smallest weight that is not connected 
    // or we can make a heap
    priority_queue<VertexEdgePair<T, U>, vector<VertexEdgePair<T, U>>, CompareWeights<T, U>> sorted_weights; 

public:


    Graph() : sz(0) { }

    // n nodes/ vertices
    Graph(int v, vector<T>& vertices){
        sz = v;
        pair<T, U> tmp;

        for(int i = 0; i < sz; i++){
            tmp = {vertices[i], 0};
            heads[vertices[i]].push_back(tmp);
        }
        
    }


    void add_edge(T ver, T edge, U weight){

        VertexEdgePair<T, U> pr = {ver, edge, weight};
        pair<T, U> tmp = {edge, weight};

        sorted_weights.push(pr);

        heads[ver].push_back(tmp);
        heads[edge].push_back(tmp);
        
        return;
    }

    void print_graph_representation(){
        list<pair<T, U>> tmp;

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for(pair<T, list<pair<T, U>> > key : heads){
            tmp = key.second;

            for(auto it = tmp.begin(); it != tmp.end(); it++){
                cout << it->first << " -> ";
            }
            cout << " NULL \n";

        }
        cout << '\n';
    }
    

    void kruskals(){
               
        set<T> addedVertex;
        set<VertexEdgePair<T, U>> addedEdges;
        VertexEdgePair<T, U> tmp;

        while(addedEdges.size() < sz - 1){
            tmp = sorted_weights.top();
            sorted_weights.pop();
            
            if(addedVertex.find(tmp.vertex) != addedVertex.end()){
                addedVertex.insert(tmp.vertex);
                addedEdges.insert(tmp);

                cout << tmp.vertex << " ---- " << tmp.edge << " costs " << tmp.weight << '\n';

            }else if (addedEdges.find(tmp) != addedEdge.end()){
                addedVertex.insert(tmp.vertex);
                
            }
        }
    }
};


int main(){
    
    vector<char> ver = {'A', 'B', 'C', 'D', 'E'};


    Graph<char, int> graph_ll(ver.size(), ver);

    graph_ll.add_edge('A', 'B', 10);
    graph_ll.add_edge('A', 'C', 3);
    graph_ll.add_edge('B', 'C', 4);
    graph_ll.add_edge('B', 'D', 2);
    graph_ll.add_edge('C', 'D', 8);
    graph_ll.add_edge('C', 'E', 2);
    graph_ll.add_edge('D', 'E', 7);


    graph_ll.print_graph_representation();
    graph_ll.kruskals();

    return 0;
}