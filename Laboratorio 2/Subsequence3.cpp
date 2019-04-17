#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int, int> largos;
    int n;
    cin>>n;
    vector<int> numbers(n);
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        numbers[i] = a;
        if(largos[a-1]){
            largos[a] = largos[a-1] + 1;
        }
        else{
            largos[a] = 1;
        }
    }
    int biggest = 0;
    int key = 0;

    for(map<int, int>::iterator it=largos.begin(); it!=largos.end(); ++it){
		pair<int, int> tupla=*it;
        if(tupla.second > biggest){
            biggest = tupla.second;
            key = tupla.first;
        }
	}
    cout<<biggest<<"\n";
    int searched = key - biggest + 1;

    for(int i=0; i<n; i++){
        if(numbers[i] == searched){
            cout<<i+1<<" ";
            searched++;
        }
    }

}