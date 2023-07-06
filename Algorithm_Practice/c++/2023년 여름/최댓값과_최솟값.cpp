#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * s의 첫문자부터 시작해서(idx=0) 빈칸 나올 때까지 i를 증가시키고 substr(idx, i)
 * 한 숫자 끝나면 idx=i+1로 갱신
*/
string solution(string s) {
    vector<int> num;
    string answer = "";
    int idx = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i]==' ' || i==s.length()-1){
            string n = s.substr(idx, i);
            int m = stoi(n);
            num.push_back(m);
            idx = i+1;
        }
    }
    
    sort(num.begin(), num.end());
    answer += to_string(num[0])+' ';
    answer += to_string(num[num.size()-1]);
    
    return answer;
}