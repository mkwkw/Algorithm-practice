#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos{
    int r;
    int c;
    bool dir; //true: 행, false: 열
};

int main(){
    vector<vector<int>> board;
    vector<vector<bool>> check1; //행 체크
    vector<vector<bool>> check2; //열 체크
    queue<Pos> pos;
    
    int n, l, answer = 0;

    cin>>n>>l;

    board.assign(n, vector<int>(n, 0));
    check1.assign(n, vector<bool>(n, true));
    check2.assign(n, vector<bool>(n, true));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        int prev1 = 0, next1 = 0, prev2 = 0, next2 = 0;
        
        prev1 = board[i][0]; //행
        prev2 = board[0][i]; //열
        
        for(int j=1; j<n; j++){
            next1 = board[i][j];
            next2 = board[j][i];

            if(prev1!=next1){
                //cout<<"row: "<<i<<' '<<j<<'\n';
                check1[i][j]=false;
                pos.push({i, j, true});
            }

            if(prev2!=next2){
                //cout<<"col: "<<j<<' '<<i<<'\n';
                check2[j][i]=false;
                pos.push({j, i, false});
            }

            prev1 = board[i][j];
            prev2 = board[j][i];
            
        }
    }

    while(!pos.empty()){
        Pos p = pos.front();
        int r = p.r;
        int c = p.c;
        bool dir = p.dir; //true: 행, false: 열

        cout<<r<<' '<<c<<' '<<(dir?"row":"col")<<'\n';

        if(dir){ //행 조사
            int sameNum1 = 0, sameNum2 = 0;
            //왼쪽
            if(c>0){ 
                if(board[r][c-1] < board[r][c]){//왼쪽 높이가 낮을 때
                
                    for(int i=c-1; i>=0; i--){
                        if(board[r][i]==board[r][c-1]){
                            sameNum1++;
                        }
                        else{
                            break;
                        }

                        if(sameNum1==l){
                            break;
                        }
                    }

                }
                else{ //왼쪽 높이가 높을 때

                    for(int i=c; i<n; i++){
                        if(board[r][i]==board[r][c]){
                            sameNum1++;
                        }
                        else{
                            break;
                        }

                        if(sameNum1==l){
                            break;
                        }
                    }

                }

            }
            //오른쪽
            if(c<n-1){
                if(board[r][c] > board[r][c+1]){ //오른쪽 높이가 낮을 때
                
                    for(int i=c+1; i<n; i++){
                        if(board[r][i]==board[r][c+1]){
                            sameNum2++;
                        }
                        else{
                            break;
                        }

                        if(sameNum2==l){
                            break;
                        }
                    }
                }
                else{ //오른쪽 높이가 높을 때
                    
                    for(int i=c; i>=0; i--){
                        if(board[r][i]==board[r][c]){
                            sameNum2++;
                        }
                        else{
                            break;
                        }

                        if(sameNum2==l){
                            break;
                        }
                    }

                }
            }
            cout<<"row: "<<sameNum1<<' '<<sameNum2<<'\n';
            if(sameNum1==l && sameNum2==l){
                check1[r][c]=true;
                
            }
            else if(sameNum1==0 && sameNum2==l){
                check1[r][c]=true;
            }
            else if(sameNum1==l && sameNum2==0){
                check1[r][c]=true;
            }

        }
        else{ //열 조사
            //위쪽
            //아래쪽
            int sameNum1 = 0, sameNum2 = 0;
            //위쪽
            if(r>0){

                if(board[r-1][c] < board[r][c]){ //위쪽 높이가 낮을 때
                
                    for(int i=r-1; i>=0; i--){
                        if(board[i][c]==board[r-1][c]){
                            sameNum1++;
                        }
                        else{
                            break;
                        }

                        if(sameNum1==l){
                            break;
                        }
                    }
                }
                else{ //위쪽 높이가 높을 때
                    
                    for(int i=r; i<n; i++){
                        if(board[i][c]==board[r][c]){
                            sameNum1++;
                        }
                        else{
                            break;
                        }

                        if(sameNum1==l){
                            break;
                        }
                    }

                }

            }
            //아래쪽
            if(r<n-1){
                if(board[r+1][c] < board[r][c]){ //아래쪽 높이가 낮을 때
                
                    for(int i=r+1; i<n; i++){
                        if(board[i][c]==board[r+1][c]){
                            sameNum2++;
                        }
                        else{
                            break;
                        }

                        if(sameNum2==l){
                            break;
                        }
                    }
                }
                else{ //아래쪽 높이가 높을 때
                    for(int i=r; i>=0; i--){
                        if(board[i][c]==board[r][c]){
                            sameNum2++;
                        }
                        else{
                            break;
                        }

                        if(sameNum2==l){
                            break;
                        }
                    }

                }
            }

            if(sameNum1==l && sameNum2==l){
                check2[r][c]=true;
            }
            else if(sameNum1==0 && sameNum2==l){
                check2[r][c]=true;
            }
            else if(sameNum1==l && sameNum2==0){
                check2[r][c]=true;
            }

        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<check1[i][j]<<' ';
            }
            cout<<'\n';
        }

        cout<<'\n';

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<check2[i][j]<<' ';
            }
            cout<<'\n';
        }
        
        pos.pop();
    }

    for(int i=0; i<n; i++){
        bool flag1 = true, flag2 = true;

        for(int j=0; j<n; j++){
            if(!check1[i][j]){
                flag1 = false;
            }
            if(!check2[j][i]){
                flag2 = false;
            }
        }

        if(flag1){
            answer++;
        }
        if(flag2){
            answer++;
        }
    }

    
    
    

    cout<<answer;

}