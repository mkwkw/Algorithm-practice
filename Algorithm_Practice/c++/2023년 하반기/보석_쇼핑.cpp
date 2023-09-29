#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

//DIA: 1,4,5,8
//RUBY: 2,3
//EMERALD: 6
//SAPPHIRE: 7
//1. 재귀
//이런 식으로 있으면 각 보석에서 하나씩 선택하기
//시간초과

map<int, string> numAndJewel; //종류 번호, 보석 이름
map<string, vector<bool>> jewelNumPicked;
map<string, vector<int>> jewelNums;
int startIdx = 100000, endIdx = 200000;

//각 보석 종류의 진열대 번호 중 하나씩만 선택
void findRange(int jewelIdx, vector<int> tempRange, int totalTypeCnt){
    // cout<<"jewelIdx "<<jewelIdx<<' ';
    // for(int i=0; i<tempRange.size(); i++){
    //     cout<<tempRange[i]<<' ';    
    // }
    // cout<<'\n';
    if(jewelIdx+1 == totalTypeCnt){
        
        sort(tempRange.begin(), tempRange.end());
        // cout<<"final ";
        // for(int j=0; j<tempRange.size(); j++){
        //     cout<<tempRange[j]<<' ';
        // }
        // cout<<'\n';
        
        if(tempRange[tempRange.size()-1]-tempRange[0]<endIdx-startIdx){
            startIdx = tempRange[0];
            endIdx = tempRange[tempRange.size()-1];
        }
        else if(tempRange[tempRange.size()-1]-tempRange[0]==endIdx-startIdx){
            if(tempRange[0]<startIdx){
                startIdx = tempRange[0];
                endIdx = tempRange[tempRange.size()-1];
            }
        }
        
        //cout<<"startIdx "<<startIdx<<" endIdx "<<endIdx<<'\n';
        
        return;
    }
    
    string jewelName = numAndJewel[jewelIdx+1];
         
    for(int i=0; i<jewelNums[jewelName].size(); i++){
        if(jewelNumPicked[jewelName][i]){
            continue;
        }  
        
        jewelNumPicked[jewelName][i] = true;
        tempRange.push_back(jewelNums[jewelName][i]);
        findRange(jewelIdx+1, tempRange, totalTypeCnt);
        jewelNumPicked[jewelName][i] = false;
        tempRange.pop_back();
    }
}

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    int idx = 0;
    
    for(int i=0; i<gems.size(); i++){
        jewelNumPicked[gems[i]].push_back(false);
        jewelNums[gems[i]].push_back(i+1);
    }
    
    for(auto m : jewelNumPicked){
        numAndJewel[idx++] = m.first;
    }

//     for(auto m : jewelNums){
//         cout<<m.first<<' ';
//         for(int i=0; i<m.second.size(); i++){
//             cout<<m.second[i]<<' ';
//         }
//         cout<<'\n';
        
//     }    
    
    for(int i=0; i<jewelNums[numAndJewel[0]].size(); i++){
        vector<int> range = {jewelNums[numAndJewel[0]][i]};
        jewelNumPicked[numAndJewel[0]][i] = true;
        findRange(0, range, numAndJewel.size()); 
    }
    
    
    answer[0] = startIdx;
    answer[1] = endIdx;
    
    return answer;
}