import java.util.*;
import java.io.*;

public class Day1B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day1.in"));
        
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt();
        int res = 0;
        while (in.hasNextInt()) {
            int d = in.nextInt();
            if (d > a) res++;
            a = b;
            b = c;
            c = d;
        }
        
        System.out.println(res);
    }
}
