import java.util.*;
import java.io.*;

public class Day15A {
    private static int compare(List<Integer> a, List<Integer> b) {
        return Integer.compare(a.get(2), b.get(2));
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day15.in"));

        List<String> lines = new ArrayList<String>();
        while (in.hasNext()) lines.add(in.next());
        int n = lines.size();
        int arr[][] = new int[n][n];
        int dst[][] = new int[n][n];
        boolean vst[][] = new boolean[n][n];
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) {
            arr[r][c] = lines.get(r).charAt(c)-'0';
            dst[r][c] = Integer.MAX_VALUE;
        }
        PriorityQueue<List<Integer>> pq = new PriorityQueue<>(Day15A::compare);
        pq.add(Arrays.asList(0, 0, 0));
        while (!pq.isEmpty()) {
            List<Integer> x = pq.remove();
            int r = x.get(0), c = x.get(1), d = x.get(2);
            if (vst[r][c]) continue;
            vst[r][c] = true;
            dst[r][c] = Math.min(dst[r][c], d);
            if (r-1 >= 0) pq.add(Arrays.asList(r-1, c, dst[r][c]+arr[r-1][c]));
            if (c+1 < n) pq.add(Arrays.asList(r, c+1, dst[r][c]+arr[r][c+1]));
            if (r+1 < n) pq.add(Arrays.asList(r+1, c, dst[r][c]+arr[r+1][c]));
            if (c-1 >= 0) pq.add(Arrays.asList(r, c-1, dst[r][c]+arr[r][c-1]));
        }

        System.out.println(dst[n-1][n-1]);
    }
}