import java.util.*;
import java.io.*;

public class Day8B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day8.in"));
        
        List<String> lines = new ArrayList<>();
        while (in.hasNext()) lines.add(in.next());
        int n = lines.size();
        int[][] arr = new int[n][n];
        for (int r = 0; r < n; r++) {
            char[] cs = lines.get(r).toCharArray();
            for (int c = 0; c < n; c++) {
                arr[r][c] = cs[c]-'0';
            }
        }

        int res = -1;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                int cnt = 1;
                int i = r-1;
                for (; 0 < i && arr[i][c] < arr[r][c]; i--);
                cnt *= r-i;
                i = r+1;
                for (; i < n-1 && arr[i][c] < arr[r][c]; i++);
                cnt *= i-r;
                i = c-1;
                for (; 0 < i && arr[r][i] < arr[r][c]; i--);
                cnt *= c-i;
                i = c+1;
                for (; i < n-1 && arr[r][i] < arr[r][c]; i++);
                cnt *= i-c;
                res = Math.max(res, cnt);
            }
        }
        
        System.out.println(res);
    }
}