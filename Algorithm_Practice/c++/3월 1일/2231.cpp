#include <iostream>
#include <string>
using namespace std;

//int -> string ���� �ٲپ �� �ڸ��� ���
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
    //�Է�
    cin >> n;
    //����
    int answer = solution(n);
    //���
    cout << answer;
    return 0;
} 