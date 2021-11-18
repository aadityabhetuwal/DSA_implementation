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
#include <functional>
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

template<typename T>
bool cmp(VertexEdgePair<T>& p1, VertexEdgePair<T>& p2) {
    if (p1.weight == p2.weight)
        return p1.vertex < p2.vertex;
    return p1.weight < p2.weight;
}

template <typename T>
struct compare_VertexEdgePair{
    bool operator() (VertexEdgePair<T>& p1, VertexEdgePair<T>& p2) {
        if (p1.weight == p2.weight)
            return p1.vertex > p2.vertex;
        return p1.weight > p2.weight;

    }
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
            parent[i] = i;
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

    map<T, vector<pair<T, int>> > heads;

    vector<vector<int>> adjacency_matrix;
    unordered_map<T, bool> visited;

    // we need a list to hold all vertex edge pairs
    vector<VertexEdgePair<T>> weights;

public:

    Graph() : sz(0) { }


    void add_edge(T ver, T edge, int weight) {

        VertexEdgePair<T> pr = { ver, edge, weight };

        weights.push_back(pr);

        if(heads.find(ver) == heads.end())
            sz++;
        
        if(heads.find(edge) == heads.end())
            sz++;
        
        heads[ver].emplace_back( edge, weight);
        heads[edge].emplace_back(ver, weight);

        return;
    }

    void print_graph_representation() {

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for (pair<T, vector<pair<T, int>> > key : heads) {
            cout << key.first << " -> ";

            for (pair<T, int> it : key.second) {
                cout << it.first << " -> ";
            }
            cout << " NULL \n";

        }
        cout << '\n';
    }


    void kruskals() {
        int min_cost = 0;

        sort(weights.begin(), weights.end(), cmp<T> );

        //create disjoint sets
        DisjointSet<T> sets(sz);
        
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

        cout << "MInimum Spanning tree according to Kruskals algorithm has cost = " << min_cost << "\n\n";
    }
    
    void prims(T ver){       
        typedef VertexEdgePair<T> VEP;
        VEP low_wt;
        int min_cost = 0;
        T y;
        bool flag = 0;


        priority_queue<VEP, vector<VEP>, compare_VertexEdgePair<T> > qu;

        qu.emplace(ver, ver, 0);

        visited.clear();
        
        cout << "\n";
        
        while(!qu.empty()){
            low_wt = qu.top();
            qu.pop();
            ver = low_wt.edge;
            flag = 0;


            if(visited.find(ver) != visited.end()){
                continue;
            }

            cout << low_wt.vertex << " --- " << low_wt.edge << " costs " << low_wt.weight << "\n";
            
            min_cost += low_wt.weight;

            visited[ver] = 1;

            for(int i = 0; i < heads[ver].size(); i++){
                y = heads[ver][i].first;

                if(visited.find(y) == visited.end()){
                    qu.emplace(ver, y, heads[ver][i].second);

                }
            }

        }

        cout << "\nMinimum Cost of tree using Prim's Algorithm is = " << min_cost << "\n\n";
    }
};


int main() {

    int ver;

    Graph<int> gh;

    // graph_ll.add_edge('A', 'B', 10);
    // graph_ll.add_edge('A', 'C', 3);
    // graph_ll.add_edge('B', 'C', 4);
    // graph_ll.add_edge('B', 'D', 2);
    // graph_ll.add_edge('C', 'D', 8);
    // graph_ll.add_edge('C', 'E', 2);
    // graph_ll.add_edge('D', 'E', 7);

    gh.add_edge(0, 1, 4);
    gh.add_edge(0, 7, 8);
    gh.add_edge(1, 2, 8);
    gh.add_edge(1, 7, 11);
    gh.add_edge(2, 3, 7);
    gh.add_edge(2, 5, 4);
    gh.add_edge(2, 8, 2);
    gh.add_edge(3, 4, 9);
    gh.add_edge(3, 5, 14);
    gh.add_edge(4, 5, 10);
    gh.add_edge(5, 6, 2);
    gh.add_edge(6, 8, 6);
    gh.add_edge(6, 7, 1);
    gh.add_edge(7, 8, 7);



    gh.print_graph_representation();
    cout << "-------------------------\nApplying Kruskals algorithm on graph : \n";
    gh.kruskals();

    cout << "---------------------\nEnter vertex to start Prims algorithm from : ";
    cin >> ver;

    gh.prims(ver);

    return 0;
}