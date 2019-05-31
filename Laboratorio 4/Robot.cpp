#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, p;
    cin>>n>>m>>p;
    while(n!=0&&m!=0&&p!=0){
        vector<vector<char> > matrix(n, vector<char>(m));
        vector<vector<int> > path_matrix(n, vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                char val;
                cin>>val;
                matrix[i][j] = val;
            }
        }
        int run = 1;
        int x = 0;
        int y = p-1;
        char val = matrix[x][y];
        path_matrix[x][y] = 1;
        int steps = 1;
        int loop_count = 0;
        while(run){
            if(val == 'N')
                x--;
            if(val == 'S')
                x++;
            if(val=='W')
                y--;
            if(val=='E')
                y++;

            if(x<0||y<0||x==n||y==m){
                cout<<steps<<" step(s) to exit\n";
                run = 0;
                continue;
            }
            char new_val = matrix[x][y];
            if(path_matrix[x][y] == 2){
                cout<<steps-2*loop_count<<" step(s) before a loop of "<<loop_count<<" step(s)\n";
                run = 0;
                continue;
            }
            if(path_matrix[x][y] == 1){
                path_matrix[x][y] = 2;
                loop_count++;

            }
            if(path_matrix[x][y] == 0){
                path_matrix[x][y] = 1;
            }
            val = matrix[x][y];
            steps++;

        }
        cin>>n>>m>>p;
    }
}