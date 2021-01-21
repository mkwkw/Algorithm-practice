//น้มุ 9663
//n-queen
import java.util.*;
public class p6 {

	private static int n;
	private static boolean isused1[] = new boolean [40];
	private static boolean isused2[] = new boolean [40];
	private static boolean isused3[] = new boolean [40];
	private static int count;
	private static void solve(int level) {
		if(level == n)
			count++;
		for(int i=0; i<n; i++) {
			if(isused1[i] || isused2[i+level] || isused3[level-i+n-1])
				continue;
			isused1[i] = true;
			isused2[i+level] = true;
			isused3[level-i+n-1] = true;
			solve(level+1);
			isused1[i] = false;
			isused2[i+level] = false;
			isused3[level-i+n-1] = false;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		solve(0);
		System.out.println(count);
		sc.close();
	}

}
