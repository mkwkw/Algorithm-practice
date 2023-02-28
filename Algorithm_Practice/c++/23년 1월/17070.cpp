#include <iostream>
#include <vector>

using namespace std;

int dr[3]={0,1,1};
int dc[3]={1,1,0};

vector<vector<int>> board; //빈칸: 0, 벽:1
vector<vector<int>> dp; //dp[r][c]: (r,c)까지 오는 경우의 수

int answer = 0;

bool verify(int r, int c, int n, int pos, int i){
    if(r<0 || r>=n || c<0 || c>=n || board[r][c]==1){
        return false;
    }

    if(i==1 && (board[r-1][c]==1 || board[r][c-1]==1)){ //대각선으로 이동 조건 - 새로 이동한 r,c 말고도 빈칸 존재 해야함
        return false;
    }
    
    //현재 모양과 다음 모양 조건
    if(pos==0 && i==2){
        return false;
    }
    else if(pos==2 && i==0){
        return false;
    }

    return true;
}

void movePipe(int r, int c, int n, int pos){ //r,c: 현재 파이프의 오른쪽 끝 부분 위치 / pos: 현재 파이프 모양(0: 가로, 1: 대각선, 2: 세로)

    for(int i=0; i<3; i++){ //다음 파이프 모양(i=0: 가로, i=1: 대각선, i=2: 세로)
        int nextR = r+dr[i]; 
        int nextC = c+dc[i];
        //cout<<"r: "<<r<<" c: "<<c<<" nextR: "<<nextR<<' '<<" nextC: "<<nextC<<" pos: "<<pos<<" i: "<<i<<'\n';

        if(verify(nextR, nextC, n, pos, i)){
            dp[nextR][nextC] += 1;
            // for(int j=0; j<n; j++){
            //     for(int k=0; k<n; k++){
            //         cout<<dp[j][k]<<' ';
            //     }
            //     cout<<'\n';
            // }
            movePipe(nextR, nextC, n, i); //재귀 이용하여 파이프 이동
        }
    }

}

int main(){

    int n;

    cin>>n;

    board.assign(n, vector<int>(n,-1));
    dp.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    movePipe(0,1,n,0);

    //dp[0][0]=0, dp[0][1]=0
    cout<<dp[n-1][n-1];

    
}