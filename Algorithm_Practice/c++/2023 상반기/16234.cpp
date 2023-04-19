#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//1. 인구 이동이 필요한지 먼저 조사
//2. bfs로 연합 만들고 인구 조정
//인구 이동이 필요하지 않을 때까지 반복

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

bool verify(int x, int y, int n){
    if(x<0 || x>=n || y<0 || y>=n){
        return false;
    }
    return true;

}

bool needMoving(vector<vector<int>> &board, int l, int r){
    int n = board.size();
    bool flag = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int nextR = i+dr[k];
                int nextC = j+dc[k];

                if(verify(nextR, nextC, n) && l<=abs(board[i][j]-board[nextR][nextC]) && abs(board[i][j]-board[nextR][nextC])<=r){
                    flag = true;
                    return flag;
                }
            }
        }
    }

    return flag;
}

int main(){
    vector<vector<int>> board;
    vector<vector<bool>> visited;
    queue<pair<int, int>> pos;
    int n, l, r, answer=0;

    cin>>n>>l>>r;

    board.assign(n, vector<int>(n,0));
    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    while(needMoving(board, l, r)){

        answer++;
        visited.assign(n, vector<bool>(n, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(visited[i][j]){
                    continue;
                }

                visited[i][j] = true;
                pos.push({i,j});

                vector<pair<int, int>> tempPos;
                tempPos.push_back({i,j});
                int totalCnt = board[i][j]; //연합의 인구 수
                int totalSize = 1; //연합의 칸 개수

                while(!pos.empty()){
                    int row = pos.front().first;
                    int col = pos.front().second;
                    //cout<<"row: "<<row<<" col: "<<col<<'\n';
                    
                    for(int k=0; k<4; k++){
                    int nextR = row+dr[k];
                    int nextC = col+dc[k];
                    //cout<<" nextR: "<<nextR<<" nextC: "<<nextC<<'\n';

                        if(verify(nextR, nextC, n) && !visited[nextR][nextC] && l<=abs(board[row][col]-board[nextR][nextC]) && abs(board[row][col]-board[nextR][nextC])<=r){
                            //cout<<"i: "<<i<<" j: "<<j<<" people: "<<board[i][j]<<" nextR: "<<nextR<<" nextC: "<<nextC<<" people: "<<board[nextR][nextC]<<'\n';
                            visited[nextR][nextC] = true;
                            totalCnt += board[nextR][nextC];
                            totalSize++;
                            tempPos.push_back({nextR,nextC});
                            pos.push({nextR, nextC});    
                        }
                    }
                    pos.pop();
                }

                //cout<<totalCnt<<' '<<totalSize<<'\n';

                int avgCnt = totalCnt/totalSize;
                for(int k=0; k<tempPos.size(); k++){
                    board[tempPos[k].first][tempPos[k].second] = avgCnt;
                }

                tempPos.clear();

            }
        }
        /*
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<"\n";
        */
    }

    cout<<answer;
    


}