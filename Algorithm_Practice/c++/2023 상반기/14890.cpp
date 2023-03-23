#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> board;
    vector<vector<int>> sameColLength;
    vector<vector<int>> sameRowLength;
    int n, l, answer = 0;

    cin>>n>>l;

    board.assign(n, vector<int>(n, 0));
    sameColLength.assign(n, vector<int>(n, 0));
    sameRowLength.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    
    for(int i=0; i<n; i++){
        bool flag = true, flag1 = true, flag2 = true;
        int prev1 = 0, next1 = 0, prev2 = 0, next2 = 0;
        
        prev1 = board[i][0];
        prev2 = board[0][i];

        for(int j=1; j<n; j++){
            
            next1 = board[i][j];
            next2 = board[j][i];
            cout<<"pos: "<<i<<' '<<j<<'\n';
            cout<<"prev1: "<<prev1<<" next1: "<<next1<<'\n';

            //하나의 행

            //인접한 칸 높이 차 2이상이면 경사로 설치 불가
            if(abs(prev1-next1)>1){
                flag1 = false;
                break;
            }

            //높이 변화가 생겼을 때
            if(prev1 != next1){
                //flag = false;

                if(prev1<next1){ //왼쪽에 L개 이상의 높이가 prev1인 칸이 있는가 
                    int sameHeight = 0;
                    for(int k=j-1; k>=0; k--){
                        if(board[i][k]==prev1){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag1 = false;
                        break;
                    }
                    cout<<"left l: "<<sameHeight<<'\n';
                }
                else{ //오른쪽에 L개 이상의 높이가 next1인 칸이 있는가
                    int sameHeight = 1;
                    for(int k=j+1; k<n; k++){
                        if(board[i][k]==next1){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag1 = false;
                        break;
                    }
                    cout<<"right l: "<<sameHeight<<'\n';

                }
            }

            

            //하나의 열
            if(abs(prev2-next2)>1){
                flag2 = false;
                break;
            }

            //높이 변화가 생겼을 때
            if(prev2 != next2){
                //flag = false;

                if(prev2<next2){ //위에 L개 이상의 높이가 prev2인 칸이 있는가 
                    int sameHeight = 0;
                    for(int k=j-1; k>=0; k--){
                        if(board[k][i]==prev2){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag2 = false;
                        break;
                    }
                    cout<<"up l: "<<sameHeight<<'\n';
                }
                else{ //아래쪽에 L개 이상의 높이가 next2인 칸이 있는가
                    int sameHeight = 1;
                    for(int k=j+1; k<n; k++){
                        if(board[k][i]==next2){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag = false;
                        break;
                    }
                    cout<<"down l: "<<sameHeight<<'\n';

                }
            }

            

            prev1 = board[i][j];
            prev2 = board[j][i];
        }

        if(flag1){
            answer++;
            cout<<"row: "<<i<<' '<<answer<<'\n';
        }

        if(flag2){
            answer++;
            cout<<"col: "<<i<<' '<<answer<<'\n';
        }
        //if(flag && flag1 && flag2){
        //    answer++;
        //}
        //else{
        //    if(flag1 && flag2){
        //        answer++;
        //    }
        //}

        //cout<<"ans: "<<answer<<'\n';
    }
    

    cout<<answer;

}