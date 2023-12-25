import java.util.*;
import java.io.*;

public class Day6A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day6.in"));
        
        int a[] = new int[9];
        for (String s: in.nextLine().split(",")) {
            a[Integer.parseInt(s)]++;
        }
        for (int t = 0; t < 80; t++) {
            int b = a[0];
            for (int i = 0; i < 8; i++) {
                a[i] = a[i+1];
            }
            a[6] += b;
            a[8] = b;
        }
        
        System.out.println(Arrays.stream(a).sum());
    }
}
