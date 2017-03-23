/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function (nums)
{
  var s = 0
  nums.forEach(n => s ^= n)
  var bit  = s & ~(
    s - 1)
  var num1 = 0, num2 = 0
  nums.forEach(n =>
  {
    if (n & bit) {
      num1 ^= n
    } else {
      num2 ^= n
    }
  })
  return [num1, num2]
};