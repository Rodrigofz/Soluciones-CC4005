#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// Algoritmo para obtener un orden topológico
// en un grafo dirigido sin ciclos (DAG)

vvi adj; // Lista de adyacencia del grafo
vi vis; // Arreglo de visitados para dfs
vi ans; // Arreglo donde se guarda el orden topológico de los nodos

vector<string>  color;
color.push_back("blanco");
color.push_back("negro");
color.push_back("rojo");
void topo_sort(int v) {
    vis[v] = 1;
    for (int i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (!vis[to]) topo_sort(to);

    }
    ans.push_back(v); // es un dfs modificado, solo basta agregar esta linea
}
//https://www.geeksforgeeks.org/detect-cycle-direct-graph-using-colors/

//ve si hay ciclo segun la lista de adyacencia
//dfs
//para cada nodo visitado "v", ve si hay un nodo adyacente "u", tal que u ya fue visitado y NO es padre de v --> ciclo


int main() {
    int n, m;
    cin >> n >> m; // num de nodos y aristas

    // se lee la lista de adyacencia
    adj = vvi(n+1);
    vis = vi(n+1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = n; i > 0; i--) {
        if (!vis[i]) {
            topo_sort(i);
        }
    }
    //ver si hay ciclo
    if(hayciclo(adj)){
    	cout<<"Sandro fails"<<"\n";
    }
    else{
    	// terminado el loop, ans tiene el orden en reversa
	    reverse(ans.begin(), ans.end());
	    for (int i = 0; i < n; ++i) cout << ans[i]<< " ";
	    cout << "\n";
}
    

}
