#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//하, 상, 우, 좌
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};
vector<vector<int>> board;

void up(int r, int c, int num){
    for(int i=r; i>=0; i--){
        if(board[i][c]==6){
            break;
        }
        if(board[i][c]>0 || board[i][c]<num*(-1)){
            continue;
        }
        
        board[i][c]=num*(-1);
    }
}

void down(int r, int c, int n, int num){
    for(int i=r; i<n; i++){
        if(board[i][c]==6){
            break;
        }
        if(board[i][c]>0 || board[i][c]<num*(-1)){
            continue;
        }
        
        board[i][c]=num*(-1);
    }
}

void left(int r, int c, int num){
    for(int i=c; i>=0; i--){
        if(board[r][i]==6){
            break;
        }
        if(board[r][i]>0 || board[r][i]<num*(-1)){
            continue;
        }

        board[r][i]=num*(-1);
    }
}

void right(int r, int c, int m, int num){
    for(int i=c; i<m; i++){
        if(board[r][i]==6){
            break;
        }
        if(board[r][i]>0 || board[r][i]<num*(-1)){
            continue;
        }

        board[r][i]=num*(-1);
    }
}

//회전시킬 때, 이전에 변경했던 값 되돌려놔야함
void initUp(int r, int c, int num){
    for(int i=r; i>=0; i--){
        if(board[i][c]==6){
            break;
        }
        if(board[i][c]>0 || board[i][c]<num*(-1)){
            continue;
        }
        
        board[i][c]=0;
    }
}

void initDown(int r, int c, int n, int num){
    for(int i=r; i<n; i++){
        if(board[i][c]==6){
            break;
        }
        if(board[i][c]>0 || board[i][c]<num*(-1)){
            continue;
        }
        
        board[i][c]=0;
    }
}

void initLeft(int r, int c, int num){
    for(int i=c; i>=0; i--){
        if(board[r][i]==6){
            break;
        }
        if(board[r][i]>0 || board[r][i]<num*(-1)){
            continue;
        }

        board[r][i]=0;
    }
}

void initRight(int r, int c, int m, int num){
    for(int i=c; i<m; i++){
        if(board[r][i]==6){
            break;
        }
        if(board[r][i]>0 || board[r][i]<num*(-1)){
            continue;
        }

        board[r][i]=0;
    }
}

int main(){

    int n,m;
    int minCnt = 0;
    int minDir = 0;
    vector<queue<pair<int, int>>> cctvPos(5); //cctvPos[0]: 1번 cctv 좌표

    cin>>n>>m;

    minCnt = n*m;

    board.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
            
            switch(board[i][j]){
                case 1:
                    cctvPos[0].push({i,j});
                    break;
                case 2:
                    cctvPos[1].push({i,j});
                    break;
                case 3:
                    cctvPos[2].push({i,j});
                    break;
                case 4:
                    cctvPos[3].push({i,j});
                    break;
                case 5:
                    cctvPos[4].push({i,j});
                    break;
                
            }
        }
    }

    //5번 cctv - 회전X
    while(!cctvPos[4].empty()){
        int nowR = cctvPos[4].front().first;
        int nowC = cctvPos[4].front().second;

        //상
        up(nowR, nowC,50);

        //하
        down(nowR, nowC, n, 50);

        //좌
        left(nowR, nowC, 50);

        //우
        right(nowR, nowC, m, 50);

        cctvPos[4].pop();
    }

    //4번 cctv - 회전 O - 4가지 방향
    
    while(!cctvPos[3].empty()){
        int nowR = cctvPos[3].front().first;
        int nowC = cctvPos[3].front().second;
        int cnt = 0;

        //방향 1
        up(nowR, nowC, 4);
        left(nowR, nowC, 4);
        right(nowR, nowC, m, 4);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 1;
        }

        cnt = 0;
        initUp(nowR, nowC, 4);
        initLeft(nowR, nowC, 4);
        initRight(nowR, nowC, m, 4);

        //방향 2
        up(nowR, nowC, 4);
        left(nowR, nowC, 4);
        down(nowR, nowC, n, 4);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 2;
        }

        cnt = 0;
        initUp(nowR, nowC, 4);
        initLeft(nowR, nowC, 4);
        initDown(nowR, nowC, n, 4);

        //방향 3
        right(nowR, nowC, m, 4);
        left(nowR, nowC, 4);
        down(nowR, nowC, n, 4);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 3;
        }
        
        cnt = 0;
        initRight(nowR, nowC, m, 4);
        initLeft(nowR, nowC, 4);
        initDown(nowR, nowC, n, 4);

        //방향4
        up(nowR, nowC, 4);
        right(nowR, nowC, m, 4);
        down(nowR, nowC, n, 4);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 4;
        }
        
        cnt = 0;
        initUp(nowR, nowC, 4);
        initRight(nowR, nowC, m, 4);
        initDown(nowR, nowC, n, 4);
        
        if(minDir>0){
            switch(minDir){
                case 1:
                    up(nowR, nowC, 40);
                    left(nowR, nowC, 40);
                    right(nowR, nowC, m, 40);
                    break;

                case 2:
                    up(nowR, nowC, 40);
                    left(nowR, nowC, 40);
                    down(nowR, nowC, n, 40);
                    break;

                case 3:
                    right(nowR, nowC, m, 40);
                    left(nowR, nowC, 40);
                    down(nowR, nowC, n, 40);
                    break;
                
                case 4:
                    up(nowR, nowC, 40);
                    right(nowR, nowC, m, 40);
                    down(nowR, nowC, n, 40);
                    break;
            }

        }

        cctvPos[3].pop();
    }

    //3번 cctv - 회전 O - 4가지 방향
    minCnt = n*m;
    minDir = 0;
    while(!cctvPos[2].empty()){
        int nowR = cctvPos[2].front().first;
        int nowC = cctvPos[2].front().second;
        int cnt = 0;

        //방향 1
        up(nowR, nowC, 3);
        right(nowR, nowC, m, 3);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 1;
        }

        cnt = 0;
        initUp(nowR, nowC, 3);
        initRight(nowR, nowC, m, 3);

        //방향 2
        up(nowR, nowC, 3);
        left(nowR, nowC, 3);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 2;
        }

        cnt = 0;
        initUp(nowR, nowC, 3);
        initLeft(nowR, nowC, 3);

        //방향 3
        left(nowR, nowC, 3);
        down(nowR, nowC, n, 3);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 3;
        }
        
        cnt = 0;
        initLeft(nowR, nowC, 3);
        initDown(nowR, nowC, n, 3);

        //방향4
        right(nowR, nowC, m, 3);
        down(nowR, nowC, n, 3);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 4;
        }
        
        cnt = 0;
        initRight(nowR, nowC, m, 3);
        initDown(nowR, nowC, n, 3);
        
        if(minDir>0){
            switch(minDir){
                case 1:
                    up(nowR, nowC, 30);
                    right(nowR, nowC, m, 30);
                    break;

                case 2:
                    up(nowR, nowC, 30);
                    left(nowR, nowC, 30);
                    break;

                case 3:
                    left(nowR, nowC, 30);
                    down(nowR, nowC, n, 30);
                    break;
                
                case 4:
                    right(nowR, nowC, m, 30);
                    down(nowR, nowC, n, 30);
                    break;
            }

        }

        cctvPos[2].pop();
    }

    //1번 cctv - 회전 O - 4가지 방향
    minCnt = n*m;
    minDir = 0;
    while(!cctvPos[0].empty()){
        int nowR = cctvPos[0].front().first;
        int nowC = cctvPos[0].front().second;
        int cnt = 0;

        //방향 1
        up(nowR, nowC, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 1;
        }

        cnt = 0;
        initUp(nowR, nowC, 1);

        //방향 2
        left(nowR, nowC, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 2;
        }

        cnt = 0;
        initLeft(nowR, nowC, 1);

        //방향 3
        down(nowR, nowC, n, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 3;
        }

        cnt = 0;
        initDown(nowR, nowC, n, 1);

        //방향4
        right(nowR, nowC, m, 1);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 4;
        }
        
        cnt = 0;
        initRight(nowR, nowC, m, 1);

        if(minDir>0){
            switch(minDir){
                case 1:
                    up(nowR, nowC, 10);
                    break;

                case 2:
                    left(nowR, nowC, 10);
                    break;

                case 3:
                    down(nowR, nowC, n, 10);
                    break;
                
                case 4:
                    right(nowR, nowC, m, 10);
                    break;
            }

        }

        cctvPos[0].pop();
    }

    //2번 cctv - 회전 O - 2가지 방향
    minCnt = n*m;
    minDir = 0;
    while(!cctvPos[1].empty()){
        int nowR = cctvPos[1].front().first;
        int nowC = cctvPos[1].front().second;
        int cnt = 0;

        //방향 1
        left(nowR, nowC, 2);
        right(nowR, nowC, m, 2);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 1;
        }

        cnt = 0;
        initLeft(nowR, nowC, 2);
        initRight(nowR, nowC, m, 2);

        //방향 2
        up(nowR, nowC, 2);
        down(nowR, nowC, n, 2);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==0){
                    cnt++;
                }
            }
        }

        if(minCnt>cnt){
            minCnt = cnt;
            minDir = 2;
        }

        cnt = 0;
        initUp(nowR, nowC, 2);
        initDown(nowR, nowC, n, 2);
        
        if(minDir>0){
            switch(minDir){
                case 1:
                    left(nowR, nowC, 20);
                    right(nowR, nowC, m, 20);
                    break;

                case 2:
                    up(nowR, nowC, 20);
                    down(nowR, nowC, n, 20);
                    break;
            }

        }

        cctvPos[1].pop();
    }

    

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<board[i][j]<<' ';
            if(board[i][j]==0){
                answer++;
            }
        }
        cout<<'\n';
    }

    cout<<answer;

}