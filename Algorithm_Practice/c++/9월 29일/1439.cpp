#include <iostream>
#include <cmath>

using namespace std;

//1 덩어리 개수 세기, 0 덩어리 개수 세기
//1. 1 덩어리 개수 + 0 덩어리 개수 == 1 이면 이미 모든 숫자 같은 상황
//2. 1 덩어리 개수 + 0 덩어리 개수 > 1 이면 min(1 덩어리 개수, 0 덩어리 개수)
int main(){

    string s;
    int one = 0;
    int zero = 0;
    cin>>s;

    //1, 0 덩어리 세기
    for(int i=1; i<s.length(); i++){
        if(s[i-1]=='1' && s[i]=='0'){
            one++;
        }
        else if(s[i-1]=='0' && s[i]=='1'){
            zero++;
        }
    }

    if(s[s.length()-1]=='0'){
        zero++;
    }
    else if(s[s.length()-1]=='1'){
        one++;
    }

    if(one+zero==1){
        cout<<"0";
    }
    else{
        cout<<min(one, zero);
    }
}