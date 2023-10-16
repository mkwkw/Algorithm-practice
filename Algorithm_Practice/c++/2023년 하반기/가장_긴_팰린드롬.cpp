#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//투 포인터
//팰린드롬 길이가 짝수인 경우, 홀수인 경우 나누어서 생각하기
//주의! 다 거쳤는데도 answer == 0 -> answer = 1로 바꿔주어야함.
//1. 팰린드롬 길이가 짝수인 경우 - left=i, right=i+1로 s[left]==s[right]인 경우, left 하나 감소 & right 하나 증가
//2. 팰린드롬 길이가 홀수인 경우 - left=i-1, right=i+1로 s[left]==s[right]인 경우, left 하나 감소 & right 하나 증가
//마지막에 s[left]==s[right] 한 번 더 확인해줌으로써 마지막 글자끼리도 같은지 확인하고, max 길이 구하기
//효율성 케이스 통과!
//최대시간: 대략 2(홀수, 짝수)*2500(s 최대 길이)*1250(s 최대 길이의 1/2) -> 625*10^4이하 
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