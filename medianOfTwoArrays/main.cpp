#include <iostream>
#include <vector>
#include <algorithm>

class solution {
  public:
    double findMedianSortedArrays(const std::vector<int> & nums1, const std::vector<int> & nums2) {
        int totalLen = nums1.size()+nums2.size();
        if (!(totalLen%2)) {
            int k = totalLen/2, kminus = k-1;
            std::cout << "The " << kminus << "-th num is: " << getKthNum(nums1, nums2, kminus) << ", "
                      << "and the " << k << "-th num is " << getKthNum(nums1, nums2, k) << std::endl;
            return (getKthNum(nums1, nums2, k)+getKthNum(nums1, nums2, kminus))/2.0;
        }
        else
            return getKthNum(nums1, nums2, totalLen/2);
    }

  private:
    int getKthNum(const std::vector<int> & nums1, const std::vector<int> & nums2, int k) {
        size_t lb, ub, mid;

        // binary search in nums1
        lb = 0, ub = nums1.size()-1;
        if (ub > lb) {
            while (lb < ub-1) {
                mid = (lb+ub)/2;
		if (getNumOfSmaller(nums1,nums2,nums1[mid]) == k) {
		  return nums1[mid];
		}
                else if (getNumOfSmaller(nums1,nums2,nums1[mid]) < k) {
		  if (getNumOfSmaller(nums1,nums2,nums1[mid])+getNumOfEqual(nums1,nums2,nums1[mid]) <= k)
		    lb = mid;
		  else if (getNumOfSmaller(nums1,nums2,nums1[mid])+getNumOfEqual(nums1,nums2,nums1[mid]) > k)
                    return nums1[mid];
		}
                else if (getNumOfSmaller(nums1,nums2,nums1[mid]) > k)
                    ub = mid;
            }
            if (getNumOfSmaller(nums1,nums2,nums1[lb]) == k)
                return nums1[lb];
	    else if (getNumOfSmaller(nums1,nums2,nums1[lb]) < k && getNumOfSmaller(nums1,nums2,nums1[lb])+getNumOfEqual(nums1,nums2,nums1[lb]) > k)
	      return nums1[lb];
            else if (getNumOfSmaller(nums1,nums2,nums1[ub]) == k)
                return nums1[ub];
        }
        else {
            if (getNumOfSmaller(nums1,nums2,nums1[lb]) == k)
                return nums1[lb];
        }

        // binary search in nums2
        lb = 0, ub = nums2.size()-1;
        if (ub > lb) {
            while (lb < ub-1) {
                mid = (lb+ub)/2;
		if (getNumOfSmaller(nums1,nums2,nums2[mid]) == k)
		  return nums2[mid];
                else if (getNumOfSmaller(nums1,nums2,nums2[mid]) < k) {
		  if (getNumOfSmaller(nums1, nums2, nums2[mid])+getNumOfEqual(nums1,nums2,nums2[mid]) <= k)
		    lb = mid;
		  else if (getNumOfSmaller(nums1, nums2, nums2[mid])+getNumOfEqual(nums1,nums2,nums2[mid]) > k)
		    return nums2[mid];
		}
                else if (getNumOfSmaller(nums1,nums2,nums2[mid]) > k)
                    ub = mid;
            }
            if (getNumOfSmaller(nums1,nums2,nums2[lb]) == k)
                return nums2[lb];
	    else if (getNumOfSmaller(nums1,nums2,nums2[lb]) < k && getNumOfSmaller(nums1,nums2,nums2[lb])+getNumOfEqual(nums1,nums2,nums2[lb]) > k)
	      return nums2[lb];
            else if (getNumOfSmaller(nums1,nums2,nums2[ub]) == k)
                return nums2[ub];
        }
        else {
            if (getNumOfSmaller(nums1,nums2,nums2[lb]) == k)
                return nums2[lb];
        }
    }

    int getNumOfSmaller(const std::vector<int> & nums1, const std::vector<int> & nums2, int val) {
        // std::cout << "val = " << val << ": ";
        auto it1 = std::lower_bound(nums1.begin(), nums1.end(), val);
        auto it2 = std::lower_bound(nums2.begin(), nums2.end(), val);
        // std::cout << "it1 = " << *it1 << ", " << "it2 = " << *it2 << " -- ";
        // std::cout << "return " << std::distance(nums1.begin(),it1)+std::distance(nums2.begin(),it2) << std::endl;
        return std::distance(nums1.begin(),it1)+std::distance(nums2.begin(),it2);
    }

  int getNumOfEqual(const std::vector<int> & nums1, const std::vector<int> & nums2, int val) {
    // std::cout << "val = " << val << ": ";
    auto first1 = std::lower_bound(nums1.begin(), nums1.end(), val);
    auto last1 = std::upper_bound(nums1.begin(), nums1.end(), val);
    auto first2 = std::lower_bound(nums2.begin(), nums2.end(), val);
    auto last2 = std::upper_bound(nums2.begin(), nums2.end(), val);
    // std::cout << std::distance(first1, last1)+std::distance(first2, last2) << std::endl;
    return std::distance(first1, last1)+std::distance(first2, last2);
  }
};


int main() {
    // std::vector<int> nums1{1,3}, nums2{2};
    // std::vector<int> nums1{1,2}, nums2{3,4};
  // std::vector<int> nums1{1,2,3,4,7}, nums2{0,5,6,9};
  // std::vector<int> nums1{1,7,8}, nums2{2,5,6,9};
  std::vector<int> nums1{1,2,3,4,5}, nums2{2,3,4,5,6};

    solution soln;
    double med = soln.findMedianSortedArrays(nums1, nums2);
    std::cout << "The median of these two sorted arrays is:\n"
              << med << std::endl;
}
