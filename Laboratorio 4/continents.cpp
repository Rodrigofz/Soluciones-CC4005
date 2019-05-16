continents.cpp
#include <bits/stdc++.h>
using namespace std;

int main{
	int M,N;
	cin>>M>>N;
	map<int, int> mapa;
	vector<vector<int> > world(M+1, vector<int>(N+1, 0));
	int count_continent = 1;
	for(int i=1; i<M+1; i++){
		string line;
		getline(cin, line);

		for(int j=1; j<N+1; j++){
			char c = line[j];
			if(c == "w"){
				world[i][j] = 0;
			}
			else{
				if(world[i-1][j] != 0 && world[i][j-1] != 0){
					int chosen = min(world[i-1][j], world[i][j-1]);
					int not_chosen = max(world[i-1][j], world[i][j-1]);
					mapa[chosen] = mapa[chosen] + mapa[not_chosen] + 1;
					mapa.erase(not_chosen);
				}
				else if(world[i-1][j] != 0){
					world[i][j] = world[i-1][j];
					mapa[world[i][j]]++;
				}
				else if(world[i][j-1] != 0){
					world[i][j] = world[i][j-1];
					mapa[world[i][j]]++;
				}
				else{
					world[i][j] = count_continent;
					count_continent++;
				}
			}
		}
	}

	cout<<world[2][2];


}