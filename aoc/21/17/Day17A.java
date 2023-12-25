import java.util.*;
import java.io.*;

public class Day17A {
    private static final int C = 0xff;  // cool number
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day17.in")).useDelimiter("[^\\-0-9]+");
        
        int x1 = in.nextInt(), x2 = in.nextInt();
        int y1 = in.nextInt(), y2 = in.nextInt();
        
        Set<Integer> txv = new HashSet<Integer>();  // valid number of frames, x velocity
        for (int xv0 = x1; xv0 > 0; xv0--) {  // xv0: initial x velocity
            int x = 0, xv = xv0, t;
            for (t = 0; xv > 0 && x <= x2; t++) {
                if (x1 <= x) txv.add(t);
                x += xv;
                xv--;
            }
            if (x1 <= x && x <= x2) { // xv = 0 and probe is in x interval
                for (; t < C; t++) txv.add(t);  // max C frames
            }
        }
        
        int res = Integer.MIN_VALUE;
        for (int t: txv) {
            for (int yv = y1; yv < 2*(y2-y1+t); yv++) {
                int y = -t*(t+1)/2+yv*t;
                int my = 0;
                if (yv > 0) {
                    int t_ = (2*yv-1)/2;
                    my = -t_*(t_+1)/2+yv*t_;
                }
                if (y1 <= y && y <= y2) res = Math.max(res, my);
            }
        }
        
        System.out.println(res);
    }
}
