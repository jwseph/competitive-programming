import java.util.*;
import java.io.*;

public class Day8A {
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

        int[][] v = new int[n][n];
        for (int r = 0; r < n; r++) {
            int lm = -1, rm = -1;
            int i = 0, j = n-1;
            while (i <= j) {
                if (lm < rm) {
                    v[r][i] += arr[r][i] > lm ? 1 : 0;
                    lm = Math.max(lm, arr[r][i]);
                    i++;
                } else {
                    v[r][j] += arr[r][j] > rm ? 1 : 0;
                    rm = Math.max(rm, arr[r][j]);
                    j--;
                }
            }
        }
        for (int c = 0; c < n; c++) {
            int lm = -1, rm = -1;
            int i = 0, j = n-1;
            while (i <= j) {
                if (lm < rm) {
                    v[i][c] += arr[i][c] > lm ? 1 : 0;
                    lm = Math.max(lm, arr[i][c]);
                    i++;
                } else {
                    v[j][c] += arr[j][c] > rm ? 1 : 0;
                    rm = Math.max(rm, arr[j][c]);
                    j--;
                }
            }
        }
        
        int cnt = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (v[r][c] > 0) cnt++;
            }
        }
        System.out.println(cnt);
    }
}