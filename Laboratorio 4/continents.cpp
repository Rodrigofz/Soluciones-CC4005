#include <bits/stdc++.h>
using namespace std;

int main(){
	int M,N;
	while(cin>>M>>N){
		map<int, int> mapa;
		vector<vector<int> > world(M+1, vector<int>(N+1, 0));
		int count_continent = 1;
		for(int i=1; i<M+1; i++){
			string line;
			cin>>line;
			for(int k=0; k<N; k++){
				int j = k+1;
				if(line[k] == 'w'){
					world[i][j] = 0;
				}
				else{
					int w = world[i-1][j];
					int z = world[i][j-1];
					if(w != 0 && z != 0 && w != z){
						int chosen = min(world[i-1][j], world[i][j-1]);
						int not_chosen = max(world[i-1][j], world[i][j-1]);
						world[i][j]=chosen;
						mapa[chosen] = mapa[chosen] + mapa[not_chosen] + 1;
						mapa.erase(not_chosen);
						count_continent--;
					}
					else if(w != 0){
						world[i][j] = w;
						mapa[world[i][j]]++;
					}
					else if(z != 0){
						world[i][j] = z;
						mapa[world[i][j]]++;
					}
					else{
						world[i][j] = count_continent;
						mapa[world[i][j]]++;
						count_continent++;
					}
				}
			}
		}
		
		int x,y;
		cin>>x>>y;
		mapa[world[x+1][y+1]]=-1;
		vector<int> check;
		for(int i=1; i<N; i++){
			if (world[i][1]!=0 && world[i][N]!=0 && find(check.begin(), check.end(), world[i][1])==check.end() && find(check.begin(), check.end(), world[i][N])==check.end()) 	{
				if (mapa[world[i][1]]==-1 || mapa[world[i][N]]==-1){
					mapa[world[i][1]]=-1;
					mapa[world[i][N]]=-1;
				}
				else{
					check.push_back(world[i][1]);
					check.push_back(world[i][N]);
					mapa[world[i][1]]+=mapa[world[i][N]];
					mapa[world[i][N]]=mapa[world[i][1]];
				}
			}
		}

		int maxim=0;
		for (int i=1; i<count_continent; i++){
			maxim=max(maxim,mapa[i]);
		}
		
		cout<<maxim<<"\n";
			
	}
}
