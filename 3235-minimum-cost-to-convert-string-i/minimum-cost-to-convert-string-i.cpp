class Solution {
public:
    long long minimumCost(string s, string t, vector<char>& t1, vector<char>& t2, vector<int>& cost) {
        long long n=s.size(),i,j,k;
        vector<vector<long long>> dist(26, vector<long long> (26,1e9));
        for(i=0;i<26;i++) dist[i][i]=0;
        for(i=0;i<t1.size();i++) {
            dist[t1[i]-'a'][t2[i]-'a'] = min(dist[t1[i]-'a'][t2[i]-'a'], (long long)cost[i]);
        }
        for(k=0;k<26;k++) {
            for(i=0;i<26;i++) {
                for(j=0;j<26;j++) {
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        long long res=0;
        for(i=0;i<n;i++) {
            if(dist[s[i]-'a'][t[i]-'a']==1e9) return -1;
            res+=dist[s[i]-'a'][t[i]-'a'];
        }
        return res;
    }
};