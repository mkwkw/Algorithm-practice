import java.util.*;
import java.io.*;

//map, 구현
//중복되는 seller에 대해서 amount를 합산하였으나, 이렇게 하면 안됨. - 뒤에 있는 추천인에게 주는 수수료가 달라진다!
//100원 10번 -> 10원 10번 -> 1원 10번 -> 0원 10번 
//1000원 -> 100원 -> 10원 -> 1원
class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        
        //추천 관계, 판매 금액, 추천해서 얻은 금액 - map으로 구현
        //1. 추천 관계 map으로 저장
        //2. 판매 금액의 10%를 추천인에게 줌 - 추천한 사람이 center일 때까지 반복
        
        Map<String, String> people = new HashMap<>(); //추천 받은 사람, 추천한 사람
        Map<String, Integer> sold = new HashMap<>(); //판매자, 판매 금액
        Map<String, Integer> referMoney = new HashMap<>(); //추천해서 얻은 금액
        
        //1. 추천 관계 저장 및 금액 초기화
        for(int i=0; i<enroll.length; i++){
            people.put(enroll[i],referral[i]);
            sold.put(enroll[i], 0);
            referMoney.put(enroll[i],0);
        }
        
        //2. 판매 금액 90% 적용 및 10%는 추천해서 얻은 금액에 저장 & 추천한 사람에게 10% 주는 것 반복
        for(int i=0; i<seller.length; i++){
            
            Integer fee = amount[i]*10;
            String peo = seller[i];
            
            sold.put(peo, sold.get(peo)+(amount[i]*90));
            
            String referringPerson = people.get(peo); //추천인
            String referredPerson = peo; //추천 받은 사람
            
            while(fee>0){
                
                if(referringPerson.equals("-")){
                    break;
                }
                
                if(fee*0.1>=1)
                    referMoney.put(referringPerson, referMoney.get(referringPerson)+(fee-fee/10));
                else
                    referMoney.put(referringPerson, referMoney.get(referringPerson)+fee);
                    
                fee = fee/10;

                referredPerson = referringPerson;
                referringPerson = people.get(referringPerson);
                
            }
                    
        }
        
        for(int i=0; i<enroll.length; i++){
            answer[i] = sold.get(enroll[i])+referMoney.get(enroll[i]);
        }
        
        return answer;
    }
}