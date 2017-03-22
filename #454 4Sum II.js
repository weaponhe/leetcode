/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function(A, B, C, D) {
  var N = A.length
  var hash = {}
  for(var i=0;i<N;i++){
    for(var j=0;j<N;j++){
      hash[A[i]+B[j]] = hash[A[i]+B[j]] == undefined? 1 : hash[A[i]+B[j]]+1
    }
  }

  var ret = 0
  for(var i=0;i<N;i++){
    for(var j=0;j<N;j++){
      ret += hash[-(C[i]+D[j])]?hash[-(C[i]+D[j])]:0
    }
  }
  return ret
};