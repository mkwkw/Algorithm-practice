#include <string>
#include <vector>

using namespace std;

//idx=0이면 각 단어의 첫 번째 문자 의미 - 'a'보다 크면 대문자 / idx>0인데 대문자인 경우에는 소문자로 바꿔주기

string solution(string s) {
    string answer = "";
    
    int idx = 0; //각 단어에서의 인덱스 
    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){
            if(idx==0 && s[i]>='a'){
                s[i] = toupper(s[i]);
            }
            else if(idx>0 && s[i]>='A'){
                s[i] = tolower(s[i]);
            }
            idx++;
        }
        else{
            idx = 0;
        }
    }
    
    answer = s;
    return answer;
}