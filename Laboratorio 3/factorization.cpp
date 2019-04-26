#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> values(n+1,0);
	//criba
	for(int i=2;i<=n;i++){
		if(values[i]==0){
			for(int j=i+i;j<=n;j+=i){
				if(values[j]==0){
					values[j]=i;
				}
			}
		}
	}
	vector<int> factor(k,0);
	int c=n;
	int counter=0;
	while(counter<k-1){
		if(values[c]!=0){ //no es primo
			factor[counter]=values[c];//guardo el factor primo mas chico
			c=c/values[c];//divido por el primo
			counter++;
		}
		else{ //si es primo
			break;
		}
	}

	if(factor[k-2]==0){
		cout<<-1;
	}
	else{
		factor[k-1]=c;
		for(int i=0;i<k;i++){
			cout<<factor[i]<<" ";
		}
	}
	cout<<"\n";
}
		
