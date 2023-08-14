#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//진수 변환
//reverse는 algorithm 라이브러리 소속 메서드
string numToNStr(int num, int n){
    string str = "";
    
    while(num>0){
        char ch;
        switch(num%n){
            case 10:
                ch = 'A';
                break;
            case 11:
                ch = 'B';
                break;
            case 12:
                ch = 'C';
                break;
            case 13:
                ch = 'D';
                break;
            case 14:
                ch = 'E';
                break;
            case 15:
                ch = 'F';
                break;
            default:
                ch = num%n+'0';
                break;
        }
        //cout<<num%n<<" ch: "<<ch<<'\n';
        str += ch;
        num /= n;
        
    }
    
    reverse(str.begin(), str.end());
    
    //cout<<"str: "<<str<<'\n';
    
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "", temp = "0";
    
    for(int i=1; i<=t*m; i++){
        temp += numToNStr(i, n);
        //cout<<"temp: "<<temp<<'\n';
    }
    
    for(int i=p-1; i<m*t; i+=m){
        answer += temp[i];
    }
    
    //cout<<temp;
    
    return answer;
}