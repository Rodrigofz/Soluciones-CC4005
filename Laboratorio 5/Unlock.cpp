#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

vector<int> visit_bfs(map<int, vector<int> > graph, int s){
    int N = graph.size();    
    queue<int> q;
    vector<int> dist(N, -1);
    dist.assign(10000, -1);
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i : graph[u]){
            if(dist[i] == -1){
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }

    return dist;
}

void visit(int ini, int fin, vector<int> buttons, map<int, vector<int> > &graph){
    for(int i=0; i<buttons.size(); i++){
        int b = buttons[i];
        if((ini + b)%10000 == fin){
            graph[ini].push_back(fin);//Creamos arista
            return; //Y retornamos
        }
        //Crear arista
        if(find(graph[ini].begin(), graph[ini].end(), (ini + b)%10000) != graph[ini].end()){
            return;
        }
        graph[ini].push_back((ini + b)%10000);
        visit((ini + b)%10000, fin, buttons, graph);
    }
}

int main(){
    int ini, fin, butt;
    int caso = 1;

    while(cin>>ini>>fin>>butt){
        if(ini==0 && fin==0 && butt==0){
            break;
        }
        vector<int> buttons(butt);
        map<int, vector<int> > graph;
        for(int i=0; i<butt; i++){
            int button;
            cin>>button;
            buttons[i] = button;
        }
        visit(ini, fin, buttons, graph);
        vector<int> dists = visit_bfs(graph, ini);
        int value = dists[fin];
        if(value == -1){
            cout<<"Case "<<caso<<": "<<"Permanently Locked\n";
        }
        else{
            cout<<"Case "<<caso<<": "<<value<<"\n";
        }
        caso++;
    }
  
}
