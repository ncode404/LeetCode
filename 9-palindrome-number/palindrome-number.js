/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    const arr = String(x).split('');
    const n = arr.length
    for (let i=0; i< n/2; i++) {
        if(arr[i] !== arr[n-i-1])
        return 0;
    }
    return 1;
};