#include <iostream>
#include <vector>
#include <cmath>

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
class AdjacencyList{

public:
    int sz;
    vector<Node<T>*> lists; // to hold rear elements of heads
    vector<Node<T>*> heads;
    vector<vector<int>> adjacency_matrix;

    AdjacencyList() : sz(0) { }

    // n nodes/ vertices
    AdjacencyList(int v, vector<int>& vertices){
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

        // while(currVer->next){
        //     currVer = currVer->next;
        // }
        currVer->next = new Node<T>(edge);
        currVer = currVer->next;
        lists[ind1] = currVer;

        // while(currEdge->next){
        //     currEdge = currEdge->next;
        // }
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
};


int main(){
    int n;
    cout << "Enter number of edges (0 to n - 1) :: ";
    cin >> n;

    vector<int> vertices(n);

    for(int i = 0; i < n; i++){
        vertices[i] = i;
    }

    AdjacencyList<int> graph_ll(n, vertices);

    graph_ll.add_edge(0, 1);
    graph_ll.add_edge(0, 3);
    graph_ll.add_edge(0, 5);
    graph_ll.add_edge(1, 2);
    graph_ll.add_edge(1, 6);
    graph_ll.add_edge(2, 5);
    graph_ll.add_edge(2, 6);
    graph_ll.add_edge(3, 4);
    graph_ll.add_edge(3, 6);
    graph_ll.add_edge(4, 5);


    graph_ll.print_graph_representation();
    graph_ll.print_matrix_representation();
    
    return 0;
}