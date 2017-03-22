/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
  nums.sort((a,b)=>a-b)
  var ans = Number.POSITIVE_INFINITY
  for(var i=0,len=nums.length;i<len-2;i++){
    var l=i+1,
        r=len-1
    while(l<r){
      var sum = nums[i]+nums[l]+nums[r]
      if(Math.abs(sum-target)<Math.abs(ans-target)){
        ans = sum
        if(ans === target)return ans
      }
      sum>target?r--:l++
    }
  }
  return ans
};