#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dx[4]={0,1,1,-1};
    int dy[4]={1,-1,0,1};

    int n, a, b, diff, idx;
    bool flag = false;

    cin>>n;

    // a/b
    a = 1; //분자
    b = 1; //분모 
    diff = 0; //차이
    idx=1;

    while(idx<n){
        a = a+dx[0];
        b = b+dy[0];
        idx = idx+1;
        if(idx==n){
            break;
        }

        for(int i=0; i<(1+diff); i++){
            //cout<<"a: "<<a<<" b: "<<b<<'\n';
            a = a+dx[1];
            b = b+dy[1];
            idx = idx+1;
            //cout<<"a: "<<a<<" b: "<<b<<" idx: "<<idx<<'\n';

            if(idx==n){
                flag = true;
                break;
            }
        }

        if(flag){
            break;
        }
        
        a = a+dx[2];
        b = b+dy[2];
        idx = idx+1;
        if(idx==n){
            break;
        }

        for(int i=0; i<(2+diff); i++){
            a = a+dx[3];
            b = b+dy[3];
            idx = idx+1;

            if(idx==n){
                flag = true;
                break;
            }
        }
        
        if(flag){
            break;
        }

        diff += 2;
    }

    cout<<a<<'/'<<b;
}

//구현 - 규칙성 - for문+while문 break 사용 주의