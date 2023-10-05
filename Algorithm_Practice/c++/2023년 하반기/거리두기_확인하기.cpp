#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i=0; i<5; i++){
        vector<pair<int,int>> pos; //p의 좌표
        int result = 1;
        
        //p의 좌표 모아두기
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(places[i][j][k]=='P'){
                    pos.push_back({j,k});
                }
            }
        }
        
        //p끼리의 거리 따지고, 거리를 두었는지 따지기
        for(int j=0; j<pos.size()-1; j++){
            for(int k=j+1; k<pos.size(); k++){
                int distance = abs(pos[j].first-pos[k].first)+abs(pos[j].second-pos[k].second); //맨해튼 거리
                if(distance>=3){
                    continue;
                } 
                else if(distance==1){
                    result = 0;
                }
                else{ //거리가 2일 때
                    int r1 = pos[j].first;
                    int r2 = pos[k].first;
                    int c1 = pos[j].second;
                    int c2 = pos[k].second;
                    
                    //행 - P_P
                    if(r1==r2){
                        if(places[i][r1][(c1+c2)/2]!='X'){
                            result = 0;
                        }
                    }
                    
                    //열
                    //P
                    //_
                    //P
                        
                    //행, 열 모두 다를 때
                    
                }
                
                if(result==0){
                    break;
                }
            }
            if(result==0){
                break;
            }
        }
        
        answer.push_back(result);
    }
    return answer;
}