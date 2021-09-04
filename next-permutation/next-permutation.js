/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function swap(i,j,arr) {
    var tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
var reverse = function(i,j,arr) {
    while(i<j) {
        swap(i,j,arr);
        i = i+1;
        j = j-1;
    }
}
var nextPermutation = function(arr) {
    var n = arr.length;
    if(n <= 1) return;
    
    var i = n-2;
    
    while(i>=0) {
        if(arr[i] < arr[i+1]) break;
        i--;
    }
    if(i>=0) {
        var j = n-1;
        while(i<j) {
            if(arr[j] > arr[i]) {
                swap(i,j,arr);
                break;
            }else j--;
            
        }
    }
    console.log(i);
    reverse(i+1,n-1,arr);
};