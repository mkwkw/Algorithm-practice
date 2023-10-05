#include <iostream>
#include<vector>

using namespace std;

//완전 탐색 - 정확성 o, 효율성 시간초과
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int length = min(board.size(), board[0].size()); //가능한 최대 정사각형 변의 길이 - min(행의 길이, 열의 길이)
    
    for(int l = length; l>=1; l--){
        //cout<<"l "<<l<<'\n';
        for(int i=0; i<=board.size()-l; i++){
            for(int j=0; j<=board[0].size()-l; j++){
                bool flag = true;
                //cout<<i<<' '<<j<<'\n';
                for(int k=i; k<i+l; k++){
                    for(int t=j; t<j+l; t++){
                        
                        if(board[k][t]==0){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag){
                        break;
                    }
                }
                //cout<<'\n';
                if(flag){
                    //cout<<"re\n";
                    return  l*l;
                }  
            }
            
        }
        
    }
    
    return answer;
}