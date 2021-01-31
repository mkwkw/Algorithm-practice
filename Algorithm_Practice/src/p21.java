//백준 1484
//다이어트
//two pointer
import java.util.*;
public class p21 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int g = sc.nextInt();
		
		int num [] = new int [100001]; 
		
		num[0]=0;
		for(int i=1; i<=100000; i++) {
			num[i] = i*i;	
		}
		

		int dif = 0; //차
		int a = 1; //pointer1
		int b = 1; //pointer2
		int ans = 0;
		while(true) {
			
			if(b >= 100000) {
				
				break;
			}
			dif = num[b] - num[a];
			if(dif > g) {
				a++;
			}
			else if(dif<g) {
				b++;			
			}
			
			if(dif == g) {
				ans = (int)Math.sqrt(num[b]);
				System.out.println(ans);
				b++;
			}
			
		}
		if(ans==0)
			System.out.println(-1);
		
			
		sc.close();
		

	}

}
