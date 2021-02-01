//백준 1484
//다이어트
//two pointer
import java.util.*;
public class p21 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int g = sc.nextInt();
		
		long num [] = new long [200001]; 
		
		num[0]=0;
		for(int i=1; i<=200000; i++) {
			num[i] = i*i;	
		}
		

		long dif = 0; //차
		int a = 1; //pointer1
		int b = 1; //pointer2
		int ans = -1;
		while(true) {
			
			if(b-a==1 && dif > g) {
				
				break;
			}
			dif = num[b] - num[a];
			if(dif >= g) {
				a++;
			}
			else  {
				b++;			
			}
			
			if(dif == g) {
				ans = (int)Math.sqrt(num[b]);
				System.out.println(ans);
				b++;
			}
			
		}
		if(ans==-1)
			System.out.println("-1");
		
			
		sc.close();
		

	}

}
