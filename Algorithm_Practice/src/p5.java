//น้มุ 15650
//nฐ๚ m 2
import java.util.*;
public class p5 {
	
	private static int n, m;
	private static int answer[] = new int [10];
	
	private static void solve(int level, int num) {
		if(level == m) {
			for(int i=0; i<m; i++) {
				System.out.print(answer[i]+" ");
				
			}
			System.out.println();
		}
		for(int i=num; i<=n; i++) {
			answer[level] = i;
			solve(level+1, i+1);
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		
		solve(0,1);
		sc.close();
	}

}
