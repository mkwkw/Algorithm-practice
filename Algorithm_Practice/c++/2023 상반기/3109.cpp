#include <iostream>
#include <vector>

using namespace std;

int dr[3]={-1, 0, 1};
//열 방향: 세가지 방향 모두 오른쪽으로 이동하므로 따로 배열 선언하지 않고 +1만 해줌

vector<string> board;
vector<vector<bool>> visited;
int cnt = 0;
bool flag; //마지막 열에 도달했는지 여부를 전역변수로 선언하여 전체적으로 통제한다. 마지막 열에 도달하면 뒤에 모든 재귀 건너뛰고 다음 행 첫번째 열로 오도록 함

bool verify(int x, int y, int r, int c){
    if(x<0 || x>=r || y<0 || y>=c){
        return false;
    }
    return true;
}

void countRoad(int x, int y, int r, int c){

    visited[x][y] = true;
    
    if(y==c-1){
        cnt++;
        flag = true; //마지막 열에 도달했다 표시
        return;
    }
    
    for(int i=0; i<3; i++){

        int nextX = x+dr[i];
        int nextY = y+1;

        if(verify(nextX, nextY, r, c) && !visited[nextX][nextY]){            
            countRoad(nextX, nextY, r, c);
            if(flag){
                return;
            }
        }
        
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c;
    cin>>r>>c;

    visited.assign(r, vector<bool>(c, false));

    for(int i=0; i<r; i++){
        string road;
        cin>>road;
        board.push_back(road);        
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j]=='x'){
                visited[i][j]=true;
            }
        }
    }

    for(int i=0; i<r; i++){
        if(board[i][0]!='x'){
            flag = false; //마지막 열에 도달하면 true로 바뀌도록
            countRoad(i,0,r,c);
        }
    }

    cout<<cnt;

}