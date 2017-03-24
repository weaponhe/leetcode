/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
  var sum = 0
  for(var i=0;i<s.length;i++){
    sum = sum * 26 + fromChar2num(s[i])
  }
  return sum
  function fromChar2num(c){
    return c.charCodeAt(0) - 'A'.charCodeAt(0) + 1
  }
};