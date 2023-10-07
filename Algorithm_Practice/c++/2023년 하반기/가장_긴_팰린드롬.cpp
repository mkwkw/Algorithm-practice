#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//정확성 통과
//시간초과
int solution(string s)
{
    string s1, s2;
    int answer=1;
    
    reverse(s1.begin(), s1.end());
    
    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=s.length()-i; j++){
            s1 = s.substr(i, j);
            s2 = s1;
            reverse(s2.begin(), s2.end());
            
            if(s1==s2 && answer<s1.length()){
                answer = s1.length();
            }
        }
    }
    
    return answer;
}