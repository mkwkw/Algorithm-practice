#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool verify(int n, int m, int r, int c){
    if(r<0 || c<0 || r>=n || c>=m){
        return false;
    }
    return true;
}

//bfs
//visited
int main(){
    
    vector<vector<char>> board;
    vector<vector<bool>> visited;
    queue<pair<int,int>> pos;
    int dr[4]={1,-1,0,0};
    int dc[4]={0,0,1,-1};
    int n, m, sheepCnt=0, wolfCnt=0;

    cin>>n>>m;

    board.assign(n, vector<char>(m, ' '));
    visited.assign(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        for(int j=0; j<m; j++){
            board[i][j] = str[j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]!='#' && !visited[i][j]){
                pos.push({i,j});
                visited[i][j] = true;
                int tempSheepCnt = 0;
                int tempWolfCnt = 0;

                if(board[i][j]=='o'){
                    tempSheepCnt = 1;
                }
                else if(board[i][j]=='v'){
                    tempWolfCnt = 1;
                }

                while(!pos.empty()){
                    for(int k=0; k<4; k++){
                        int nextR = pos.front().first+dr[k];
                        int nextC = pos.front().second+dc[k];
                        if(verify(n, m, nextR, nextC) && board[nextR][nextC]!='#' && !visited[nextR][nextC]){
                            pos.push({nextR, nextC});
                            visited[nextR][nextC] = true;
                            if(board[nextR][nextC]=='o'){
                                tempSheepCnt++;
                            }
                            else if(board[nextR][nextC]=='v'){
                                tempWolfCnt++;
                            }
                        }
                    }
                    pos.pop();
                }

                if(tempWolfCnt>=tempSheepCnt){
                    wolfCnt += tempWolfCnt;
                }
                else{
                    sheepCnt += tempSheepCnt;
                }
            }
        }
    }    

    cout<<sheepCnt<<' '<<wolfCnt;

}