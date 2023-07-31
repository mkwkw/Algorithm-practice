#include <string>
#include <vector>

using namespace std;

//규칙성 찾기
vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n>s){
        answer.push_back(-1);
        return answer;
    }
    
    //n=3, s=11
    //11/3 = 3 -> answer={3}
    //s = 11 - (11/3) = 8
    //8/2 = 4 -> answer={3,4}
    //s = 8 - (8/2) = 4
    //4/1 = 4 -> answer={3,4,4}
    for(int i=0; i<n; i++){
        answer.push_back(s/(n-i));
        s -= s/(n-i);
    }
    
    return answer;
}