#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//이분탐색
//long long 보고 데이터 크기가 클 수 있음을 생각하고 시간 절약 생각 -> 이분탐색 고려, 정렬
//주의! 같은 무게의 사람들이 3명 이상일 때의 처리법
long long solution(vector<int> weights) {
    vector<pair<int,int>> ratio = {{1,1}, {3,4}, {2,3}, {1,2}};
    long long answer = 0;
    
    //오름차순 정렬 - 이분탐색 위해서
    sort(weights.begin(), weights.end());
    
    for(int i=0; i<weights.size()-1; i++){
        
        int a = weights[i];
        int b;
        for(int j=0; j<4; j++){
            if(a%ratio[j].first!=0){
                continue;
            }
            
            b = a*((double)ratio[j].second/(double)ratio[j].first);
            
            // if(b>weights[weights.size()-1]){
            //     break;
            // }
            
            //이분탐색
            int left = i+1;
            int right = weights.size()-1;
            int mid;
            
            while(left<=right){
                mid = (left+right)/2;
                if(weights[mid]<b){
                    left = mid+1;
                }
                else if(weights[mid]>b){
                    right = mid-1;
                }
                
                if(weights[mid]==b){
                    answer++;
                    
                    //같은 무게인 것들이 더 있나 탐색 - 정렬되어있으므로 mid의 왼쪽으로 쭉 탐색, 오른쪽으로 쭉 탐색
                    // 100, 100, 100, 100, 200
                    //왼쪽
                    for(int k=mid-1; k>=i+1; k--){
                        if(weights[k]==b){
                            answer++;
                        }
                    }
                    //오른쪽
                    for(int k=mid+1; k<weights.size(); k++){
                        if(weights[k]==b){
                            answer++;
                        }
                    }
                    break;
                }
            }
        }    
    }
    
    return answer;
}