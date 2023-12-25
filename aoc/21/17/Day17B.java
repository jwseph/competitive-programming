import java.util.*;
import java.io.*;

public class Day17B {
    private static final int C = 0xff;  // cool number
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day17.in")).useDelimiter("[^\\-0-9]+");
        
        int x1 = in.nextInt(), x2 = in.nextInt();
        int y1 = in.nextInt(), y2 = in.nextInt();
        
        Map<Integer, Set<Integer>> txv = new HashMap<Integer, Set<Integer>>();  // valid number of frames, x velocity
        for (int xv0 = x2; xv0 > 0; xv0--) {  // xv0: initial x velocity
            int x = 0, xv = xv0, t;
            for (t = 0; xv > 0 && x <= x2; t++) {
                if (x1 <= x) {
                    if (!txv.containsKey(t)) txv.put(t, new HashSet<Integer>());
                    txv.get(t).add(xv0);
                }
                x += xv;
                xv--;
            }
            if (x1 <= x && x <= x2) { // xv = 0 and probe is in x interval
                for (; t < C; t++) {  // max C frames
                    if (!txv.containsKey(t)) txv.put(t, new HashSet<Integer>());
                    txv.get(t).add(xv0);
                }
            }
        }
        
        Set<Integer> res = new HashSet<Integer>();
        for (int t: txv.keySet()) {
            for (int yv = y1; yv < 2*(y2-y1+t); yv++) {
                int y = -t*(t+1)/2+yv*t;
                if (y1 <= y && y <= y2) for (int xv: txv.get(t)) res.add(xv+yv*C);  // max yv is C
            }
        }
        
        System.out.println(res.size());
    }
}
