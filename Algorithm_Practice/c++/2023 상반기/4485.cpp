#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board, shortest;
vector<vector<bool>> visited;
int answer;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

bool verify(int r, int c, int n){
    if(r<0 || r>=n || c<0 || c>=n){
        return false;
    }
    return true;
}

//dfs로 풀면 시간 초과
/*
void dfs(int n, int r, int c, int rupee){

    if(r==n-1 && c==n-1){
        answer = min(answer, rupee);
        return;
    }
    
    for(int i=0; i<4; i++){
        int nextR = r+dr[i];
        int nextC = c+dc[i];

        if(!verify(nextR, nextC, n) || visited[nextR][nextC]){
            continue;
        }

        int nextRupee = rupee+board[nextR][nextC];
        if(nextRupee>answer){
            return;
        }

        visited[nextR][nextC] = true;
        dfs(n, nextR, nextC, nextRupee);
        visited[nextR][nextC] = false;

    }
}
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, idx=0;

    while(cin>>n){
        answer = 1000000000;

        if(n==0){
            return 0;
        }

        board.assign(n, vector<int>(n, 0));
        shortest.assign(n, vector<int>(n, 1000000000));
        visited.assign(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>board[i][j];
            }
        }

        //다익스트라: 왼쪽에서 더해질 때, 오른쪽에서 더해질 때, 위쪽에서 더해질 때, 아래쪽에서 더해질 때 고려해서 최솟값 갱신
        shortest[0][0] = board[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    if(verify(i+dr[k], j+dc[k], n)){
                        shortest[i+dr[k]][j+dc[k]] = min(shortest[i][j]+board[i+dr[k]][j+dc[k]], shortest[i+dr[k]][j+dc[k]]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    if(verify(i+dr[k], j+dc[k], n)){
                        shortest[i+dr[k]][j+dc[k]] = min(shortest[i][j]+board[i+dr[k]][j+dc[k]], shortest[i+dr[k]][j+dc[k]]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    if(verify(i+dr[k], j+dc[k], n)){
                        shortest[i+dr[k]][j+dc[k]] = min(shortest[i][j]+board[i+dr[k]][j+dc[k]], shortest[i+dr[k]][j+dc[k]]);
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<4; k++){
                    if(verify(i+dr[k], j+dc[k], n)){
                        shortest[i+dr[k]][j+dc[k]] = min(shortest[i][j]+board[i+dr[k]][j+dc[k]], shortest[i+dr[k]][j+dc[k]]);
                    }
                }
            }
        }

        
        //dfs(n, 0,0, board[0][0]);
        cout<<"Problem "<<++idx<<": "<<shortest[n-1][n-1]<<'\n';
    }
}