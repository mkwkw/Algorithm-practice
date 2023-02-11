#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board, adjacentCnt;
vector<vector<bool>> visited;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

//���� üũ
bool verify(int n, int m, int x, int y){
    if(x<0 || x>=n){
        return false;
    }
    else if(y<0 || y>=m){
        return false;
    }

    return true;
}

//������ 0ĭ ���� ����
void countAdjacent(int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<4; k++){
                if(board[i][j]>0 && verify(n, m, i+dx[k], j+dy[k])){
                    if(board[i+dx[k]][j+dy[k]]==0){
                        adjacentCnt[i][j]++;
                    }
                }
            }            
        }
    }
}

//���� ��� �ľ� - dfs
void countIce(int n, int m, int x, int y){
    if(!visited[x][y] && board[x][y]>0){
        visited[x][y]=true;
        for(int i=0; i<4; i++){
            if(verify(n,m, x+dx[i], y+dy[i])){
                countIce(n, m, x+dx[i], y+dy[i]);
            }
        }
    }
}


int main(){
    
    int n, m, answer=0;
    int cnt = 0; //���� ����
    cin>>n>>m;

    board.assign(n, vector<int>(m,0));
    visited.assign(n,vector<bool>(m,false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    //���� ��� ���� ����
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j] && board[i][j]>0){
                cnt++;
                countIce(n,m,i,j);
            }
        }
    }

    while(cnt==1){ //���� ��� ����==1 ���� ��� �ݺ�
        
        visited.assign(n,vector<bool>(m,false));
        adjacentCnt.assign(n,vector<int>(m,0));
        cnt=0; 

        countAdjacent(n, m);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = board[i][j] - adjacentCnt[i][j];
                if(board[i][j]<0){
                    board[i][j]=0;
                }
            }
        }

        answer++;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && board[i][j]>0){
                    cnt++;
                    countIce(n,m,i,j);
                }
            }
        }

        if(cnt>=2){
            break;
        }
        else if(cnt==0){
            answer=0;
            break;
        }
        
    }
    
    cout<<answer;

}