#include <bits/stdc++.h>
using namespace std;


vector<int> visit_bfs(map<int, vector<int> > graph, int s){
    int N = graph.size();    
    queue<int> q;
    vector<int> dist(N, -1);
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

    int max_dist = 0;
    int lejanest = -1;

    for(int i=0; i<N; i++){
        if(dist[i] > max_dist){
            max_dist = dist[i];
            lejanest = i;
        }
    }
    vector<int> to_return(2);
    to_return[0] = lejanest;
    to_return[1] = max_dist;
    return to_return;
}


int main(){
    int N;
    cin>>N;
    map<int, vector<int> > graph;
    for(int i=0; i<N-1; i++){
        int u, v;
        cin>>u>>v;
        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    vector<int> lejanest1 = visit_bfs(graph, 0);
    vector<int> lejanest2 = visit_bfs(graph, lejanest1[0]);

    cout<<lejanest2[1]<<"\n";

}