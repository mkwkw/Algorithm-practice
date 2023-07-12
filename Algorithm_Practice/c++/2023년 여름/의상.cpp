#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, vector<string>> clothesMap;
    int answer = 1;
    
    for(int i=0; i<clothes.size(); i++){
        clothesMap[clothes[i][1]].push_back(clothes[i][0]);
    }
    
    //만약 [headgear]={"A", "B"}이면 가능한 경우는 A, B, 입지 않음 -> 3가지
    //[eyewear]={"C", "D", "E"}이면 가능한 경우는 C, D, E, 입지 않음 -> 4가지
    //모든 경우의 수 3*4
    //아무것도 입지 않는 경우는 없으므로 마지막에 -1
    //답: 3*4-1
    
    for(auto eachClothes : clothesMap){
        answer *= eachClothes.second.size()+1;   
    }
    
    answer -= 1;
    
    return answer;
}