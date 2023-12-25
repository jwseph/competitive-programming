import java.util.*;
import java.io.*;

public class Day18A2 {
    private static List<Character> s = new ArrayList<Character>();
    private static boolean solve() {
        int d = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s.get(i) == '[') {
                d++;
                continue;
            }
            if (s.get(i) == ']') {
                if (d > 4) {
                    System.out.println(i);
                    i -= 4;
                    int l = s.get(i+1)-'0', r = s.get(i+3)-'0';
                    for (int j = 0; j < 5; j++) s.remove(i);
                    s.add(i, '0');
                    boolean b = false;
                    for (int j = i+1; j < s.size(); j++) {
                        if ('0' <= s.get(j) && s.get(j) <= '9') {
                            int v = r+s.get(j)-'0';
                            System.out.println(j);
                            if (v > 9) {
                                s.remove(j);
                                s.add(j, '[');
                                s.add(j, (char)(v/2+'0'));
                                s.add(j, ',');
                                s.add(j, (char)(v-v/2+'0'));
                                s.add(j, ']');
                                b = true;
                                return false;
                            } else {
                                s.set(j, (char)(v+'0'));
                            }
                            break;
                        }
                    }
                    // for (int j = i-1; j >= 0; j--) {
                    //     if ('0' <= s.get(j) && s.get(j) <= '9') {
                    //         int v = l+s.get(j)-'0';
                    //         if (v > 9) {
                    //             s.remove(j);
                    //             s.add(j, '[');
                    //             s.add(j, (char)(v/2+'0'));
                    //             s.add(j, ',');
                    //             s.add(j, (char)(v-v/2+'0'));
                    //             s.add(j, ']');
                    //             b = true;
                    //             return false;
                    //         } else {
                    //             s.set(j, (char)(v+'0'));
                    //         }
                    //         break;
                    //     }
                    // }
                    if (b) return false;
                }
                d--;
                continue;
            }
        }
        return true;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day18.in"));
        
        String str = in.next();
        while (in.hasNext()) str = "["+str+","+in.next()+"]";
        for (char c: str.toCharArray()) s.add(c);

        for (Character c: s) System.out.print(c); System.out.println();
        solve();
        System.out.println();
        // boolean b = solve();
        // while (!b) solve();
        for (Character c: s) System.out.print(c); System.out.println();
    }
}
