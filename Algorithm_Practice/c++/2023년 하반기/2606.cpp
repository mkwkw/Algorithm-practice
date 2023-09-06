#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> board;
vector<bool> visited;
int answer = 0;
void dfs(int i, int n){
    
    visited[i] = true;

    for(int j=1; j<=n; j++){
        if(board[i][j] && !visited[j]){
            dfs(j, n);
            answer++;
        }
    }
}

int main(){
    int n, m;
    
    cin>>n>>m;

    board.assign(n+1, vector<bool>(n+1, false));
    visited.assign(n+1, false);

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        board[a][b] = true;
        board[b][a] = true;
    }

    dfs(1, n);

    cout<<answer;
}