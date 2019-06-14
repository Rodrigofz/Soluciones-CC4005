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

int createGraph(int node, wgraph &graph, int dest, vi moves){
	cout<<"entre a create";
	int currentNode=node;
    vector<int> nodes(8);
    nodes[0]=node;
    while(find(nodes.begin(),nodes.end(),dest)==nodes.end()){
    	for(int j; j<8; j++){
		    for(int i=0; i<8; i++){
		    	vii vecinos = graph[currentNode];
			    int f=currentNode+moves[i];
		    	if (f>=0){
		   		    int w=currentNode%8*f%8+currentNode/8*f/8;
   		    		ii r = make_pair(w,f);
   		    		cout<<w<<"\t"<<f<<"\n";
		   		    if(find(vecinos.begin(),vecinos.end(),r)==vecinos.end()){
			    		graph[currentNode].push_back(pair<int,int>(w, f));
			    		cout<<"se agrego nodo "<<currentNode<<" "<<f;
		   		    }
		    	}
		    	nodes[i]=f;
		    }
		}
	}
	for (int i = 0; i < 8; ++i)
	{
		createGraph(nodes[i],graph, dest, moves);
	}
	return 0;
}

int main(){
	int a,b,c,d;
    cin>>a>>b>>c>>d;

    vector<long long> dists(64, LLONG_MAX);
    int s = b*8+a;
    int dest = d*8+c;
    wgraph graph(64);
    vector<int> p(64, -1);
    vector<int> moves;
    moves.push_back(-15);
    moves.push_back(-17);
    moves.push_back(-6);
    moves.push_back(10);
    moves.push_back(-10);
    moves.push_back(6);
    moves.push_back(17);
    moves.push_back(15);
    int x= createGraph(s,graph,dest,moves);
	Dijsktra(s,graph,dists,p);
	cout<<dists[dest]<<"\n";	

}
