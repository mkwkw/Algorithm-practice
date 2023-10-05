#include <string>
#include <vector>
#include <iostream>

using namespace std;

//구현
//경우의 수 나누기
//거리1, 거리2인 경우 나누어서 생각하기
//2중 for문으로 P위치 하나씩 비교할 필요 없음 -> 이렇게 하면 시간초과
bool verify(int nextR, int nextC){
    if(nextR<0 || nextR>=5 || nextC<0 || nextC>=5){
        return false;
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int dr1[4] = {0,0,-1,1};
    int dc1[4] = {1,-1,0,0};
    int dr2[4] = {0,1,1,2};
    int dc2[4] = {2,1,-1,0};
    
    for(int i=0; i<5; i++){
        vector<pair<int,int>> pos; //p의 좌표
        int result = 1;
        cout<<"i "<<i<<'\n';
        //p의 좌표 모아두기
        for(int j=0; j<5; j++){
            for(int k=0; k<5; k++){
                if(places[i][j][k]=='P'){
                    pos.push_back({j,k});
                }
            }
        }
        
        //p끼리의 거리 따지고, 거리를 두었는지 따지기
        for(int j=0; j<pos.size();j++){
            int r = pos[j].first;
            int c = pos[j].second;
            cout<<r<<' '<<c<<'\n';
            //거리가 2
            for(int k=0; k<4; k++){
                int nextR = r+dr2[k];
                int nextC = c+dc2[k];

                if(verify(nextR, nextC) && places[i][nextR][nextC]=='P'){
                    //같은 행
                    if(nextR==r){
                        if(places[i][nextR][(nextC+c)/2]!='X'){
                            cout<<"r\n";
                            cout<<r<<' '<<nextR<<'\n';
                            result = 0;
                            break;
                        }
                    }
                    else if(nextC==c){//같은 열
                        if(places[i][(nextR+r)/2][nextC]!='X'){
                            cout<<"c\n";
                            result = 0;
                            break;
                        }
                    }
                    else{ //다른 행, 다른 열
                        if(!(places[i][nextR][c]=='X'&&places[i][r][nextC]=='X')){
                            cout<<"rc\n";
                            result = 0;
                            break;
                        }
                    }
                }
            }
            if(result==0){
                break;
            }
            cout<<"d2 check\n";
            //거리가 1
            for(int k=0; k<4; k++){
                int nextR = r+dr1[k];
                int nextC = c+dc1[k];

                if(verify(nextR, nextC) && places[i][nextR][nextC]=='P'){
                    cout<<"d1\n";
                    result = 0;
                    break;
                }
            }
            
            if(result==0){
                break;
            }
            cout<<"d1 check\n";
        }
        cout<<"result "<<result<<'\n';
        answer.push_back(result);
    }
    
    return answer;
}

int main(){
    vector<int> answer = solution({{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}});

    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<' ';
    }
}