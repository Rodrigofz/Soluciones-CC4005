#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > graph;
graph G;
int tarjan_time;
vector<int> disc,low;
stack<int> S;
vector<bool> inStack;
vector<vector<int> > SCC;

void tarjan(int u){
	disc[u] = low[u] = tarjan_time++;
	S.push(u);
	inStack[u] = true;


	for(int v : G[u])
	{
		if(disc[v] == -1)
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}

		else if(inStack[v]) low[u] = min(low[u],disc[v]);
	}

	if(low[u] == disc[u])
	{
        SCC.emplace_back();
		while(S.top() != u)
		{
			int v = S.top(); S.pop();
			SCC.back().push_back(v);
			inStack[v] = false;
		}
		S.pop();
		SCC.back().push_back(u);
		inStack[u] = false;
	}
}

int main(){
    int n, m;
    while(cin>>n>>m){
        if(n==0 && m==0){
            break;
        }
        vector<vector<int> > g(n);
        map<int, string> num_name;
        map<string, int> name_num;
        int counter = 0;

        for(int i=0; i<m; i++){
            string name1, name2;
            cin>>name1>>name2;
            int num1, num2;
            
            if(name_num[name1]){
                num1 = name_num[name1];
            }
            else{
                num1 = counter;
                num_name[num1] = name1;
                name_num[name1] = num1;
                counter++;
            }

            if(name_num[name2]){
                num2 = name_num[name2];
            }
            else{
                num2 = counter;
                num_name[num2] = name2;
                name_num[name2] = num2;
                counter++;
            }
            g[num1].push_back(num2);
        } 

        for(vector<int> v : g){
            cout<<"New vector:\n";
            for(int i : v){
                cout<<i<<"\t";
            }
            cout<<"\n";
        }

        G = g;
        tarjan_time = 0;
        disc.assign(n,-1);
	    low.assign(n,-1);
        while(!S.empty()) S.pop();
	    inStack.assign(n,false);
	    SCC.clear();

        // Si el nodo no esta visitado, utilizar tarjan
        for(int u = 0; u < n; ++u)
            if(disc[u] == -1)
                tarjan(u);

        int k = 1;
        for(vector<int> &C : SCC)
        {
            cout << "La " << k++ << "-esima componente conexa es: ";
            for(int u : C) cout << u << ' ';
            cout << '\n';
        }
    }
}

