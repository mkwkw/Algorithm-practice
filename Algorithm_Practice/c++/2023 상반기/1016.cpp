#include <iostream>
#include <vector>

using namespace std;

int main(){
    //maxNum과 minNum의 차이는 최대 1000000
    //[0+minNum]~[num.size()-1+minNum]
    vector<bool> num; //minNum보다 크거나 같고, maxNum보다 작거나 같은 수가 제곱수로 나누어지는가
    long long minNum, maxNum;
    int answer = 0; 

    cin>>minNum>>maxNum;

    num.assign(1000001, false);

    for(long long i=2; i*i<=maxNum; i++){
        
        long long cnt = minNum/(i*i); //제곱수의 배수 개수
       
        if(minNum%(i*i)==0){
            cnt++;
        }
        
        while(cnt*(i*i)<=maxNum){
            
            if(cnt*(i*i)-minNum>=0){
                num[cnt*(i*i)-minNum] = true;
            }
            cnt++;
            
        }

    }

    for(int i=0; i<=maxNum-minNum; i++){
        if(!num[i]){
            answer++;
        }
    }

    cout<<answer;
}