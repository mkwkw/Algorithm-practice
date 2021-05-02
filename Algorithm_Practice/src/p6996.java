import java.util.*;
public class p6996 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		
		for(int i=0; i<n; i++) {
			String word1 = sc.next();
			String word2 = sc.next();
			
			if(word1.length()!= word2.length()) {
				System.out.println(word1 +" & "+ word2 +" are NOT anagrams.");
				continue;
			}
			char w1 [] = word1.toCharArray();
			char w2 [] = word2.toCharArray();
			
			Arrays.sort(w1);
			Arrays.sort(w2);
			
			if(Arrays.equals(w1, w2))
				System.out.println(word1 + " & "+word2+" are anagrams.");
			else
				System.out.println(word1 +" & "+ word2 +" are NOT anagrams.");
			
			
		}
		
		
	}

}
