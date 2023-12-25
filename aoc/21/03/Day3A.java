import java.util.*;
import java.io.*;

public class Day3A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day3.in"));
        
        final int n = 12;  // binary length
        int a[] = new int[n];  // number of 1s per bit (reverse order from string)
        int i;
        for (i = 0; in.hasNext(); i++) {
            String s = in.next();
            for (int c = 0; c < n; c++) if (s.charAt(n-1-c) == '1') {
                a[c]++;
            }
        }
        int eps = 0;
        for (int c = 0; c < n; c++) if (a[c] > i/2) {  // can both 1 and 0 be equally common? sus
            eps ^= 1<<c;
        }
        int gam = ((1<<n)-1)^eps;
        
        System.out.println(eps*gam);
    }
}
