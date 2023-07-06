#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> fib;
    int answer = 0;
    
    fib.push_back(0); //F(0)
    fib.push_back(1); //F(1)
    
    for(int i=2; i<=n; i++){
        fib.push_back((fib[i-2]+fib[i-1])%1234567);
    }
    answer = fib[n];
    return answer;
}