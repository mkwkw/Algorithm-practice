#include <iostream>
#include <string>
using namespace std;

//int -> string 으로 바꾸어서 한 자리씩 계산
int solution(int n) {
    int answer = 0;
		for(int i=1; i<=n; i++){
			string num = to_string(i);
			int s = num.size();
			
			int sum=i;
			for(int j=0; j<s; j++){
                sum += num[j]-'0';
			}
			
			if(sum == n){
				answer = i;
				break;
			}
		}
		
    return answer;
} 

int main(void) {
    int n;
    //입력
    cin >> n;
    //연산
    int answer = solution(n);
    //출력
    cout << answer;
    return 0;
} 