#include <string>
#include <vector>
#include <iostream>

using namespace std;

//구현, 문자열
//주의! i개씩 자르고 난 후, 나머지 글자들
//i개씩 잘라서 이전 문자열과 비교
int solution(string s) {
    string answerStr = "";
    int answer = 1001;
    
    for(int i=s.length(); i>=1; i--){
        int totalCnt = 0;
        int cnt = 1;
        string prevStr = "";
        string str = "";
        
        int lastIdx = s.length()-i+1;
        for(int j=0; j<s.length(); j+=i){
            if(j+i-1>=s.length()){
                lastIdx = j;
                break;
            }
            
            string temp = s.substr(j,i);
            //cout<<prevStr<<' '<<temp<<'\n';
            
            if(j==0){
                prevStr = temp;
            }
            else if(j>0 && prevStr==temp){
                cnt += 1;
            }
            else if(j>0 && prevStr!=temp){
                totalCnt += i;
                if(cnt>1){
                    totalCnt += to_string(cnt).length();
                    str += to_string(cnt);
                }
                
                str += prevStr;
                prevStr = temp;
                cnt = 1;
            }       
        
        }
        
        if(s.length()%i!=0){
            str += s.substr(s.length()-1-s.length()%i+1);
        }
        if(cnt>1){
            str += to_string(cnt);
        }
        str += prevStr;
        totalCnt += s.length()%i;
        
        //cout<<str<<'\n';
        //cout<<"totalCnt "<<totalCnt<<'\n';
        answer = min(answer, (int)str.length());
    }
    
    return answer;
}