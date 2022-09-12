#include <iostream>
#include <vector>

using namespace std;

vector<int> prevDice;
vector<int> presDice;
vector<vector<int>> board;
int x, y;

//Key point -> 주사위의 면은 인덱스로 고정하고 그 면의 숫자만 돌아가는 식으로 문제를 해결한다.

//범위 체크
bool valid(int n , int m, int r, int c){
    if(r>=n || c>=m || r<0 || c<0){
        return false;
    }
    return true;
}

void copyDice(int x, int y){
    if(board[x][y]==0){
        board[x][y]=presDice[5];
    }
    else{
        presDice[5]=board[x][y];
        prevDice[5]=board[x][y];
        board[x][y]=0;
    }
}

int upside(int n, int m, int r, int c, int order){ //주사위 굴리기
    //범위 체크 - 범위 벗어나면 출력되지 않고 굴러가지도 않게 해야함.
    if(order==1 && valid(n,m,r,c+1)){ //오른쪽
        x=r;
        y=c+1;
        presDice[0] = prevDice[3];
        presDice[1] = prevDice[1];
        presDice[2] = prevDice[0];
        presDice[3] = prevDice[5];
        presDice[4] = prevDice[4];
        presDice[5] = prevDice[2];
        copyDice(x,y);

    }
    else if(order==2 && valid(n,m,r,c-1)){//왼쪽
        x=r;
        y=c-1;
        presDice[0] = prevDice[2];
        presDice[1] = prevDice[1];
        presDice[2] = prevDice[5];
        presDice[3] = prevDice[0];
        presDice[4] = prevDice[4];
        presDice[5] = prevDice[3];
        copyDice(x,y);
    }
    else if(order==3 && valid(n,m,r-1,c)){//위쪽
        x=r-1;
        y=c;
        presDice[0] = prevDice[4];
        presDice[1] = prevDice[0];
        presDice[2] = prevDice[2];
        presDice[3] = prevDice[3];
        presDice[4] = prevDice[5];
        presDice[5] = prevDice[1];
        copyDice(x,y);
    }
    else if(order==4 && valid(n,m,r+1,c)){//아래쪽
        x=r+1;
        y=c;
        presDice[0] = prevDice[1];
        presDice[1] = prevDice[5];
        presDice[2] = prevDice[2];
        presDice[3] = prevDice[3];
        presDice[4] = prevDice[0];
        presDice[5] = prevDice[4];
        copyDice(x,y);
    }
    else{ //범위 벗어남
        return -1;
        //return;
    }    

    copy(presDice.begin(), presDice.end(), prevDice.begin());
    //맨 윗면 숫자 출력
    // for(int i=0; i<6; i++){
    //     cout<<"presDice["<<i<<"]: "<<presDice[i]<<'\n';
    // }
    return presDice[0];
    
}

int main(){
    int n, m, k, result;
    cin>>n>>m>>x>>y>>k;

    board.assign(n, vector<int>(m,0));
    prevDice.assign(6, 0); //처음엔 모든 면에 0 있음.
    presDice.assign(6, 0); //처음엔 모든 면에 0 있음.

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>board[i][j];
        }
    }

    copyDice(x,y);

    for(int i=0; i<k; i++){
        int order;
        cin>>order;
        //upside(n,m,x,y,order);
        result = upside(n,m,x,y,order);
        if(result==-1){
            continue;
        }
        cout<<result<<'\n';
    }
}