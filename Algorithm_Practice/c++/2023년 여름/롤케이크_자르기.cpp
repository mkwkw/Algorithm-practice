#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

//map - 키 값 중복X - 종류 세기에 적합
//일단 전체적으로 "topping 종류 : topping 개수"로 map 만들기
//다시 앞에서부터 돌면서 해당 topping 종류에서 1씩 빼기 && 만약에 map에서 topping[i] 개수가 0이면 아예 map에서 제거(erase)
//앞에서부터 돌면서 추가되고 있는 numAndCnt2의 size와 하나씩 빠지고 있는 numAndCnt1의 size가 같다면 answer++
int solution(vector<int> topping) {
    int answer = 0, totalType;
    map<int,int> numAndCnt1, numAndCnt2; //동생, 철수
    
    for(int i=0; i<topping.size(); i++){
        numAndCnt1[topping[i]]++;
    }
    
    for(int i=0; i<topping.size(); i++){
        numAndCnt2[topping[i]] += 1;
        numAndCnt1[topping[i]] -= 1;
        
        if(numAndCnt1[topping[i]]==0){
            numAndCnt1.erase(topping[i]);
        }
        
        if(numAndCnt1.size()==numAndCnt2.size()){
            answer++;
        }
    }
    
    return answer;
}