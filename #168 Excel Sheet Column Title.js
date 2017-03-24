/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function (n)
{
  var str = ''
  while (n) {
    str = fromNum2Char((
        n - 1) % 26) + str
    n   = Math.floor((
      n - 1) / 26)
  }
  return str

  function fromNum2Char(num)
  {
    return String.fromCharCode(num + 'A'.charCodeAt(0))
  }
};