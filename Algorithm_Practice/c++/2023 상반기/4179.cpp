#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int r;
    int c;
    int time;
    char JF;
};

bool verify(int r, int c, int n, int m){
    if(r<0 || r>=n || c<0 || c>=m){
        return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<string> board;
    queue<Pos> PosQ;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,1,-1};    
    int n, m, answer = 1000001;
    bool flag1 = false, flag2 = false; //가장자리에 지훈이가 있는지, .이 있는지

    cin>>n>>m;

    board.assign(n, " ");

    for(int i=0; i<n; i++){
        string maze;
        cin>>maze;

        board[i] = maze;
    }

    //지훈이가 바로 탈출 가능한 경우
    //처음부터 가장자리에 있는 경우
    if(board[0].find('J')!=string::npos){
        flag1 = true;
    }
    else if(board[n-1].find('J')!=string::npos){
        flag1 = true;
    }
    else{
        for(int i=0; i<n; i++){
            if(board[i][0]=='J'){
                flag1 = true;
            }
            if(board[i][m-1]=='J'){
                flag1 = true;
            }

            if(flag1){
                break;
            }
        }
    }

    if(flag1){
        cout<<"1";
        return 0;
    }

    //무조건 탈출 불가능한 경우: 4개의 가장자리에 .이 하나도 없는 경우
    if(board[0].find('.')!=string::npos){
        flag2 = true;
    }
    else if(board[n-1].find('.')!=string::npos){
        flag2 = true;
    }
    else{
        for(int i=0; i<n; i++){
            if(board[i][0]=='.'){
                flag2 = true;
            }
            if(board[i][m-1]=='.'){
                flag2 = true;
            }

            if(flag2){
                break;
            }
        }
    }

    if(!flag2){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    //불을 먼저 이동 시킨 후, 지훈이를 이동시켜야함. 순서 중요!
    //순서가 없다면 지훈이가 이동한 후, 불이 이동하게 되어 불가능한 경우가 가능한 경우라고 잘못 판별될 수 있음.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='F'){
                PosQ.push({i,j,0,'F'});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='J'){
                PosQ.push({i,j,0,'J'});
            }
        }
    }

    while(!PosQ.empty()){
        int r = PosQ.front().r;
        int c = PosQ.front().c;
        int time = PosQ.front().time;
        char JF = PosQ.front().JF;

        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];

            if(!verify(nextR, nextC, n, m) || board[nextR][nextC]=='#'){
                continue;
            }

            if(JF=='J'){
                if(board[nextR][nextC]=='.'){
                    board[nextR][nextC]='J';
                    PosQ.push({nextR, nextC, time+1, 'J'});

                    if(nextR==0 || nextR==n-1 || nextC==0 || nextC==m-1){
                        answer = min(answer, time+1);
                    }
                }
            }
            else{
                if(board[nextR][nextC]=='.' || board[nextR][nextC]=='J'){
                    board[nextR][nextC]='F';
                    PosQ.push({nextR, nextC, time+1, 'F'});
                }
            } 
        }

        PosQ.pop();
    }

    if(answer==1000001){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<answer+1;
    }

}