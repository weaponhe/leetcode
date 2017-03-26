/**
 * @param {number} n
 * @return {number}
 */
var countPrimes = function(n) {
  var arr = new Array(n).fill(false),
      count = 0
  for(var i=2;i<n;i++){
    if(arr[i]===false){
      count++
      for(var j=2;i*j<n;j++){
        arr[i*j]=true
      }
    }
  }
  return count
};