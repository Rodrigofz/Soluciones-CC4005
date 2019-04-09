#include <bits/stdc++.h>
using namespace std;

int main(){
    string nStr;
    getline(cin, nStr);
    int n = stoi(nStr);

    vector<int> values(n);
    for(int i=0; i<n; i++){
        char a;
        int count;
        cout<<a;
        while(a!='\n'){
            if(a==')'){
                count--;
            }
            else if(a=='('){
                count++;
            }
            cout<<a;
        }
        cout<<count;
        /*
        string readBrackets;
        getline(cin, readBrackets);
        int lefties = count(readBrackets.begin(), readBrackets.end(), '(');
        int righties =  count(readBrackets.begin(), readBrackets.end(), ')');
        values[i] = righties-lefties;
        cout<<values[i]<<"\n";
        */
    }

}








