#include <iostream>
#include <vector>

using namespace std;

//dp이용

double maxMul(vector<double> &v){
    vector<double> dp(v.size());
    dp[0]=v[0];
    for(int i=1; i<v.size(); i++){
        dp[i]=v[i]*dp[i-1];
    }
}

int main(){
    vector<double> v;
    int n;

    cin>>n;
    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    double answer = maxMul(v);
    cout<<answer;

}