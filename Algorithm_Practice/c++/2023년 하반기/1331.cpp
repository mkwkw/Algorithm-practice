#include <iostream>
#include <vector>

using namespace std;

//체스에서 나이트의 움직임?
int main(){
    int r, c, prevR, prevC, firstR, firstC;
    //나이트 이동 가능한 지점(규칙)
    int dr[8]={-1,-2,2,1,-1,2,-2,1};
    int dc[8]={-2,-1,1,2,2,-1,1,-2};    
    string pos;
    vector<vector<bool>> visited;
    bool flag = true;
    bool knightPossible = true;
    visited.assign(6, vector<bool>(6, false));

    for(int i=0; i<36; i++){
        
        cin>>pos;

        r = pos[1]-'1';
        c = pos[0]-'A';

        if(i==0){
            firstR = r;
            firstC = c;
        }

        if(i>0){
            knightPossible = false;
            for(int j=0; j<8; j++){
                if(prevR+dr[j]==r && prevC+dc[j]==c){
                    knightPossible = true;
                    break;
                }
            }
        }

        if(visited[r][c]){ //재방문
            flag = false;
        }
        if(!knightPossible){ //나이트 이동 불가능
            flag = false;
        }

        visited[r][c] = true; //방문 표시
        prevR = r;
        prevC = c;

    }

    //마지막지점에서 첫번째 지점으로 이동가능한지 판별
    bool lastToFirst = false;
    for(int i=0; i<8; i++){
        if(prevR+dr[i]==firstR && prevC+dc[i]==firstC){
            lastToFirst = true;
            break;
        }
    }

    if(!lastToFirst){
        flag = false;
    }

    if(flag){
        cout<<"Valid";
    }
    else{
        cout<<"Invalid";
    }
}