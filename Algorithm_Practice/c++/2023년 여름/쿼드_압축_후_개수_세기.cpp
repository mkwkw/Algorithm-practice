#include <string>
#include <vector>
#include <iostream>

using namespace std;

//재귀
//좌표 중심
vector<vector<int>> board;
int zeroCnt = 0, oneCnt = 0;
//현재 범위의 가장 왼쪽 위의 좌표, 현재 범위의 정사각형의 한 변의 길이
void recur(int r, int c, int length){

    //해당 범위의 사각형이 모두 0이거나 1인가
    bool flag = true;
    int firstNum = board[r][c];
    for(int i=r; i<r+length; i++){
        for(int j=c; j<c+length; j++){
            if(firstNum!=board[i][j]){
                flag = false;
                break;
            }
        }
        if(!flag){
            break;
        }
    }

    if(flag){
        if(firstNum==0){
            zeroCnt++;
        }
        else{
            oneCnt++;
        }
        return;
    }

    recur(r, c, length/2); //좌상
    recur(r, c+length/2, length/2); //우상
    recur(r+length/2, c, length/2); //좌하
    recur(r+length/2, c+length/2, length/2); //우하
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    board = arr;
    recur(0, 0, arr.size());
    
    answer.push_back(zeroCnt);
    answer.push_back(oneCnt);
    
    return answer;
}

int main(){
    vector<int> answer;
    //answer = solution({{1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1}});
    answer = solution({{1,1,0,0},{1,0,0,0},{1,0,0,1},{1,1,1,1}});
    cout<<"answer ";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<' ';
    }
}