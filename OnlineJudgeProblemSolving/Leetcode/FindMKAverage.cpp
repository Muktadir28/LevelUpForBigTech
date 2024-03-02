//
//  FindMKAverage.cpp
//  
//
//  Created by Md Muktadir on 2/3/24.
//

#include <stdio.h>

struct Node{
    int idx, val;
    Node(int _idx, int _val) : val(_val), idx(_idx) {}
    bool operator < (const Node& other) const {
        if(val == other.val) {
            return idx < other.idx;
        }

        return val < other.val;
    }
};
class MKAverage {
    set<Node> minSet;
    set<Node> midSet;
    set<Node> maxSet;
    int total_elements;
    int M, K;
    long long avg_sum;
    unordered_map<int, int> tracker;
public:
    MKAverage(int m, int k) {
        M = m;
        K = k;
        total_elements = 0;
        minSet.clear();
        midSet.clear();
        maxSet.clear();
        tracker.clear();
        avg_sum = 0;
    }
    
    void addElement(int num) {
        total_elements++;
        //push
        minSet.insert({total_elements, num});
        tracker[total_elements] = num;
        //balance
        if(minSet.size() > K) {
            Node extraElement = *minSet.rbegin();
            minSet.erase(extraElement);
            midSet.insert(extraElement);
            avg_sum += extraElement.val;
            if(midSet.size() > M - 2 * K)
            {
                extraElement = *midSet.rbegin();
                midSet.erase(extraElement);
                avg_sum -= extraElement.val;
                maxSet.insert(extraElement);
            }
        }
        
        if(total_elements > M) {
            // delete
            auto minLower = minSet.find({total_elements - M, tracker[total_elements - M]});
            auto midLower = midSet.find({total_elements - M, tracker[total_elements - M]});
            auto maxLower = maxSet.find({total_elements - M, tracker[total_elements - M]});
            
            if(minLower != minSet.end()) {
                minSet.erase(minLower);
            } else if(midLower != midSet.end()) {
                avg_sum -= midLower->val;
                midSet.erase(midLower);
            } else if(maxLower != maxSet.end()) {
                maxSet.erase(maxLower);
            }
            //rebalance
            if(maxSet.size() > K) {
                Node extraElement = *maxSet.begin();
                maxSet.erase(maxSet.begin());
                midSet.insert(extraElement);
                avg_sum += extraElement.val;
            }

            if(minSet.size() < K) {
                Node extraElement= *midSet.begin();
                midSet.erase(midSet.begin());
                minSet.insert(extraElement);
                avg_sum -= extraElement.val;
            }
        }
    }
    
    int calculateMKAverage() {
        if(total_elements >= M) {
            return (avg_sum / midSet.size());
        }

        return -1;
    }
};

int main() {
    //Nothing to do here
    return 0;
}
