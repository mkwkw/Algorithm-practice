#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    int left = 1; 
    int right = 0; //diffs[i]의 최댓값
    int level = 0;
    long long time = 0;
    
    for(int i=0; i<diffs.size(); i++)
    {
        right = max(right, diffs[i]);
        //cout<<ll_diffs[i]<<' ';
    }
    
    while(left<=right){
        level = (left+right)/2;
        time = 0;     
        
        for(int j=0; j<diffs.size(); j++)
        {
            if(diffs[j]<=level)
            {
                time += (long long)times[j];
            }
            else
            {
                if(j>0)
                {
                    time += (long long)((diffs[j]-level)*(times[j]+times[j-1])+times[j]);
                }
                else
                {
                    time += (long long)((diffs[j]-level)*(times[j])+times[j]);
                }
            }
        }
        //cout<<"level: "<<level<<" time: "<<time<<'\n';
        if(time<=limit)
        {
            answer = level;
            
            if(time<limit)
            {
                right = level-1;
            }
            else
            {
                break;
            }
        }
        else if(time>limit)
        {
            left = level+1;
        }
        else
        {
            break;
        }       
        
    }
    
    return answer;
}