import java.util.*;
import java.io.*;

public class Day6A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day6.in"));

        char[] s = (in.next()+" ").toCharArray();
        Map<Character, Integer> cnt = new HashMap<>();
        for (int i = 0; i < 4; i++) cnt.merge(s[i], 1, Integer::sum);
        int res = -1;
        for (int i = 4; i < s.length; i++) {
            if (cnt.size() == 4) {
                res = i;
                break;
            }
            cnt.merge(s[i], 1, Integer::sum);
            char c = s[i-4];
            cnt.put(c, cnt.get(c)-1);
            if (cnt.get(c) == 0) cnt.remove(c);
        }

        System.out.println(res);
    }
}