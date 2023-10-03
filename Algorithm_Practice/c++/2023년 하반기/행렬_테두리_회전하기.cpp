#include <string>
#include <vector>
#include <iostream>

using namespace std;

//구현
//초기화 잘 되는지 확인 중요
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<vector<int>> board;
    vector<int> answer;
    
    board.assign(rows, vector<int>(columns, 0));

    //초기화 - row보다 column이 큰 경우, 제대로 초기화되는지 확인 필요
    for(int i=1; i<=rows*columns; i++){
        if(i%columns==0){
            board[i/columns-1][columns-1] = i;
        }
        else{
            board[i/columns][i%columns-1] = i;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        int minNum = rows*columns; //각 회전에 대한 답
        int r1 = queries[i][0]-1;
        int c1 = queries[i][1]-1;
        int r2 = queries[i][2]-1;
        int c2 = queries[i][3]-1;
        
        //각 모서리
        int ru = board[r1][c2];
        int ld = board[r2][c1];
        int rd = board[r2][c2];
        
        //회전
        //1번
        for(int j=c2-1; j>=c1; j--){
            board[r1][j+1] = board[r1][j];
            minNum = min(minNum, board[r1][j+1]);
        }
        
        //2번
        for(int j=r2-1; j>=r1+1; j--){
            board[j+1][c2] = board[j][c2];
            minNum = min(minNum, board[j+1][c2]);
        }
        board[r1+1][c2] = ru;
        minNum = min(minNum, ru);
        
        //3번
        for(int j=c1+1; j<=c2-1; j++){
            board[r2][j-1] = board[r2][j];
            minNum = min(minNum, board[r2][j-1]);
        }
        board[r2][c2-1] = rd;
        minNum = min(minNum, rd);
        
        //4번
        for(int j=r1+1; j<=r2-1; j++){
            board[j-1][c1] = board[j][c1];
            minNum = min(minNum, board[j-1][c1]);
        }
        board[r2-1][c1] = ld;
        minNum = min(minNum, ld);
        
        answer.push_back(minNum);
        
        // for(int j=0; j<rows; j++){
        //     for(int k=0; k<columns; k++){
        //         cout<<board[j][k]<<' ';
        //     }
        //     cout<<'\n';
        // }
    }

    return answer;
}