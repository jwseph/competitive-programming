import java.util.*;
import java.io.*;

public class Day18A {
    private static Scanner in;
    private static class SnailfishNumber {
        Pair parent;
        SnailfishNumber(Pair parent) { this.parent = parent; }
        Number getLeft() { return parent == null ? null : equals(parent.l) ? parent.getLeft() : parent.l instanceof Number ? (Number)parent.l: ((Pair)parent.l).getLast(); }
        Number getRight() { return parent == null ? null : equals(parent.r) ? parent.getRight() : parent.r instanceof Number ? (Number)parent.r: ((Pair)parent.r).getFirst(); }
        Integer getMagnitude() { System.out.println("getMagnitude called from SnailfishNumber"); return null; }
    }
    private static class Number extends SnailfishNumber {
        Integer val;
        Number(int val) {
            this(null, val);
        }
        Number(Pair parent, String c) {
            this(parent, Integer.valueOf(c));
        }
        Number(Pair parent, int val) {
            this(parent, Integer.valueOf(val));
        }
        Number(Pair parent, Integer val) {
            super(parent);
            this.val = val;
        }
        public String toString() { return val.toString(); }
        void splitIfNeeded() {
            if (val < 10) return;
            Pair pair = new Pair(parent, new Number(val/2), new Number(val-val/2));
            if (equals(parent.l)) parent.l = pair;
            else parent.r = pair;
        }
        Integer getMagnitude() {
            return val;
        }
    }
    private static class Pair extends SnailfishNumber {
        SnailfishNumber l, r;
        Pair() { this(null); }
        Pair(Pair parent) {
            super(parent);
            if (parent == null) in.next();
            String c = in.next();
            l = (c.equals("[")) ? new Pair(this) : new Number(this, c);
            in.next();
            c = in.next();
            r = (c.equals("[")) ? new Pair(this) : new Number(this, c);
            in.next();
            return;
        }
        Pair(SnailfishNumber l, SnailfishNumber r) { this(null, l, r); }
        Pair(Pair parent, SnailfishNumber l, SnailfishNumber r) {
            super(parent);
            this.l = l;
            this.r = r;
            l.parent = this;
            r.parent = this;
        }
        public String toString() { return "["+l.toString()+","+r.toString()+"]"; }
        static Pair sum(Pair l, Pair r) { return new Pair(l, r); }
        Number getLast() { return r instanceof Number ? (Number)r : ((Pair)r).getLast(); }
        Number getFirst() { return l instanceof Number ? (Number)l : ((Pair)l).getFirst(); }
        void scan(int depth) {
            String temp = null;
            if (l instanceof Pair) temp = ""+(Pair)l;
            if (l instanceof Pair) System.out.println("l instanceof Pair");
            if (l instanceof Pair) ((Pair)l).scan(depth+1);
            if (r instanceof Pair) System.out.println("r instanceof Pair");
            if (r instanceof Pair) ((Pair)r).scan(depth+1);
            if (depth < 4) return;
            Number l, r;
            if ((l = getLeft()) != null) {
                System.out.println("left"+" "+(this.l instanceof Pair)+" "+(this.l instanceof Number));
                if (temp != null) System.out.println(temp+" "+this.l);
                l.val += ((Number)this.l).val;
                l.splitIfNeeded();
            }
            if ((r = getRight()) != null) {
                System.out.println("right");
                r.val += ((Number)this.r).val;
                r.splitIfNeeded();
            }
            Number n = new Number(parent, 0);
            if (equals(parent.l)) parent.l = n;
            else parent.r = n;
        }
        Integer getMagnitude() {
            return 3*l.getMagnitude()+2*r.getMagnitude();
        }
    }
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("Day18.in")).useDelimiter("\\r*\\n*");
        
        Pair c = new Pair();
        // c.scan(0);
        System.out.println(c);
        while (in.hasNext()) {
            c = Pair.sum(c, new Pair());
            // c.scan(0);
            System.out.println(c);
        }
        c.scan(0);
        System.out.println(c.getMagnitude());
    }
}
