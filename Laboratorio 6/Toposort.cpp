#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// Algoritmo para obtener un orden topológico
// en un grafo dirigido sin ciclos (DAG)

vvi adj; // Lista de adyacencia del grafo
vi vis; // Arreglo de visitados para dfs
vvi topo;
vi ans; // Arreglo donde se guarda el orden topológico de los nodos

void topo_sort(int v) {
    vis[v] = 1;
    for (int i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (!vis[to]) topo_sort(to);
    }
    ans.push_back(v); // es un dfs modificado, solo basta agregar esta linea
}

int main() {
    int n, m;
    while(cin >> n){ // num de nodos y aristas
        adj = vvi(n);
        vis = vi(n,0);
        if(n!=0){
            for(int i=0; i<n;i++){
        	    // se lee la lista de adyacencia
        	    cin>>m;
        	    for (int j = 0; j < m; ++j) {
        	        int a;
        	        cin >> a;
        	        adj[i].push_back(a);
        	    }
        	}
            for (int i = 0; i < n; ++i) {
                if (!vis[i]) {
                    topo_sort(i);
                }
            }
            vi dp(ans.size(),1);
            for(int i=0; i<ans.size(); i++){
                int aux=ans[i];
                if (adj[aux].size()!=0){
                    dp[aux]=0;
                    for(int j=0; j<adj[aux].size(); j++){
                        dp[aux]=dp[aux]+dp[adj[aux][j]];
                    }
                }
            }
            cout<<dp[0];
            cout<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
}
