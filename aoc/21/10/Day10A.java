import java.util.*;
import java.io.*;

public class Day10A {
    public static final Map<Character, Character> close = new HashMap<Character, Character>();
    public static final Map<Character, Integer> scores = new HashMap<Character, Integer>();
    static {
        close.put('(', ')');
        close.put('[', ']');
        close.put('{', '}');
        close.put('<', '>');
        scores.put(')', 3);
        scores.put(']', 57);
        scores.put('}', 1197);
        scores.put('>', 25137);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day10.in"));
        
        int res = 0;
        while (in.hasNext()) {
            Deque<Character> s = new ArrayDeque<Character>();  // stack sucks in java
            for (char c: in.next().toCharArray()) {
                if (close.containsKey(c)) {
                    s.addLast(close.get(c));
                    continue;
                }
                if (s.peekLast() == c) {
                    s.removeLast();
                    continue;
                }
                res += scores.get(c);
                break;
            }
        }
        
        System.out.println(res);
    }
}
