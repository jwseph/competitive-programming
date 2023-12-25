import java.util.*;
import java.io.*;

public class Day11B {
    private static Scanner in;
    private static List<Monkey> monkeys = new ArrayList<>();
    private static int lcm = 1;
    private static class Monkey {
        private Queue<Integer> items = new LinkedList<>();
        private char op;
        private int num, mod, true_i, false_i, cnt;
        public Monkey() {
            monkeys.add(this);
            for (int i = 0; i < 4; i++) in.next();
            String s;
            for (s = in.next(); s.charAt(s.length()-1) == ','; s = in.next()) {
                items.add(Integer.parseInt(s.substring(0, s.length()-1)));
            }
            items.add(Integer.parseInt(s));
            for (int i = 0; i < 4; i++) in.next();
            op = in.next().charAt(0);
            s = in.next();
            if (s.equals("old")) op = '^';
            else num = Integer.parseInt(s);
            for (int i = 0; i < 3; i++) in.next();
            mod = Integer.parseInt(in.next());
            lcm *= mod;
            for (int i = 0; i < 5; i++) in.next();
            true_i = Integer.parseInt(in.next());
            for (int i = 0; i < 5; i++) in.next();
            false_i = Integer.parseInt(in.next());
        }
        public void add(int item) {
            items.add(item);
        }
        public void tick() {
            while (!items.isEmpty()) {
                long item = items.remove();
                cnt++;
                switch (op) {
                    case '+': item += num; break;
                    case '*': item *= num; break;
                    case '^': item *= item; break;
                    default: System.out.println("switch error");
                }
                item %= lcm;
                int i = item%mod == 0 ? true_i : false_i;
                monkeys.get(i).add((int)item);
            }
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("Day11.in"));
        while (in.hasNext()) new Monkey();
        for (int i = 0; i < 10000; i++) {
            for (Monkey monkey: monkeys) monkey.tick();
        }
        int max1 = -1, max2 = -1;
        for (Monkey monkey: monkeys) {
            if (monkey.cnt > max1) {
                max2 = max1;
                max1 = monkey.cnt;
                continue;
            }
            max2 = Math.max(max2, monkey.cnt);
        }
        System.out.println((long)max1*max2);
    }
}