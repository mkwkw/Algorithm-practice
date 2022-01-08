#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> fib;
stack<int> ans; //정답 저장할 스택 - 큰 수 순서대로 찾아내므로 stack의 LIFO를 이용하여 수를 오름차순으로 출력한다.

//피보나치 수열 만들어서 fib벡터에 저장하기
void make_fib(){ 
    int fib0 = 0;
    int fib1 = 1;
    int nfib = 1;

    fib.push_back(0);
    fib.push_back(1);

    while((fib0+fib1)<=1000000000){
        nfib = fib0+fib1;
        fib.push_back(nfib);
        fib0 = fib1;
        fib1 = nfib;
    }

}

//이분 탐색으로 n 이하의 피보나치 수 중 가장 큰 수 찾아서 리턴
void binary_search(int n){ 
    int left = 0;
    int right = fib.size()-1;
    int mid;

    if(n<1){
        return;
    }

    while(left<=right){
        mid = (left+right)/2;
        
        if(n>=fib[mid] && n<fib[mid+1]){ //break 조건
            break;
        }
        else if(n<fib[mid]){
            right = mid-1;
        }        
        else{
            left = mid+1;
        }
    }

    ans.push(fib[mid]); 
    binary_search(n-fib[mid]);
}

int main(){
    int t, num;
    cin>>t;
    
    make_fib();

    for(int i=0; i<t; i++){
        cin>>num;
        binary_search(num);

        while(!ans.empty()){
            cout<<ans.top()<<' ';
            ans.pop();
        }
        
        cout<<'\n';
    }

}

//1. 0~1000000000까지 피보나치 수 벡터에 저장하기
//2. 이분탐색으로 주어진 수 이하의 피보나치 수 중 가장 큰 수 찾기
//3. 나중에 출력할 스택에 넣기
//4. 2,3반복하고 스택에 넣는 것 끝나면 스택 top 출력하고 pop
//5. 2,3,4 반복 