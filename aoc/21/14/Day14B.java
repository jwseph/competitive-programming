import java.util.*;
import java.io.*;

public class Day14B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day14.in"));

        Map<String, Long> cnt = new HashMap<String, Long>();
        Map<String, Character> key = new HashMap<String, Character>();
        char cs[] = in.next().toCharArray();
        while (in.hasNext()) {
            String a = in.next();
            in.next();
            char b = in.next().charAt(0);
            key.put(a, b);
            cnt.put(a, 0L);
        }
        for (int i = 1; i < cs.length; i++) {
            cnt.merge(""+cs[i-1]+cs[i], 1L, Long::sum);
        }
        for (int t = 0; t < 40; t++) {
            Map<String, Long> _cnt = new HashMap<String, Long>();
            for (Map.Entry<String, Long> e: cnt.entrySet()) {
                String s = e.getKey();
                Long v = e.getValue();
                Character c = key.get(s);
                _cnt.merge(""+s.charAt(0)+c, v, Long::sum);
                _cnt.merge(""+c+s.charAt(1), v, Long::sum);
            }
            cnt = _cnt;
        }
        Map<Character, Long> res = new HashMap<Character, Long>();
        for (Map.Entry<String, Long> e: cnt.entrySet()) {
            for (Character c: e.getKey().toCharArray()) {
                res.merge(c, e.getValue(), Long::sum);
            }
        }
        res.merge(cs[0], 1L, Long::sum);
        res.merge(cs[cs.length-1], 1L, Long::sum);
        
        System.out.println((Collections.max(res.values())-Collections.min(res.values()))/2);
    }
}