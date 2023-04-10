#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> money;
    int n, sum = 0, total;
    cin>>n;

    money.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>money[i];
        sum += money[i];
    }

    sort(money.begin(), money.end());

    cin>>total;

    //1. 총합이 주어진 예산 이하인 경우
    //2. 총합이 주어진 예산 초과인 경우
    if(total>=sum){
        cout<<money[n-1];
    }
    else{ //상한액 찾아야함

        //이분 탐색
        /**
         * left:1, right: money[n-1]
         * mid = (left+right)/2
         * if(mid*n>total){
         *      right = mid-1;
         * }
         * else if(mid*n<total){
         *      left = mid+1;
         * }
         * 
        */

        int left = 1;
        int right = money[n-1];
        int mid;
        int tempSum;

        while(left<right){
            mid = (left+right)/2;
            tempSum = 0;

            for(int i=0; i<n; i++){
                if(money[i]<mid){
                    tempSum += money[i];
                }
                else{
                    tempSum += mid;
                }
            }

            //cout<<"left: "<<left<<" right: "<<right<<" mid: "<<mid<<" tempSum: "<<tempSum<<'\n';

            if(tempSum>total){
                right = mid-1;
            }
            else if(tempSum<total){
                left = mid+1;
            }
            else{
                break;
            }
        }

        if(tempSum<total){
            while(tempSum<total){
                mid++;
                tempSum = 0;
                for(int i=0; i<n; i++){
                    if(money[i]<mid){
                        tempSum += money[i];
                    }
                    else{
                        tempSum += mid;
                    }
                }

                //위의 while문에서 tempSum이 total보다 커져서 나왔을 때, 다시 mid를 줄여서 tempSum이 total보다 작아지게 만들어야한다.
                if(tempSum>total){
                    mid--;
                    break;
                }
            }
        }
        else if(tempSum>total){
            while(tempSum>total){
                mid--;
                tempSum = 0;
                for(int i=0; i<n; i++){
                    if(money[i]<mid){
                        tempSum += money[i];
                    }
                    else{
                        tempSum += mid;
                    }
                }
            }
        }


        cout<<mid;
        
    }


    

}