#include <iostream>
#include <vector>

using namespace std;

int prime(int n, int k){
    vector<bool> is_prime(n + 1, true);
    int cnt = 0; //카운트 변수
    //제곱근까지 검사할 경우 반례: k번째 지워지는 수가 제곱근 이상의 소수일 경우
    //따라서 이 문제에서는 꼭 n까지 돌려야 함
    for (int i = 2; i <= n; i++) { 
        if (is_prime[i]) { //i가 소수라면
            for (int j = i; j <= n; j += i) { //이 문제에서 i번째도 지우는 수에 포함하므로 i부터 i의 배수 지움
                if (!is_prime[j]) //이미 지워진 수라면 넘어감
                    continue;
                
                is_prime[j] = false; //i의 배수를 제거
                if (++cnt == k)
                    return j; //k번째 지우는 수 리턴
            }
        }
    }
    //k번째 지우는 수 없다면 -1 리턴
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, answer;

    cin>>n>>k;

    answer = prime(n,k);

    cout<<answer;
}

//set으로 구현할까? -> 순회 및 비교가 번거로움
//queue로 구현할까? -> 시간초과 발생 //pop과 push 계속 반복
//vector<bool>을 선언하고 인덱스를 숫자처럼 생각해서 2중 for 문으로 소수 p 설정 및 p의 배수 지우기
//해당 인덱스가 지워진다/지워진 인덱스이다 = false