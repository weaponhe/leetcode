/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  var count = 0
  while(n){
    count++
    n = n&(n-1)
  }
  return count
};

/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  var count = 0
  while(n){
    count += (n&1)
    n = n>>>1
  }
  return count
};

