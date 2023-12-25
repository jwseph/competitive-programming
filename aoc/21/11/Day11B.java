import java.util.*;
import java.io.*;

public class Day11B {
    private static int arr[][] = new int[10][10];

    private static void dfs(int r, int c) {
        arr[r][c]++;
        if (arr[r][c] != 10) return;
        _dfs(r-1, c-1);
        _dfs(r-1, c);
        _dfs(r-1, c+1);
        _dfs(r, c-1);
        _dfs(r, c+1);
        _dfs(r+1, c-1);
        _dfs(r+1, c);
        _dfs(r+1, c+1);
    }
    private static void _dfs(int r, int c) {
        if (r < 0 || r >= 10 || c < 0 || c >= 10) return;
        dfs(r, c);
    }
    
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day11.in"));
        
        for (int r = 0; r < 10; r++) {
            char s[] = in.next().toCharArray();
            for (int c = 0; c < 10; c++) {
                arr[r][c] = s[c]-'0';
            }
        }
        int t = 0;
        for (int cnt = 0; cnt < 100; t++) {
            for (int r = 0; r < 10; r++) for (int c = 0; c < 10; c++) dfs(r, c);
            cnt = 0;
            for (int r = 0; r < 10; r++) {
                for (int c = 0; c < 10; c++) {
                    if (arr[r][c] > 9) {
                        arr[r][c] = 0;
                        cnt++;
                    }
                }
            }
        }
        
        System.out.println(t);
    }
}
