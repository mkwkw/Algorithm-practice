#include <iostream>
#include <string>
#include <queue>

using namespace std;

//while문으로 돌면서 2개씩 지우기 -> 시간 초과
//queue 이용 -> 시간 단축 - result 마지막 문자와 q.front() 비교

int solution(string s)
{   
    queue<char> q;
    int answer = 0;
    string result = "";
    result += s[0];
    
    if(s.length()<2 || s.length()%2!=0){
        return 0;
    }
    
    for(int i=1; i<s.length(); i++){
        q.push(s[i]);
    }
    
    while(!q.empty()){
        //cout<<result<<'\n';
        if(result[result.length()-1] == q.front()){
            result = result.erase(result.length()-1, 1); 
            //아무래도 맨 뒤에서 하나만 지우면 되니까 substr보다 erase가 시간이 적게 걸림 
        }
        else{
            result += q.front();
        }
        q.pop();
    }
    
    if(result==""){
        answer = 1;
    }
    
    return answer;
}