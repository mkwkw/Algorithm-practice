import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] gems) {
        //1. 보석의 종류 세기
        //2. 투 포인터
        int[] answer = new int[2];
        answer[0] = 1;
        answer[1] = gems.length;
        Set<String> gemType = new HashSet<>();
        
        for(int i=0; i<gems.length; i++){
            gemType.add(gems[i]);
        }
        
        //보석 종류
        int gemTypes = gemType.size();
        
        //투 포인터
        int start = 0;
        int end = 0;
        
        while(start<gems.length && end<gems.length){
            //System.out.println(start+" "+end);
            Set<String> set = new HashSet<>();
            for(int i=start; i<=end; i++){
                set.add(gems[i]);
            }
            if(set.size()<gemTypes){
                end++;
            }
            else if(set.size()==gemTypes){
                if(end-start<answer[1]-answer[0]){
                    answer[0] = start+1;
                    answer[1] = end+1;
                }
                else if(end-start==answer[1]-answer[0]){
                    if(start+1<answer[0]){
                        answer[0] = start+1;
                        answer[1] = end+1;
                    }
                }
                start++;
            }
        }
        
        return answer;
    }
}