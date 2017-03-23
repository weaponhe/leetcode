/**
 * @param {number[]} nums
 * @return {number}
 */

//sort
var findDuplicate = function(nums) {
  nums.sort((a,b)=>a-b)
  var i=0,len=nums.length
  while(i<len-1&&nums[i]!=nums[i+1])i++
  return nums[i]
};

//two pointers