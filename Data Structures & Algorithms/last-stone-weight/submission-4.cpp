class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        vector<int> frq(1001, 0);
        int mx = 0;

        for (int w : stones) {
            frq[w]++;
            mx = max(mx, w);
        }

        int i = mx;
        while (i > 0) {
            // Skip if no stones of this weight
            if (frq[i] == 0) {
                i--;
                continue;
            }

            // If even number of stones, they cancel out
            if (frq[i] % 2 == 0) {
                frq[i] = 0;
                i--;
            } else {
                // One stone of weight i remains, find next available stone
                int j = i - 1;
                while (j > 0 && frq[j] == 0) j--;

                if (j == 0 && frq[j] == 0) {
                    // No more stones to smash with
                    return i;
                }

                // Smash i and j -> new stone of weight i - j
                frq[i]--;
                frq[j]--;
                frq[i - j]++;
                i = max(i, i - j);  // restart from the heavier side
            }
        }

        return 0;
    }
};
