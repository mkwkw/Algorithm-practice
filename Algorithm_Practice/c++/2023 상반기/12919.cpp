#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
bool answer = false;


//1. s->t : s���� �Ź� A �ٿ�����,  B �ٿ������� -> �ð� �ʰ�
//2. t->s : t�� �� �� ���ڰ� B�� ���, �� �� ���ڰ� A�� ��� ����� ó���� �� ����!
void recur(string str){
    //cout<<str<<'\n';

    if(answer){
        return;
    }
    
    if(str.length() == s.length()){
        if(str == s){
            answer = true;
        }
        else{
            answer = false;
        }
        return;
    }

    if(str[str.length()-1] == 'A'){
        string tmp = str;
        tmp.erase(tmp.length()-1, 1);
        recur(tmp);
    }

    //cout<<"st: "<<str<<'\n';
    if(str[0]=='B'){
        string tmp = str;
        tmp.erase(0, 1);
        
        reverse(tmp.begin(), tmp.end());
        recur(tmp);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>s>>t;

    recur(t);
   
    cout<<answer;
}