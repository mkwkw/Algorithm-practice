//팀대항전
//4번
//브루트포스
//1.가격 증가->최대 이익 더이상 증가하지 않을 때의 금액 
//한 사람에게 팔았을 때 이익
//2.이익이 없을 때 0출력
import java.io.*;
public class p43 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		
		int price[] = new int [n]; //최대 금액
 		int deliver[] = new int [n]; //배송비
 		int profit[] = new int [n]; //한 사람당 이익
 		
 		int result = 1; //최대 이익을 만들어주는 가격
 		int max = 0; //최대 이익
 		int answer = 0; //정답
 		int maxprofit = 0; 
 		for(int i=0; i<n; i++) {
 			String brr[] = br.readLine().split(" ");
 			price[i] = Integer.parseInt(brr[0]);
 			deliver[i] = Integer.parseInt(brr[1]);
 			profit[i] = price[i]-deliver[i];
 			if(profit[i]>maxprofit)
 				maxprofit=profit[i];
 		}
 		
 		
 		
 		while(result<=maxprofit) {
 			int sum=0;
 			for(int i=0; i<n; i++) {
 				if(result<=profit[i])
 					sum += result;
 				else
 					continue;
 			}
 			System.out.println("합: "+sum);
 			System.out.println("제시 가격: "+result);
// 			if(max>=sum)
// 				break;
 			
 			if(max<sum) {
 				max=sum;
 				answer = result;
 			}
 			System.out.println("최대 이익: "+max);
 			
 			result++;
 			System.out.println();
 			
 			if(answer == 1)
 				answer = 0;
 		}
 		
 		System.out.println(answer);
		

	}

}
