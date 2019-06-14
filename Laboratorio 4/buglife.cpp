buglife.cpp
#include <bits/stdc++.h>
using namespace std;

//PONE EN UNA LISTA CUALES NODOS HAN SIDO VISITADOS

vector<int> visit_bfs(map<int, vector<int> > graph, int s){
	//s nodo de start
    int N = graph.size();    
    queue<int> q;
    vector<int> dist(N, 0); //marcaremos con 1 cuando el nodo este visitado
    dist[s] = 0;
    q.push(s);
    //guardo los visitados
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i : graph[u]){
        	//los relaciono con los nodos que estan unidos
            if(dist[i] == 0){
                dist[i] = 1;
                q.push(i);
            }

        }
    }

}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int b,t; //bichos, interacciones
		cin>>b>>t;
		vector<vector<int>> grafo (b,vector<int>(b,0)); //matriz llena de 0s
		for(int j=0;j<t;j++){
			int b1,b2;
			cin>>b1>>b2; //bicho 1 con bicho 2
			grafo[b1-1,b2-1]=1;
			grafo[b2-1,b1-1]=1;
		}
		//lista con los visitados. El primero será el primer nodo

	}
}