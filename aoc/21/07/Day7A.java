import java.util.*;
import java.io.*;

public class Day7A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day7.in"));
        
        String _a[] = in.nextLine().split(",");
        int a[] = new int[_a.length];
        for (int i = 0; i < a.length; i++) a[i] = Integer.parseInt(_a[i]);
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for (int x: a) {
            min = Math.min(min, x);
            max = Math.max(max, x);
        }
        int res = Integer.MAX_VALUE;
        for (int i = min; i <= max; i++) {
            int sum = 0;
            for (int x: a) sum += Math.abs(x-i);
            res = Math.min(res, sum);
        }
        
        System.out.println(res);
    }
}
