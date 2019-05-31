#include <bits/stdc++.h>
using namespace std;

int main(){
    int v, a;
    cin>>v>>a;
    map<int, int> colors;
    int nope = 0;
    vector<int> counters(2);

    for(int i=0; i<a; i++){
        int n1, n2;
        cin>>n1>>n2;
        if(colors[n1] == 1||colors[n1] == 2){
            if(colors[n2] && colors[n1] == colors[n2]){
                nope = 1;
            }
            else if(!colors[n2]){
                int color = (1-(colors[n1] - 1))+1;
                colors[n2] = color;
                counters[color-1]++;

            }
            else if(colors[n1] != colors[n2]){
                continue;
            }
        }
        else if(colors[n2] == 1||colors[n2] == 2){
            int color = (1-(colors[n2] - 1))+1;
            colors[n1] = color;
            counters[color-1]++;
        }
        else{
            colors[n1] = 1;
            counters[0]++;
            colors[n2] = 2;
            counters[1]++;
        }

    }

    if(nope){
        cout<<-1;
        return 0;
    }
    vector<int> others;
    cout<<counters[0]<<"\n";
    
    for(map<int, int>::iterator it=colors.begin(); it!=colors.end(); ++it){
		pair<int, int> tuple=*it;
        if(tuple.second == 1){
            cout<<tuple.first<<" ";
        }
	}
    
    cout<<"\n";

    cout<<counters[1]<<"\n";
    int j = 1;
    for(map<int, int>::iterator it=colors.begin(); it!=colors.end(); ++it){
		pair<int, int> tuple=*it;
        if(tuple.second == 2){
            cout<<tuple.first;
        }
        if(j!=counters[1]){
            cout<<" ";
        }
        j++;
	}

}