#include <bits/stdc++.h>
using namespace std;

vector<int> visited;

void visit(int ini, int fin, vector<int> buttons, map<int, vector<int> > &graph){
    for(int i=0; i<buttons.size(); i++){
        int b = buttons[i];
        if((ini + b)%10000 == fin){
            cout<<"Creating edge from "<<ini<<" to "<<(ini + b)%10000<<"\n";
            graph[ini].push_back(fin);//Creamos arista
            return; //Y retornamos
        }
        //Crear arista
        cout<<"Creating edge from "<<ini<<" to "<<(ini + b)%10000<<"\n";
        if(find(graph[ini].begin(), graph[ini].end(), (ini + b)%10000) != graph[ini].end()){
            return;
        }
        graph[ini].push_back((ini + b)%10000);
        visit((ini + b)%10000, fin, buttons, graph);
    }
}

int main(){
    int ini, fin, butt;
    cin>>ini>>fin>>butt;
    vector<int> buttons(butt);
    map<int, vector<int> > graph;
    for(int i=0; i<butt; i++){
        int button;
        cin>>button;
        buttons[i] = button;
    }
    visit(ini, fin, buttons, graph);
    cout<<graph[0][0]<<"  "<<graph[0][1];
}
