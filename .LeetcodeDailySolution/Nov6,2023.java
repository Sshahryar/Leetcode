class SeatManager {
    private PriorityQueue<Integer> queue;

    public SeatManager(int n) {
        queue = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            queue.offer(i);
        }
    }
    public int reserve() {
        return (!queue.isEmpty())? queue.poll() : -1;
    }
    public void unreserve(int seatNumber) {
        queue.offer(seatNumber);
    }
}
