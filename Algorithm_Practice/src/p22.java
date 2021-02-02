//백준 1253
//좋다
import java.util.*;
public class p22 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long num[] = new long [n];
		boolean visited[] = new boolean [n];
		
		
		for(int i=0; i<n; i++) {
			num[i] = sc.nextLong();
			visited[i] = false;
		}
		Arrays.sort(num);
		
		
		int count = 0; //좋은 수 개수
		
		
		//배열의 양쪽 끝에서 접근
		for(int i=0; i<n; i++) {
			long goal = num[i];
			
			
			int a = 0; //pointer1
			int b = n-1; //pointer2
			
			while(a<b) {
				long sum = num[a]+num[b]; // 두 수의 합
				
				sum = num[a] + num[b];
				
				if(sum<goal)
					a++;
				else if(sum==goal&& visited[i]==false) { //) {
					//두 수 중에 goal이 들어가면 안 됨
					if(i!=a && i!=b) {
						count++;
						visited[i]=true;
						break;
					}
					if(a==i)
						a++;
					else if(b==i)
						b--;
					
				}
				else{
					b--;
				}
				
			}
		}
		
		System.out.println(count);
		sc.close();
		
	}

}
