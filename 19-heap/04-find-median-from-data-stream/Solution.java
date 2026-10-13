import java.util.Collections;
import java.util.PriorityQueue;

class MedianFinder {
    private PriorityQueue<Integer> small = new PriorityQueue<>(Collections.reverseOrder());
    private PriorityQueue<Integer> large = new PriorityQueue<>();

    public MedianFinder() {}

    public void addNum(int num) {
        small.add(num);
        large.add(small.poll());
        if (large.size() > small.size()) {
            small.add(large.poll());
        }
    }

    public double findMedian() {
        if (small.size() > large.size()) return small.peek();
        return (small.peek() + large.peek()) / 2.0;
    }
}
