#include <string>
#include <vector>

using namespace std;

//dp: 1칸+n-1칸 & 2칸+n-2칸
long long solution(int n) {
    vector<long long> ways;
    long long answer = 0;
    
    ways.push_back(0); //0칸 
    ways.push_back(1); //1칸 이동방법 1가지
    ways.push_back(2); //2칸 이동방법 2가지
    
    if(n>=3){
        for(int i=3; i<=n; i++){
            ways.push_back((ways[i-1]+ways[i-2])%1234567); 
        }
    }
    
    answer = ways[n];
    
    return answer;
}