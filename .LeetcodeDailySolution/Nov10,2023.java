class Solution {
    private static final int MINV = -100000, MAXV = 100000,
    RANGEV = MAXV - MINV + 1;
    private static final long UINT_MAX = 0xFFFFFFFFl;
    private static long[] index = new long[RANGEV];

    public int[] restoreArray(int[][] apairs) {
        final int n = apairs.length;
        if (n == 1) return apairs[0];
        int minv = MAXV, maxv = MINV;
        for (int i = 0; i < n; i++) {
            final var ap = apairs[i];
            final int v0 = ap[0], v1 = ap[1];
            final long j = i + 1;
            index[v0-MINV] += index[v0-MINV] == 0 ? j : j << 32;
            index[v1-MINV] += index[v1-MINV] == 0 ? j : j << 32;
            final int mn = Math.min(v0, v1);
            final int mx = Math.max(v0, v1);
            minv = Math.min(mn, minv);
            maxv = Math.max(mx, maxv);
        }

        int head = minv;
        while (head <= maxv
            && (index[head-MINV] > UINT_MAX || index[head-MINV] == 0))
            head++;

        int[] r = new int[n + 1];
        r[0] = head;
        int ri = 1;
        for (long idx = index[head-MINV]; idx != 0; idx = index[head-MINV]) {
            final int loidx = (int)(idx & UINT_MAX);
            final var ap = apairs[loidx - 1];
            index[head-MINV] >>>= 32;
            r[ri++] = head = ap[ap[0] == head ? 1 : 0];
            final int lonext = (int)(index[head-MINV] & UINT_MAX),
                      hinext = (int)(index[head-MINV] >>> 32);
            if (lonext == loidx) index[head-MINV] = hinext;
            else if (hinext == loidx) index[head-MINV] = lonext;
        }
        return r;
    }
}
