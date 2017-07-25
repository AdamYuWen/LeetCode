/**
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2. The number of elements initialized in nums1
 * and nums2 are m and n respectively.
 *
 * Author: Adam Yu Wen
 * Date: July 24, 2017
 */

 /**
  * Method 1:
  * The run time is 6 ms
  */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int idx = 0; idx < n; idx++) {
            nums1[m + idx] = nums2[idx];
        }
        sort(nums1.begin(), nums1.end());
    }
};

 /**
  * Method 2:
  * The run time is 3 ms
  */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Because the final size is fixed
        // assign the values from the end to the beginning
        int currIdx = m + n - 1;
        m--; n--;
        // When nums1 and nums2 both have elements
        // assign the largest element to nums1
        while(m > -1 && n > -1) {
            if(nums1[m] > nums2[n]) {
                nums1[currIdx] = nums1[m];
                m--; currIdx--;
            }
            else {
                nums1[currIdx] = nums2[n];
                n--; currIdx--;
            }
        }
        // When nums2 still have elements
        // assign the rest of nums2
        while(n > -1) {
            nums1[currIdx] = nums2[n];
            n--; currIdx--;
        }
        // When nums1 still have elements
        // do nothing
    }
};
