#include <iostream>

using namespace std;

int main(){
    string s, answer="";
    int oneCnt = 0, zeroCnt = 0, removedZeroCnt = 0, removedOneCnt = 0;
    cin>>s;

    //0과 1의 자리를 재배치할 수는 없다.
    //00110000 -> 0010
    for(int i=0; i<s.length(); i++){
        if(s[i]=='0'){
            zeroCnt++;
        }
        else{
            oneCnt++;
        }
    }

    //0은 뒤에서부터 zeroCnt/2만큼 지우고, 1은 앞에서부터 oneCnt/2만큼 지우기
    for(int i=s.length()-1; i>=0; i--){
        if(s[i]=='0' && removedZeroCnt<zeroCnt/2){
            s[i]=' ';
            removedZeroCnt++;
            //cout<<s<<'\n';
        }
    }

    for(int i=0; i<s.length(); i++){
        if(s[i]=='1' && removedOneCnt<oneCnt/2){
            s[i]=' ';
            removedOneCnt++;
            //cout<<s<<'\n';
        }
    }

    for(int i=0; i<s.length(); i++){
        if(s[i]!=' '){
            answer += s[i];
        }
    }

    cout<<answer;
}