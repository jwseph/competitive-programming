import java.util.*;
import java.io.*;

public class Day14A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day14.in"));

        List<Character> str = new ArrayList<Character>();
        for (char c: in.next().toCharArray()) str.add(c);
        Map<String, Character> hash = new HashMap<String, Character>();
        while (in.hasNext()) {
            String a = in.next();
            in.next();
            char b = in.next().charAt(0);
            hash.put(a, b);
        }

        for (int t = 0; t < 10; t++) {
            for (int i = 1; i < str.size(); i++) {
                String a = ""+str.get(i-1)+str.get(i);
                str.add(i++, hash.get(a));
            }
        }
        Map<Character, Integer> cnt = new HashMap<Character, Integer>();
        for (Character b: hash.values()) cnt.put(b, 0);
        for (Character b: str) cnt.put(b, cnt.get(b)+1);
        
        System.out.println(Collections.max(cnt.values())-Collections.min(cnt.values()));
    }
}