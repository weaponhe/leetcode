/**
 * @param {number[]} houses
 * @param {number[]} heaters
 * @return {number}
 */
var findRadius = function(houses, heaters) {
    heaters.sort((a,b)=>a-b)
    var radius=Number.NEGATIVE_INFINITY
    for(var i=0,n=houses.length;i<n;i++){
        radius = Math.max(radius,search(houses[i],heaters))
    }
    return radius
};

function search(val,arr){
    var left = 0,
        right = arr.length-1,
        mid

    while(right-left>1){
        mid = getMid(left,right)
        if(arr[mid]===val){
            return 0
        }else if(arr[mid] > val){
            right = mid
        }else{
            left = mid
        }
    }
    return Math.min(Math.abs(val-arr[left]),Math.abs(val-arr[right]))

    function getMid(l,r){
        return Math.floor((l+r)/2)
    }
}