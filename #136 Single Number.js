/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  var single = 0
  for(var i=0,len=nums.length;i<len;i++){
    single ^=nums[i]
  }
  return single
};