import java.util.*;
import java.io.*;

public class Day4A {
    private static class Board {
        private int board[];
        private boolean marked[][];
        public Board(Scanner in) {
            board = new int[5*5];
            marked = new boolean[5][5];
            for (int i = 0; i < 5*5; i++) {
                int x = in.nextInt();
                board[i] = x;
            }
        }
        public int getSum() {
            int sum = 0;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) if (!marked[r][c]) {
                    sum += board[r*5+c];
                }
            }
            return sum;
        }
        public boolean mark(int x) {  // returns whether or not board has won
            int i = indexOf(x);
            if (i == -1) return false;
            int r = i/5, c = i%5;
            marked[r][c] = true;
            return check(r, c);
        }
        private int indexOf(int x) {
            for (int i = 0; i < 5*5; i++) if (board[i] == x) return i;
            return -1;
        }
        private boolean check(int r, int c) {
            return checkRow(r) || checkCol(c);
        }
        private boolean checkRow(int r) {
            for (int c = 0; c < 5; c++) if (!marked[r][c]) return false;
            return true;
        }
        private boolean checkCol(int c) {
            for (int r = 0; r < 5; r++) if (!marked[r][c]) return false;
            return true;
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day4.in"));
        
        String _arr[] = in.nextLine().split(",");
        int arr[] = new int[_arr.length];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(_arr[i]);
        }
        
        List<Board> boards = new ArrayList<Board>();
        while (in.hasNextInt()) boards.add(new Board(in));
        
        for (int x: arr) for (Board board: boards) {
            if (board.mark(x)) {
                System.out.println(board.getSum()*x);
                return;
            }
        }
    }
}
