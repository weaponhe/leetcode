/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  return (0+nums.length)*(nums.length+1)/2 - nums.reduce((a,b)=>{return a+b},0)
};