#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sosu;
    vector<bool> prime; //인덱스의 수가 소수인지 아닌지
    int t;
    
    cin>>t;

    //두 수를 합쳤을 때, 짝수라면 무조건 소수의 합으로 나타낼 수 있다.
    //두 수를 합쳤을 때, 홀수라면 2+소수로 나타나는 경우만 소수+소수이다.
    //두 수의 합 기준으로 생각하기

    prime.assign(2000001, true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<2000000; i++){
        if(prime[i]){
            for(int j=i*i; j<2000000; j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i=2; i<=2000000; i++){
        if(prime[i]){
            sosu.push_back(i);
        }
    }

    for(int i=0; i<t; i++){
        long long a, b, s;
        
        cin>>a>>b;
        
        s = a+b;

        if(s==2 || s==3){
            cout<<"NO\n";
        }
        else if(s%2==0){ //s가 짝수, 무조건 소수+소수 가능
            cout<<"YES\n";
        }
        else{// s가 홀수, 2+소수인 경우
            bool flag = true;
            s -= 2;
            for(int j=0; j<sosu.size() && (long long)(sosu[j]*sosu[j])<=s; j++){
                if(s%sosu[j]==0){ //소수로 나누어떨어짐 -> 소수가 아님
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }    
}