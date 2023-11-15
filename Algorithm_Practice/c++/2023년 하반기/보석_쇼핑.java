import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(String[] gems) {
        //1. 보석의 종류 세기
        //2. 보석의 종류~전체 진열대 크기까지 길이 늘려가면서 탐색
        int[] answer = new int[2];
        Set<String> gemType = new HashSet<>();
        
        for(int i=0; i<gems.length; i++){
            gemType.add(gems[i]);
        }
        
        //보석 종류
        int gemTypes = gemType.size();
        System.out.println(gemTypes);
        for(int i=gemTypes; i<=gems.length; i++){
            for(int j=0; j<=gems.length-i; j++){
                Set<String> temp = new HashSet<>();
                for(int k=j; k<j+i; k++){
                    temp.add(gems[k]);
                }
                if(temp.size()==gemTypes){
                    answer[0] = j+1;
                    answer[1] = j+i;
                    return answer;
                }
            }
        }
        
        return answer;
    }
}