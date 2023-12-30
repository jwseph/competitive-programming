import java.util.*;
import java.io.*;

public class Day7B {
	public static void main(String[] args) throws FileNotFoundException {
	    Scanner in = new Scanner(new File("Day7.in"));

        List<List<Integer>> A = new ArrayList<>();
        while (in.hasNext()) {
            String s = in.next();
            int b = in.nextInt();
            List<Integer> c = calc(s);
            c.add(b);
            A.add(c);
        }

        Collections.sort(A, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> a, List<Integer> b) {
                for (int i = 0; i < a.size(); i++) {
                    if (a.get(i) != b.get(i)) return a.get(i).compareTo(b.get(i));
                }
                return 0;
            }
        });
        int res = 0;
        for (int i = 0; i < A.size(); i++) {
            res += A.get(i).get(6) * (i+1);
        }
        System.out.println(res);
	}
    static final String tmp = "J23456789TQKA";
    static int rank(String s) {
        List<Integer> cnt = new ArrayList<>();
        for (int i = 0; i < tmp.length(); i++) cnt.add(0);
        for (char c: s.toCharArray()) {
            if (c == 'J') continue;
            int i = tmp.indexOf(c);
            cnt.set(i, cnt.get(i)-1);
        }
        Collections.sort(cnt);
        for (char c: s.toCharArray()) {
            if (c != 'J') continue;
            cnt.set(0, cnt.get(0)-1);
        }
        if (cnt.get(0) == -5) return 7;
        if (cnt.get(0) == -4) return 6;
        if (cnt.get(0) == -3 && cnt.get(1) == -2) return 5;
        if (cnt.get(0) == -3) return 4;
        if (cnt.get(0) == -2 && cnt.get(1) == -2) return 3;
        if (cnt.get(0) == -2) return 2;
        return 1;
    }
    static List<Integer> calc(String s) {
        List<Integer> res = new ArrayList<>();
        res.add(rank(s));
        for (char c: s.toCharArray()) res.add(tmp.indexOf(c));
        return res;
    }
}