#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//곡괭이를 사용할 수 있는 모든 경우에 피로도 계산
//next_permutation
int countTired(string tool, string mine){
    if(tool==mine){
        return 1;
    }
    
    if(tool=="diamond"){
        return 1;
    }
    else if(tool=="iron"){
        if(mine=="diamond"){
            return 5;
        }
        return 1;
    }
    else{
        if(mine=="diamond"){
            return 25;
        }
        else{
            return 5;
        }
    }
    
    return 0;
}

//곡괭이 사용할 수 있는 모든 경우의 수 구하기 - next_permutation
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 25*50;
    vector<string> tools;
    
    for(int i=0; i<picks[0]; i++){
        tools.push_back("diamond");
    }
    for(int i=0; i<picks[1]; i++){
        tools.push_back("iron");
    }
    for(int i=0; i<picks[2]; i++){
        tools.push_back("stone");
    }
    
    //곡괭이 사용하는 모든 경우의 수
    do{
        int tired = 0;
        int first = 0;
        for(int i=0; i<tools.size(); i++){
            bool flag = true;
            for(int j=0; j<5; j++){
                if(first+j<minerals.size())
                    tired += countTired(tools[i], minerals[first+j]);
                else{
                    flag = false;
                    break;
                }
            }
            
            if(!flag){
                break;
            }
            
            first+=5;
        }
        answer = min(answer, tired);
    }
    while(next_permutation(tools.begin(), tools.end()));
    
    return answer;
}