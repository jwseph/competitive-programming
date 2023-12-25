import java.util.*;
import java.io.*;

public class Day13A {
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
        String _s[] = in.nextLine().split("=");
        char f = _s[0].charAt(_s[0].length()-1);
        int v = Integer.parseInt(_s[1]);
        Set<Integer> res = new HashSet<Integer>();
        if (f == 'x') for (int num: arr) {
            int x = num/BASE, y = num%BASE;
            x = (x < v) ? x : (2*v-x);
            res.add(x*BASE+y);
        } else for (int num: arr) {
            int x = num/BASE, y = num%BASE;
            y = (y < v) ? y : (2*v-y);
            res.add(x*BASE+y);
        }

        System.out.println(res.size());
    }
}