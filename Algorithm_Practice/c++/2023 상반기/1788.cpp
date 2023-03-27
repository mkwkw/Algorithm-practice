#include <iostream>
//#include <vector>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    //vector<int> f;
    map<int, int> m; //인덱스에 음수가 들어갈 수 있어야하고 키 값은 중복되지 않으므로 map 사용

    cin>>n;

    //f.assign(2000000000, 0);

    //f[1000000000]=0;
    //f[1000000001]=1;

    m[0]=0;
    m[1]=1;
    m[-1]=1;

    if(n>=2){
        for(int i=2; i<=n; i++){
            m[i] = (m[i-1]+m[i-2])%(1000000000);
        }
    }
    else if(n<0){
        for(int i=-1; i>=n; i--){
            m[i] = (m[i+2]-m[i+1])%(1000000000);
        }
    }

    if(m[n]>0){
        cout<<"1\n";
    }
    else if(m[n]==0){
        cout<<"0\n";
    }
    else{
        cout<<"-1\n";
    }

    cout<<abs(m[n]);

    //이렇게 하면 메모리 초과 발생

    //n이 양수 f(n) = f(n-1)+f(n-2)
    //f(n-2) = f(n)-f(n-1)
    //f(n) = f(n+2)-f(n+1)
    //map으로?
    // if(n<0){
    //     for(int i=999999999; i>=(n+1000000000); i--){
    //         f[i] = (f[i+2]-f[i+1])%(1000000000);
    //     }
    // }
    // else if(n>0){
    //     for(int i=1000000002; i<=(n+1000000000); i++){
    //         f[i] = (f[i-1]+f[i-2])%(1000000000);
    //         //cout<<i<<' '<<i-1<<' '<<i-2<<'\n';
    //         //cout<<f[i]<<' '<<f[i-1]<<' '<<f[i-1]<<'\n';
    //     }
    // }

    // if(f[n+1000000000]>0){
    //     cout<<"1\n";
    // }
    // else if(f[n+1000000000]==0){
    //     cout<<"0\n";
    // }
    // else{
    //     cout<<"-1\n";
    // }

    // cout<<abs(f[n+1000000000]);

}