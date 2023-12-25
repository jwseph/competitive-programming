import java.util.*;
import java.io.*;

public class Day13B {
    private static final int BASE = 10000;
    private static Set<Integer> arr = new HashSet<Integer>();
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day13.in"));

        while (in.hasNext()) {
            String s = in.nextLine();
            if (s.equals("")) break;
            String _s[] = s.split("\\,");
            arr.add(Integer.parseInt(_s[0])*BASE+Integer.parseInt(_s[1]));
        }
        while (in.hasNext()) {
            String _s[] = in.nextLine().split("=");
            char f = _s[0].charAt(_s[0].length()-1);
            int v = Integer.parseInt(_s[1]);
            Set<Integer> arr2 = new HashSet<Integer>();
            if (f == 'x') for (int num: arr) {
                int x = num/BASE, y = num%BASE;
                x = (x < v) ? x : (2*v-x);
                arr2.add(x*BASE+y);
            } else for (int num: arr) {
                int x = num/BASE, y = num%BASE;
                y = (y < v) ? y : (2*v-y);
                arr2.add(x*BASE+y);
            }
            arr = arr2;
        }

        int H = 0, W = 0;
        for (int num: arr) {
            H = Math.max(H, num%BASE+1);
            W = Math.max(W, num/BASE+1);
        }
        boolean res[][] = new boolean[H][W];
        for (int num: arr) res[num%BASE][num/BASE] = true;
        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                System.out.print(res[r][c]?'█':' ');
            }
            System.out.println();
        }
    }
}