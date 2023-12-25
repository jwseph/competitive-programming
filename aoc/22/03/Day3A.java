import java.util.*;
import java.io.*;

public class Day3A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day3.in"));

        int res = 0;
        while (in.hasNext()) {
            String str = in.next();
            int n = str.length()/2;
            String a = str.substring(0, n), b = str.substring(n);
            Set<Character> s = new HashSet<>();
            for (char c: a.toCharArray()) s.add(c);
            for (char c: b.toCharArray()) if (s.contains(c)) {
                res += c < 'a' ? 27+c-'A' : 1+c-'a';
                break;
            }
        }

        System.out.println(res);
    }
}