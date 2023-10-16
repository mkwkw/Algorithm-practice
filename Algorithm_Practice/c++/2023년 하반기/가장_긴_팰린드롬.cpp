#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//투 포인터
int solution(string s)
{
    int answer = 0;
    int left = 0, right = 1;
    
    //1. s가 1인 경우
    if(s.length()==1){
        return 1;
    }
    
    //2. s가 2이상인 경우 - 팰린드롬이 짝수일 때
    if(s.length()>=2){
        for(int i=0; i<s.length()-1; i++){
            left = i;
            right = i+1;
            
            if(s[left]!=s[right]){
                continue;
            }
            
            while(s[left]==s[right]){
                if(left==0 || right==s.length()-1){
                    break;
                }
                --left;
                ++right;
            }
            if(s[left]==s[right]){
                answer = max(answer, right-(left)+1);  
            }
            else{
                answer = max(answer, right-1-(left+1)+1);
            }
            //cout<<"i "<<i<<' '<<right<<' '<<left<<' '<<answer<<'\n';
        }    
    }
    
    //3. s가 3이상인 경우 - 팰린드롬이 홀수 일 때
    if(s.length()>=3){
        for(int i=1; i<s.length()-1; i++){
            left = i-1;
            right = i+1;
            if(s[left]!=s[right]){
                continue;
            }
            while(s[left]==s[right]){
                if(left==0 || right==s.length()-1){
                    break;
                }
                --left;
                ++right;
            }
            
            if(s[left]==s[right]){
                answer = max(answer, right-(left)+1);  
            }
            else{
                answer = max(answer, right-1-(left+1)+1);
            }
            //cout<<"i "<<i<<' '<<right<<' '<<left<<' '<<answer<<'\n';
        }   
    }
    
    if(answer==0)
        answer = 1;
    
    return answer;
}