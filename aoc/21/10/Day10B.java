import java.util.*;
import java.io.*;

public class Day10B {
    public static final Map<Character, Character> close = new HashMap<Character, Character>();
    public static final Map<Character, Long> scores = new HashMap<Character, Long>();
    static {
        close.put('(', ')');
        close.put('[', ']');
        close.put('{', '}');
        close.put('<', '>');
        scores.put(')', 1L);
        scores.put(']', 2L);
        scores.put('}', 3L);
        scores.put('>', 4L);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day10.in"));
        
        List<Long> res = new ArrayList<Long>();
        while (in.hasNext()) {
            Deque<Character> s = new ArrayDeque<Character>();  // stack sucks in java
            boolean corrupted = false;
            for (char c: in.next().toCharArray()) {
                if (close.containsKey(c)) {
                    s.addLast(close.get(c));
                    continue;
                }
                if (s.peekLast() == c) {
                    s.removeLast();
                    continue;
                }
                corrupted = true;
                break;
            }
            if (corrupted) continue;
            long score = 0;
            while (s.size() > 0) {
                score = score*5+scores.get(s.peekLast());
                s.removeLast();
            }
            res.add(score);
        }
        
        Collections.sort(res);
        System.out.println(res.get(res.size()/2));
    }
}
