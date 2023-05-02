#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool verifyXWin(vector<vector<char>> &board){
    bool res = false;
        for(int i=0; i<3; i++){
            if(board[i][0]=='X' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                res = true;        
            }
        }
        for(int i=0; i<3; i++){

            if(board[0][i]=='X' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
                res = true;        
            }
        }
        if(board[0][0]=='X' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            res = true;        
        }
        if(board[0][2]=='X' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            res = true;    
        }
    

    return res;
}

bool verifyOWin(vector<vector<char>> &board){
    bool res = false;
        for(int i=0; i<3; i++){
            if(board[i][0]=='O' && board[i][0]==board[i][1] && board[i][1]==board[i][2]){
                res = true;        
            }
        }
        for(int i=0; i<3; i++){
            if(board[0][i]=='O' && board[0][i]==board[1][i] && board[1][i]==board[2][i]){
                res = true;        
            }
        }
        if(board[0][0]=='O' && board[0][0]==board[1][1] && board[1][1]==board[2][2]){
            res = true;        
        }
        if(board[0][2]=='O' && board[0][2]==board[1][1] && board[1][1]==board[2][0]){
            res = true;    
        }
    

    return res;
}

int main(){
    vector<vector<char>> board;
    string str;

    board.assign(3, vector<char>(3, '.'));
    cin>>str;
    while(str!="end"){
        int xCnt = 0;
        int oCnt = 0;

        for(int i=0; i<9; i++){
            board[i/3][i%3] = str[i];
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(board[i][j]=='X'){
                    xCnt++;
                }
                if(board[i][j]=='O'){
                    oCnt++;
                }
            }
        }

        bool xWin = verifyXWin(board);
        bool oWin = verifyOWin(board);

        //cout<<xCnt<<' '<<oCnt<<'\n';
        //cout<<"ver: "<<verticalCnt<<' '<<winChVertical<<" hor: "<<horizontalCnt<<' '<<winChHorizontal<<" diag: "<<diagonalCnt<<' '<<winChDiagonal<<" full: "<<fullFlag<<' ';
        if(xWin && !oWin && xCnt==oCnt+1){
            cout<<"valid\n";
        }
        else if(!xWin && oWin && xCnt==oCnt){
            cout<<"valid\n";
        }
        else if(!xWin && !oWin && xCnt==5 && oCnt==4){
            cout<<"valid\n";
        }
        else{
            cout<<"invalid\n";
        }
        
        cin>>str;
    }
}