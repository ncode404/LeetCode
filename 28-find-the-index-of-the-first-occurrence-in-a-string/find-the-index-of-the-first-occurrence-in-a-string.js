/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(h, s) {
    const n=h.length, t=s.length;
    for (let i=0;i< n;i++) {
        if(i+t<=n && h.slice(i, i+t) == s)
        return i;
    }
    return -1;
};