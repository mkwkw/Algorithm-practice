#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4]={-1,1,0,0};
int dc[4]={0,0,1,-1};

bool verify(int r, int c, int n, int m){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }
    return true;
}

int main(){
    vector<vector<int>> board;
    vector<vector<bool>> visited;
    queue<pair<int, int>> pos;
    int n, m, destR, destC;

    cin>>n>>m;

    board.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j]==2){
                destR = i;
                destC = j;
            }
        }
    }

    //갈 수 없는 위치:0, 갈 수 있는 위치:1, 목적지:2
    //2의 좌표에서 시작 - bfs
    board[destR][destC] = 0;
    visited[destR][destC]=true;
    pos.push({destR, destC});

    while(!pos.empty()){
        
        int r = pos.front().first;
        int c = pos.front().second;
        int dist = board[r][c];

        for(int i=0; i<4; i++){
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if(!verify(nextR, nextC, n, m) || visited[nextR][nextC] || board[nextR][nextC]==0){
                continue;
            }
            //cout<<"nextR: "<<nextR<<" nextC: "<<nextC<<'\n';
            board[nextR][nextC] = dist+1;
            visited[nextR][nextC] = true;
            pos.push({nextR, nextC});

        }
        pos.pop();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            
            //도달하지 못하는 곳 판별
            if(!visited[i][j] && board[i][j]==1){
                board[i][j]=-1;
            }
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }

}