/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
  var map = {}
  while(true){
    map[n] = true
    var sum = 0
    while(n){
      sum += Math.pow(n%10,2)
      n = Math.floor(n/10)
    }
    if(sum === 1) return true
    if(map[sum])return false
    n = sum
  }
};

