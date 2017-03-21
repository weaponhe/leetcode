var twoSum = function (nums, target)
{
  var hash = {}
  for (var i = 0, len = nums.length; i < len; i++) {
    if (hash[target - nums[i]] !== undefined)
    {
      return [hash[target - nums[i]], i]
    }
    hash[nums[i]] = i
  }
};