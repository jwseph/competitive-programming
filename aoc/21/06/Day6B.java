import java.util.*;
import java.io.*;

public class Day6B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day6.in"));
        
        long a[] = new long[9];
        for (String s: in.nextLine().split(",")) {
            a[Integer.parseInt(s)]++;
        }
        for (int t = 0; t < 256; t++) {
            long b = a[0];
            for (int i = 0; i < 8; i++) {
                a[i] = a[i+1];
            }
            a[6] += b;
            a[8] = b;
        }
        System.out.println(Arrays.stream(a).sum());
    }
}
