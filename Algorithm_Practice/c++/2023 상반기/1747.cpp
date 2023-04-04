#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, answer = 0;
    cin>>n;

    if(n==1 || n==2){ 
        answer = 2;
        cout<<answer;
        return 0;
    }

    //소수: 2, 3, 5, 7
    //한 자리수는 그 자체가 팰린드롬수
    for(int i=n; i<=1000000000; i++){
        bool flag = true;
        for(int j=2; j<=(int)sqrt(i); j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }

        
        if(flag){ //소수
            //펠린드롬수 검사
            string numStr = to_string(i);
            int len = numStr.length();
            
            bool flag1 = true;
            for(int i=0; i<len/2; i++){ //양끝에서 점점 가운데로 오면서 쌍으로 비교
                if(numStr[i]!=numStr[len-1-i]){
                    flag1 = false;
                    break;
                }
            }
            if(flag1){
                answer = i;
                break;
            }            
        }
    }

    cout<<answer;
}