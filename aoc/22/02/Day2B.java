import java.util.*;
import java.io.*;

public class Day2B {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day2.in"));

        int score = 0;
        while (in.hasNext()) {
            int a = "ABC".indexOf(in.next()), b = "XYZ".indexOf(in.next());
            score += b*3+1+(b+a+2)%3;
        }

        System.out.println(score);
    }
}