// Union-find Algorithm to check cycle in the graph
#include<iostream>
using namespace std;

class Edge{
    public:
        int src;
        int dest;
};

class Graph{
    public:
        int V;
        int E;   
        Edge* edge;
  
};

Graph* createGraph(int v, int e){
    Graph* graph = new Graph();
    graph->V = v;
    graph->E = e;
    graph->edge = new Edge[e*sizeof(Edge)];  
    return graph;  
}

void Union(int x, int y, int* set){
    set[x]=y;
}

int find(int index, int* set){
    if(set[index]==-1){
        return index;
    }
    return find(set[index],set);
}


bool isCycle(Graph* graph){
    int* set = new int[graph->V];
    for(int i=0;i<graph->V;i++){
        set[i]=-1;
    }
    for(int i=0;i<graph->E;i++){
        int x = find(graph->edge[i].src - 1 ,set);
        int y = find(graph->edge[i].dest - 1 ,set);
        if(x==y){
            return true;
        }
        Union(x, y, set);
    }
    return false;
}

int main(){
    int v,e;
    cout<<"Enter Number of Vertex : ";
    cin>>v;
    cout<<"Enter Number OF Edges : ";
    cin>>e;
    Graph * graph = createGraph(v,e);
    for(int i=0; i<e; i++){
        cout<<"Enter Strating point : ";
        cin>>graph->edge[i].src;
        cout<<"Enter End point : ";
        cin>>graph->edge[i].dest;
    }
    cout<<boolalpha<<isCycle(graph);

}