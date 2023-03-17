#include <iostream>
#include <vector>

using namespace std;

int dr[3]={-1, 1, 0};

vector<string> board;
vector<vector<bool>> visited;
int cnt = 0;

bool verify(int x, int y, int r, int c){
    if(x<0 || x>=r || y<0 || y>=c){
        return false;
    }
    return true;
}

void countRoad(int x, int y, int r, int c){
    
    if(!verify(x,y,r,c) || visited[x][y]){
        return;
    }

   

    visited[x][y] = true;
    cout<<"move: "<<x<<' '<<y<<' '<<cnt<<'\n';
    if(y==c-1){
        cnt++;
        countRoad(x+1, 0, r, c);
    }

    if(x>=r-1){
        return;
    }
    
    for(int i=0; i<3; i++){

        int nextX = x+dr[i];
        int nextY = y+1;
        cout<<nextX<<' '<<nextY<<' '<<cnt<<'\n';

        countRoad(nextX, nextY, r, c);
        
    }
}

int main(){
    
    int r, c;
    cin>>r>>c;

    visited.assign(r, vector<bool>(r, false));

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
            countRoad(i,0,r,c);
        }
    }

    cout<<cnt;

}