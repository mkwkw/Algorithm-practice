#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
int answer = 1000;

int dr[3]={1,1,1};
int dc[3]={-1,0,1};
int n, m;

bool verify(int r, int c){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }
    return true;
}

//return, continue 사용 주의!
void backtracking(int r, int c, int fuel, int dir){
    //cout<<"r: "<<r<<" c: "<<c<<" fuel: "<<fuel<<" answer: "<<answer<<'\n';
    for(int i=0; i<3; i++){
        if(r==n-1){
            answer = fuel;
            return;
        }

        if(dir==i){
            continue;
        }
        
        int nextR = r+dr[i];
        int nextC = c+dc[i];

        if(!verify(nextR, nextC)){
            continue;
        }

        int nextFuel = fuel+board[nextR][nextC];

        if(nextFuel>=answer){
            continue;
        }

        backtracking(nextR, nextC, nextFuel, i);
    }

}

int main(){
    
    cin>>n>>m;

    board.assign(n, vector<int>(m,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        backtracking(0, i, board[0][i], -1);
    }

    cout<<answer;

}