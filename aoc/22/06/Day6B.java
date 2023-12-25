import java.util.*;
import java.io.*;

public class Day6B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day6.in"));

        int n = 14;
        char[] s = (in.next()+" ").toCharArray();
        Map<Character, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; i++) cnt.merge(s[i], 1, Integer::sum);
        int res = -1;
        for (int i = n; i < s.length; i++) {
            if (cnt.size() == n) {
                res = i;
                break;
            }
            cnt.merge(s[i], 1, Integer::sum);
            char c = s[i-n];
            cnt.put(c, cnt.get(c)-1);
            if (cnt.get(c) == 0) cnt.remove(c);
        }

        System.out.println(res);
    }
}