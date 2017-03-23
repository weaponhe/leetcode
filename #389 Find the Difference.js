/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
  var i,len = s.length,
      ss = 0, ts=0
  for(i=0;i<len;i++){
    ss += s.charCodeAt(i)
  }
  for(i=0;i<len+1;i++){
    ts += t.charCodeAt(i)
  }
  return String.fromCharCode(ts-ss)
};