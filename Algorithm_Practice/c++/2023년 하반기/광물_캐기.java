import java.io.*;

//백트래킹, 재귀
//다이아 곡괭이 사용하는 경우, 철 곡괭이 사용하는 경우, 돌 곡괭이 사용하는 경우 모두 탐색
//주의! 인자값 받는 변수를 새로 선언해서 중간에 값이 바뀌어서 다음 재귀로 들어가지 않도록 주의하기
class Solution {
    public int countTired(String tool, String mineral){
        
        if(tool.equals("iron")){
            if(mineral.equals("diamond")){
                return 5;
            }
        }
        else if(tool.equals("stone")){
            if(mineral.equals("diamond")){
                return 25;
            }
            else if(mineral.equals("iron")){
                return 5;
            }
        }
        
        return 1;
    }
    
    public int answer = 25*50;
    
    public void backtracking(int diamondCnt, int ironCnt, int stoneCnt, int mineralIdx, String[] minerals, int tired){
        //System.out.println("diamond 곡괭이 "+diamondCnt+" iron 곡괭이 "+ironCnt+" 돌 곡괭이 "+stoneCnt+" "+mineralIdx+" 피로도 "+tired);
        
        //곡괭이를 다 썼을 때
        if(diamondCnt==0 && ironCnt==0 && stoneCnt==0){
            answer = Math.min(answer, tired);
            return;
        }
        
        //광물을 다 캤을 때
        if(mineralIdx>=minerals.length){
            answer = Math.min(answer, tired);
            return;
        }
        
        if(diamondCnt>0){
            //System.out.println("mineralIdx "+mineralIdx);
            int newTired = tired;
            int newMineralIdx = mineralIdx;
            for(int i=0; i<5; i++){
                if(newMineralIdx+i>=minerals.length){
                    //System.out.println("answer "+answer);
                    answer = Math.min(answer, newTired);
                    break;
                }
                newTired += countTired("diamond", minerals[newMineralIdx+i]);
            }
            newMineralIdx = mineralIdx + 5;
            backtracking(diamondCnt-1, ironCnt, stoneCnt, newMineralIdx, minerals, newTired);
        }
        if(ironCnt>0){
            //System.out.println("mineralIdx "+mineralIdx);
            int newTired = tired;
            int newMineralIdx = mineralIdx;
            for(int i=0; i<5; i++){
                if(newMineralIdx+i>=minerals.length){
                    answer = Math.min(answer, newTired);
                    break;
                }
                newTired += countTired("iron", minerals[newMineralIdx+i]);
            }
            newMineralIdx = mineralIdx + 5;
            backtracking(diamondCnt, ironCnt-1, stoneCnt, newMineralIdx, minerals, newTired);
        }
        if(stoneCnt>0){
            //System.out.println("mineralIdx "+mineralIdx);
            int newTired = tired;
            int newMineralIdx = mineralIdx;
            for(int i=0; i<5; i++){
                if(newMineralIdx+i>=minerals.length){
                    answer = Math.min(answer, newTired);
                    break;
                }
                newTired += countTired("stone", minerals[newMineralIdx+i]);
            }
            newMineralIdx = mineralIdx + 5;
            backtracking(diamondCnt, ironCnt, stoneCnt-1, newMineralIdx, minerals, newTired);
        }
    }
    
    public int solution(int[] picks, String[] minerals) {
        
        backtracking(picks[0], picks[1], picks[2], 0, minerals, 0);
        
        return answer;
    }
}