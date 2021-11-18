#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>
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


template<typename T>
struct VertexEdgePair {
    T vertex;
    T edge;
    int weight;

    VertexEdgePair() { }

    VertexEdgePair(T ver, T edg, int wei) {
        vertex = ver;
        edge = edg;
        weight = wei;
    }

};

template <typename T>
bool cmp(VertexEdgePair<T>& p1, VertexEdgePair<T>& p2) {

    if (p1.weight == p2.weight)
        return p1.vertex < p2.vertex;
    return p1.weight < p2.weight;
};

template <typename T>
struct DisjointSet{
    T *parent;
    int *rank;
    int n;

    DisjointSet(){ }

    DisjointSet(int sz){
        n = sz;

        parent = new T[n + 1];
        rank = new int[n + 1];

        // initially all vertices are different sets and rank is 0
        for(int i = 0; i < n; i++){
            rank[i] = 0;

            // every element is parent of itself
            parent[i] = i + 'A';
        }
    }

    int get_index(T el){
        if(typeid(T) == typeid(char)){
            return el - 'A';
        }
        return el;
    }


    // get parent of u
    T find(T u){
        if(u != parent[get_index(u)]){
            parent[get_index(u)] = find(parent[get_index(u)]);
        }
        return parent[get_index(u)];
    }

    void merge(T x, T y){
        x = find(x);
        y = find(y);

        // make a tree with smaller height which is subtree of other tree
        if(rank[get_index(x)] > rank[get_index(y)] ){
            parent[get_index(y)] = x;
        }else{
            parent[get_index(x)] = y;
        }

        if(rank[get_index(x)] > rank[get_index(y)] ){
            rank[get_index(y)]++;
        }
    }
};

template <typename T>
class Graph {


    int sz;
    // vector<Node<T>*> lists; // to hold rear elements of heads
    // vector<Node<T>*> heads;

    map<T, list<pair<T, T>> > heads;

    vector<vector<int>> adjacency_matrix;
    unordered_map<T, bool> visited;
    // typename list<T>::iterator it;

    // we need a priority queue to get the next smallest weight that is not connected 
    // or we can make a heap
    vector<VertexEdgePair<T>> weights;

public:


    Graph() : sz(0) { }

    // n nodes/ vertices
    Graph(int v, vector<T>& vertices) {
        sz = v;
        pair<T, T> tmp;

        for (int i = 0; i < sz; i++) {
            tmp = { vertices[i], 0 };
            heads[vertices[i]].push_back(tmp);
        }

    }

    // cout << typeof(Graph) << '\n';

    void add_edge(T ver, T edge, int weight) {

        VertexEdgePair<T> pr = { ver, edge, weight };
        pair<T, T> tmp = { edge, weight };

        weights.push_back(pr);

        heads[ver].push_back(tmp);
        heads[edge].push_back(tmp);

        return;
    }

    void print_graph_representation() {
        list<pair<T, T>> tmp;

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for (pair<T, list<pair<T, T>> > key : heads) {
            tmp = key.second;

            for (auto it = tmp.begin(); it != tmp.end(); it++) {
                cout << it->first << " -> ";
            }
            cout << " NULL \n";

        }
        cout << '\n';
    }


    void kruskals() {
        int min_cost = 0;

        sort(weights.begin(), weights.end(), cmp<T>);

        //create disjoint sets
        DisjointSet<char> sets(sz);
        
        T u, v;
        T set_u, set_v;

        for(int i = 0; i < weights.size(); i++){
            u = weights[i].vertex;
            v = weights[i].edge;

            set_u = sets.find(u);
            set_v = sets.find(v);

            // check if selected edge is creating a cycle or not
            // if cycle is there u and v belong to same set
            if(set_u != set_v){
                min_cost += weights[i].weight;

                cout << u << " --- " << v << " costs " << weights[i].weight << "\n";

                sets.merge(u, v);
            }
        }

        cout << "Minimum cost tree has traversal cost = " << min_cost << '\n';
    }


    void prims(){
        // create a multiset for easier solving
    }
};


int main() {

    DisjointSet<char> ds(10);


    vector<char> ver = { 'A', 'B', 'C', 'D', 'E' };


    Graph<char> graph_ll(ver.size(), ver);

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