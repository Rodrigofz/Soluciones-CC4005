    #include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;

typedef vector<int> vi;


void Dijsktra(int s, wgraph &M, vector<long long> &dist, vi &p) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		int d = front.first, u = front.second;
		if (d > dist[u]) continue;
		
		//cout << u+1 << endl;

		for (int j = 0; j < M[u].size(); j++) {
			ii v = M[u][j];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));

				p[v.second] = u;
			}
		}
	}
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<long long> dists(n+1, LLONG_MAX);
    int s = 1;
    wgraph graph(n+1);
    vector<int> p(n+1, 0);

    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;

        graph[a].push_back(pair<int, int>(w, b));
        graph[b].push_back(pair<int, int>(w, a));
    }

    Dijsktra(s, graph, dists, p);

    int i = n;
    vector<int> path;
    while (p[i]!=0){
        path.push_back(i);
        i = p[i];
    }

    if(path.size() == 0)
        cout<<-1<<"\n";
    else{
        cout<<1<<" ";
        for(int j=path.size()-1; j>=0; j--){
            cout<<path[j]<<" ";
        }
        cout<<"\n";
    } 
}