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

using namespace std;

struct VEP {
    char vertex;
    char edge;
    int weight;

    VEP() { }

    VEP(char ver, char edg, int wei) {
        vertex = ver;
        edge = edg;
        weight = wei;
    }

};

bool cmp(VEP p1, VEP p2) {
    if (p1.weight == p2.weight)
        return p1.vertex < p2.vertex;
    return p1.weight < p2.weight;
}

struct cmp_VEP{
    bool operator() (VEP p1, VEP p2) {
        if (p1.weight == p2.weight)
            return p1.vertex > p2.vertex;
        return p1.weight > p2.weight;

    }
};


struct DisjointSet{
    char *parent;
    int *rank;
    int n;

    DisjointSet(){ }

    DisjointSet(int sz){
        n = sz;

        parent = new char[n + 1];
        rank = new int[n + 1];

        // initially all vertices are different sets and rank is 0
        for(int i = 0; i < n; i++){
            rank[i] = 0;

            // every element is parent of itself
            parent[i] = i + 'A';
        }
    }

    int get_index(char el){
        return el - 'A';
    }


    // get parent of u
    char find(char u){
        if(u != parent[get_index(u)]){
            parent[get_index(u)] = find(parent[get_index(u)]);
        }
        return parent[get_index(u)];
    }

    void merge(char x, char y){
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


class Graph {
    int sz;

    map<char, vector<pair<char, int>> > heads;
    unordered_map<char, bool> visited;
    vector<VEP> weights;

public:


    Graph() : sz(0) { }


    void add_edge(char ver, char edge, int weight) {

        VEP pr = { ver, edge, weight };

        weights.push_back(pr);

        if(heads.find(ver) == heads.end())
            sz++;
        
        if(heads.find(edge) == heads.end())
            sz++;
        
        heads[ver].push_back({edge, weight });
        heads[edge].push_back({ver, weight});
    }


    void print_graph_representation() {

        cout << "\nThe adjacency link list representation of graph is :: \n";
        for (auto key : heads) {
            cout << key.first << " -> ";

            for (pair<char, int> it : key.second) {
                cout << it.first << " -> ";
            }
            cout << " null \n";

        }
        cout << '\n';
    }


    void kruskals() {
        int min_cost = 0;

        sort(weights.begin(), weights.end(), cmp);

        //create disjoint sets
        DisjointSet sets(sz);
        
        char u, v;
        char set_u, set_v;

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

        cout << "\nMinimum Spanning Tree traversal cost using Kruskals is = " << min_cost << "\n\n";
    }
    
    void prims(char ver){       
        VEP pop_elm;
        int min_cost = 0;
        char y;
        bool flag = 0;

        priority_queue<VEP, vector<VEP>, cmp_VEP > pri_qu;

        pri_qu.emplace(ver, ver, 0);

        visited.clear();
        
        cout << "\n";

        while(!pri_qu.empty()){
            pop_elm = pri_qu.top();
            pri_qu.pop();
            ver = pop_elm.edge;
            flag = 0;


            if(visited.find(ver) != visited.end()){
                continue;
            }

            cout << pop_elm.vertex << " --- " << pop_elm.edge << " costs " << pop_elm.weight << "\n";
            
            min_cost += pop_elm.weight;

            visited[ver] = 1;

            for(int i = 0; i < heads[ver].size(); i++){
                y = heads[ver][i].first;

                if(visited.find(y) == visited.end()){
                    pri_qu.emplace(ver, y, heads[ver][i].second);

                }
            }

        }

        cout << "\nMinimum Spanning Tree traversal cost using prims is = " << min_cost << "\n\n";
    }
};


int main() {

    char ch;

    Graph graph_ll;

    graph_ll.add_edge('A', 'B', 10);
    graph_ll.add_edge('A', 'C', 3);
    graph_ll.add_edge('B', 'C', 4);
    graph_ll.add_edge('B', 'D', 2);
    graph_ll.add_edge('C', 'D', 8);
    graph_ll.add_edge('C', 'E', 2);
    graph_ll.add_edge('D', 'E', 7);


    graph_ll.print_graph_representation();
    cout << "-------------------------\nApplying Kruskals algorithm on graph : \n";
    graph_ll.kruskals();

    cout << "\n-----------\nPrims algo starting from vertex E: \n";
    graph_ll.prims('E');

    return 0;
}