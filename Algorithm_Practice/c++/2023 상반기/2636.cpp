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
    queue<pair<int, int>> outsidePos; //���� ġ�� ��ġ
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

    //0���� bfs
    while(nowCheeseCnt>0){//ġ���� ���� �Ǻ� - (0,0)�� ������ �ܺ�
        int meltingCnt = 0; //���� ġ�� ����
        
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
                    //0���� 0�� ������ �ܺ� �����̹Ƿ� push, 1�� ������ ���� ġ���̹Ƿ� 0���� �ٲ���
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