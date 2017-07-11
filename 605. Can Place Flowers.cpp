/**
 * Suppose you have a long flowerbed in which some of the plots are
 * planted and some are not. However, flowers cannot be planted in
 * adjacent plots - they would compete for water and both would die.
 * Given a flowerbed (represented as an array containing 0 and 1,
 * where 0 means empty and 1 means not empty), and a number n,
 * return if n new flowers can be planted in it without violating
 * the no-adjacent-flowers rule.
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * Note:
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 *
 * Author: Adam Yu Wen
 * Date: July 11, 2017
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // if the number of additional flowers is 0
        if(n == 0) return true;

        int flowerbedSize = flowerbed.size();
        for(int idx = 0; idx < flowerbedSize; idx++) {
            // if the current is 1, skip it
            if(flowerbed[idx] == 1) continue;

            // for the first element, don't need to think about the left one
            if(idx == 0) {
                if(flowerbed[1] == 0) {
                    n--;
                    // change the element is important
                    // because it will affect others
                    flowerbed[0] = 1;
                }
            }
            // for the last element, don't need to think about the right one
            else if (idx == flowerbedSize - 1) {
                if(flowerbed[flowerbedSize - 2] == 0) {
                    n--;
                    flowerbed[flowerbedSize - 1] = 1;
                }
            }
            // for the middle elements
            else {
                if(flowerbed[idx - 1] == 0 && flowerbed[idx + 1] == 0) {
                    n--;
                    flowerbed[idx] = 1;
                }
            }
            if(n == 0) return true;
        }
        return false;
    }
};
