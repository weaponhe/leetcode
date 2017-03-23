/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  var mask,len = nums.length,i,j,sum,res=0
  for(i=0;i<32;i++){
    mask = 1<<i
    sum = 0
    for(j=0;j<len;j++){
      if(mask&nums[j]){
        sum++
      }
    }
    res |= (sum%3)<<i
  }
  return res
};