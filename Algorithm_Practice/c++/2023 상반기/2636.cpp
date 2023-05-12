#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

bool verifyDistrict(int n, int m, int r, int c){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int>> board;
    vector<vector<bool>> visited;
    queue<pair<int, int>> outsidePos; //녹을 치즈 위치
    int n, m, beforeCheeseCnt = 0, nowCheeseCnt = 0, answer = 0;
    
    cin>>n>>m;

    board.assign(n, vector<int>(m, 0));
    visited.assign(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];

            if(board[i][j]==1){
                nowCheeseCnt++;
            }
        }
    }

    //0따라서 bfs
    while(nowCheeseCnt>0){//치즈의 구멍 판별 - (0,0)은 무조건 외부
        int meltingCnt = 0; //녹을 치즈 개수
        
        visited.assign(n, vector<bool>(m, false));
        
        outsidePos.push({0,0});
        visited[0][0] = true;

        while(!outsidePos.empty()){
            int r = outsidePos.front().first;
            int c = outsidePos.front().second;

            for(int i=0; i<4; i++){
                int nextR = r+dr[i];
                int nextC = c+dc[i];

                if(verifyDistrict(n, m, nextR, nextC) && !visited[nextR][nextC]){
                    //0옆에 0이 있으면 외부 영역이므로 push, 1이 있으면 녹을 치즈이므로 0으로 바꿔줌
                    if(board[nextR][nextC]==0){
                        outsidePos.push({nextR, nextC});
                    }
                    else{
                        board[nextR][nextC]=0;
                        meltingCnt++;
                    }

                    visited[nextR][nextC] = true;
                }
            }

            outsidePos.pop();
        }        

        beforeCheeseCnt = nowCheeseCnt;
        nowCheeseCnt = beforeCheeseCnt - meltingCnt;
        //cout<<answer<<' '<<beforeCheeseCnt<<' '<<nowCheeseCnt<<'\n';

/*
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
*/
        answer++;
    }

    cout<<answer<<'\n'<<beforeCheeseCnt;
}