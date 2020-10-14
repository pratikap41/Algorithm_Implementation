//Dijkstra's Algorithm

#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

//function for finding min distance point
int minDist(int V, int * value, bool * visited){
    int min_value = INT_MAX, min_index;
    for(int i=0; i<V; i++){
        if(value[i]<=min_value && !visited[i]){
            min_value = value[i];
            min_index = i;
        }
    }
    return min_index;
}

//Djkstra Algorithm
void dijkstra(int ** graph, int V, int E) {
    bool visited[V];
    int value[V];
    for(int i=0; i<V; i++){
        visited[i]=false;
        value[i]=INT_MAX;
    }
    int start_pt;
    cout<<"Enter Starting Vertex : ";
    cin>>start_pt;
    value[start_pt-1] = 0;
    for(int i=0; i<V; i++){
        int u = minDist(V, value, visited);
        visited[u] = true;
        for(int v=0; v<V;v++){
            if( value[u]!=INT_MAX && !visited[v] && graph[u][v] && value[v]>=value[u]+graph[u][v]){
                value[v] = value[u]+graph[u][v];
            } 
        }
    }
    for(int i=0; i<V; i++){
        cout<<value[i]<<" ";
    }
    
}

int main(){
    int V, E;
    cout<<"Enter Number Of Vertices : ";
    cin>>V;
    cout<<"Enter Number Of Edges : ";
    cin>>E;
    int **graph = new int*[V];
    // set all element of matrix to 0
    for(int i=0; i<V; i++){
        graph[i]= new int[V];
        for(int j=0; j<V; j++){
            graph[i][j]=0;
        }
    }
    //taking edge input in graph
    for(int i=0; i<E; i++){
       int start, end, weight;
       cout<<"Enter Start Vertex of Edge : ";
       cin>>start;
       cout<<"Enter End Vertex of Edge : ";
       cin>>end;
       cout<<"Enter Weight of Edge : ";
       cin>>weight;
       graph[start-1][end-1] = weight;
       graph[end-1][start-1]= weight;
    }
    dijkstra(graph,V,E);
    return 0;
}

