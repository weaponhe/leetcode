/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
  nums.sort((a,b)=>a-b)
  var len = len=nums.length,
      ret = []
  for(var i=0;i<len-3;i++){
    if(i==0 || (i>0 && nums[i]!=nums[i-1])){
      ret = ret.concat(threeSum(target-nums[i],i+1).map((item)=>{
        return item.concat(nums[i])
      }))
    }
  }
  return ret

  function threeSum(target,l){
    var ret = []
    for(var i=l;i<len-2;i++){
      if(i==l || (i>l && nums[i]!=nums[i-1])){
        ret = ret.concat(twoSum(target-nums[i],i+1).map((item)=>{
          return item.concat(nums[i])
        }))
      }
    }
    return ret
  }
  function twoSum(target,l){
    var ret = []
    var r = len-1
    while(l<r){
      if(nums[l]+nums[r] === target){
        ret.push([nums[l],nums[r]])
        while(++l<r&&nums[l]==nums[l-1]);
        while(l<--r&&nums[r]==nums[r+1]);
      }else if(nums[l]+nums[r] > target){
        r--
      }else{
        l++
      }
    }
    return ret
  }
}

