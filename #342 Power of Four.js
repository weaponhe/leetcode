/**
 * @param {number} num
 * @return {boolean}
 */
var isPowerOfFour = function(num) {
  var tester = 0x55555555
  return num > 0 && (num&(num-1))===0 && (num&tester)>0
};