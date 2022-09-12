#include <iostream>
#include <vector>

using namespace std;

vector<int> prevDice;
vector<int> presDice;
vector<vector<int>> board;
int x, y;

//Key point -> �ֻ����� ���� �ε����� �����ϰ� �� ���� ���ڸ� ���ư��� ������ ������ �ذ��Ѵ�.

//���� üũ
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

int upside(int n, int m, int r, int c, int order){ //�ֻ��� ������
    //���� üũ - ���� ����� ��µ��� �ʰ� ���������� �ʰ� �ؾ���.
    if(order==1 && valid(n,m,r,c+1)){ //������
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
    else if(order==2 && valid(n,m,r,c-1)){//����
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
    else if(order==3 && valid(n,m,r-1,c)){//����
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
    else if(order==4 && valid(n,m,r+1,c)){//�Ʒ���
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
    else{ //���� ���
        return -1;
        //return;
    }    

    copy(presDice.begin(), presDice.end(), prevDice.begin());
    //�� ���� ���� ���
    // for(int i=0; i<6; i++){
    //     cout<<"presDice["<<i<<"]: "<<presDice[i]<<'\n';
    // }
    return presDice[0];
    
}

int main(){
    int n, m, k, result;
    cin>>n>>m>>x>>y>>k;

    board.assign(n, vector<int>(m,0));
    prevDice.assign(6, 0); //ó���� ��� �鿡 0 ����.
    presDice.assign(6, 0); //ó���� ��� �鿡 0 ����.

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