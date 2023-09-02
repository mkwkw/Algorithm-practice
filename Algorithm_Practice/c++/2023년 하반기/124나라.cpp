#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//3번씩 반복 - 3진수와 유사
string solution(int n) {
    string answer = "";
    
    while(n>0){
        if(n%3==0){
            answer += "4";
            n--; //3으로 나눈 나머지가 0이면 n에서 1을 뺌. -> 6%3=0 -> answer = 4, 몫:(6-1)/3 = 1 -> answer = "14" 
        }
        else if(n%3==1){
            answer += "1";
        }
        else{
            answer += "2";
        }
        
        n /= 3;
        
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}