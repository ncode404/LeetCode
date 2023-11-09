class MedianFinder {
public:
    MedianFinder() {
        
    }
    int n=0;
    priority_queue<int> pmax;
    priority_queue<int, vector<int>, greater<int>> pmin;
    void addNum(int num) {
        n++;
        if(pmax.empty() || num<=pmax.top()) pmax.push(num);
        else pmin.push(num);
        if(n%2==0) {
            if(pmax.size()>pmin.size()) {
                int t=pmax.top(); pmax.pop();
                pmin.push(t);
            }
            else if(pmax.size()<pmin.size()) {
                int t=pmin.top(); pmin.pop();
                pmax.push(t);
            }
        }
        else {
            if(pmin.size()>pmax.size()) {
                int t=pmin.top(); pmin.pop();
                pmax.push(t);
            }
        }
    }
    
    double findMedian() {
        if(n%2==0) {
            if(pmin.empty() || pmax.empty()) return 0.0;
            return (double)(pmax.top()+pmin.top())/2;
        }
        return pmax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */