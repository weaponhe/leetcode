/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
  nums.sort((a,b)=>a-b)
  var ret = []
  for(var i=0,len=nums.length;i<len-2;i++){
    if(i==0||(i>0 && nums[i]!=nums[i-1])){
      var l=i+1,
          r=len-1,
          sum = -nums[i]
      while(l<r){
        if(nums[l]+nums[r]>sum){
          r--
        }else if(nums[l]+nums[r]<sum){
          l++
        }else{
          ret.push([nums[i],nums[l],nums[r]])
          while(++l<r && nums[l]==nums[l-1]);
          while(l<--r && nums[r]==nums[r+1]);
        }
      }
    }
  }
  return ret
};