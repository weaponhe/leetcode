/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
  if(n<1)return false
  while(n>1){
    if(n%3){
      return false
    }
    n = Math.floor(n/3)
  }
  return true
};