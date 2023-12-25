import java.util.*;
import java.io.*;

public class Day3B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day3.in"));

        int res = 0;
        while (in.hasNext()) {
            Set<Character> s = getLetters(in.next());
            for (int i = 0; i < 2; i++) {
                s.retainAll(getLetters(in.next()));
            }
            for (Character c: s) res += (c < 'a' ? 27+c-'A' : 1+c-'a');
        }

        System.out.println(res);
    }
    private static Set<Character> getLetters(String s) {
        Set<Character> res = new HashSet<>();
        for (char c: s.toCharArray()) res.add(c);
        return res;
    }
}