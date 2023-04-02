#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> eq;
vector<bool> check;
vector<char> num;

string maxNumStr;
string minNumStr;
long long maxNum = 0;
long long minNum = 9999999999;

void backtracking1(int cnt, int n){

    if(cnt==n){
        string res = "";
        long long resN;
        for(int i=0; i<n; i++){
            res += num[i];
        }
        
        resN = stoll(res);

        if(minNum>resN){
            minNum = resN;
            minNumStr = res;
        }
        
        minNum = min(minNum, resN);

        return;
    }

    for(int i=0; i<10; i++){
        if(minNum<9999999999){
            break;
        }
        if(check[i]){
            continue;
        }

        if(eq[cnt-1]=='<'){
            if(num[cnt-1]>i+'0'){
                continue;
            }
        }
        else{
            if(num[cnt-1]<i+'0'){
                continue;
            }
        }
        check[i] = true;
        num[cnt] = i+'0';
        backtracking1(cnt+1, n);
        check[i] = false;
    }

}

void backtracking2(int cnt, int n){

    if(cnt==n){
        string res = "";
        long long resN;
        for(int i=0; i<n; i++){
            res += num[i];
        }
        
        resN = stoll(res);

        if(maxNum<resN){
             maxNum = resN;
             maxNumStr = res;
        }
    
        minNum = min(minNum, resN);

        return;
    }   

    for(int i=9; i>=0; i--){
        if(maxNum>0){
            break;
        }
        if(check[i]){
            continue;
        }

        if(eq[cnt-1]=='<'){
            if(num[cnt-1]>i+'0'){
                continue;
            }
        }
        else{
            if(num[cnt-1]<i+'0'){
                continue;
            }
        }
        check[i] = true;
        num[cnt] = i+'0';
        backtracking2(cnt+1, n);
        check[i] = false;
    }

}

int main(){
    int k;
    cin>>k;

    eq.assign(k, ' ');
    check.assign(10, false);
    num.assign(k+1, ' ');

    for(int i=0; i<k; i++){
        cin>>eq[i];
    }

    //최소 정수는 0에서부터 탐색
    for(int i=0; i<10; i++){
        char c = i+'0';
        num[0] = c;
        check[i] = true;
        backtracking1(1, k+1);
        check[i] = false;
    }
    
    //최대 정수는 9에서부터 탐색
    check.assign(10, false);
    num.assign(k+1, ' ');

    for(int i=9; i>=0; i--){
        if(num[k]!=' '){
            break;
        }
        char c = i+'0';
        num[0] = c;
        check[i] = true;
        backtracking2(1, k+1);
        check[i] = false;
    }

    cout<<maxNumStr<<'\n'<<minNumStr;

}