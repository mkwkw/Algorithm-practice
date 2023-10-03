#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

//팩토리얼 값 구하는 함수
long long factorial(int n){
    if(n==1){
        return 1;
    }
    
    return n*factorial(n-1);
}

vector<int> solution(int n, long long k) {
    vector<bool> visited;
    vector<int> answer;
    set<int> remainNumSet;
    visited.assign(n+1, false);
    
    int divider = n-1;
    long long nMinus1Factorial = factorial(divider);
    long long kk = k;
    long long order;
    int num, cnt=1;
    vector<int> remainNum;
    
    for(int i=1; i<=n; i++){
        remainNumSet.insert(i);
    }
    
    while(nMinus1Factorial>=2){
        num = kk/nMinus1Factorial+1;
        order = kk%nMinus1Factorial;
        
        if(order==0){
            order = nMinus1Factorial;
            num -= 1;
        }
        //visited[num] = true;
        int idx = 1;
        for(auto s : remainNumSet){
            if(idx++ == num){
                answer.push_back(s);
                visited[s] = true;
                remainNumSet.erase(s);
            }
        }
        //answer.push_back(num);
        
        kk = order;
        nMinus1Factorial = factorial(--divider);
        //cout<<"num "<<num<<" order "<<kk<<'\n';
    }
    
    for(auto s : remainNumSet){
        remainNum.push_back(s);
    }
    
    do{
        if(cnt==kk){
            for(int i=0; i<remainNum.size(); i++){
                answer.push_back(remainNum[i]);
            }
        }
        cnt++;
        
    }while(next_permutation(remainNum.begin(), remainNum.end()));
    
    return answer;
}