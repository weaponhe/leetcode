/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
  var start = 0, end = numbers.length-1,sum,res
  while(true){
    sum = numbers[start]+numbers[end]
    if(sum==target){
      return [start+1,end+1]
    }else if(sum > target){
      end--
    }else{
      start++
    }
  }
}