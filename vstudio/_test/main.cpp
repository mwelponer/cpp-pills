#include <iostream>
#include <array>
#include <vector>

int search(std::vector<int>& nums, int target) 
{
    int l = 0;
    int r = nums.size()-1;

    while(l <= r)
    {
        int mid = l + (r-l)/2;
        if(nums.at(mid) == target) 
            return mid;

        if(target > nums.at(mid))
            l = mid+1;
        else
            r = mid-1;
        
    }

    return -1;
}

int main()
{
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    std::cout << "res: " << search(nums, target) << std::endl;
}