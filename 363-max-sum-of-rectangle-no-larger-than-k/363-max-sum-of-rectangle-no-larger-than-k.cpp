class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
    
    // Init
    const int h = m.size(), w = m[0].size();
    int res = INT_MIN;

    /*
        Why do we have this loop?
            Well, to answer this question, we will have to look at how @votrubac is trying to solve this question. 
            First problem we have is that we are given a matrix. It has 2 dimensions. But we don't like 
            2 dimensions. So lets reduce the complexity a bit. We dont want to consider the entire matrix
            lets just consider a smaller part of this matrix. We will run two loops just to go through columns.
            First loop ('l') will go from '0' to 'w-1' and a second (inner) loop will go from 'l' to 'w-1'. 
            Basically the left and the right limits of the sub part under consideration. Good, now we have a 
            smaller subpart of the matrix. So lets also collect the row-wise sum at we update the right limits.
            So, we will essentially have the row-wise sum of the block we are consider (this is stored in 'sums').
            Very well, now can we process this vector 'sum' in a way that we can get the sums of all the 'parts'
            inside our current block? Well, you can run 2 more loops from '0' to 'h' and 'd' to 'h', But that will 
            increase the complexity by a very big margin. Before we go any further, lets go through this subproblem 
            once more. We have a vector 'sum', 1d, and we have to figure out a range in this vector, such that the 
            sum of values in that range is no larger than 'k'. Or, we have to find a 'Max value of a Subarray 
            with sum less than K'. So we have essentially converted this 2d problem into a 1d problem.
        Why does it go from 0 to 'w' and not 0 to 'h'?
            We are looking at this problem column-wise (It is easier). So we are giving priority to 'w'. 
            We do have a smaller loop that goes over 'h' inside this loop.
        Why are we using 'l' and 'r'?
            'left' and 'right', Einstein. 
            'l' and 'r' would basically give you the 'limits' for the current matrix part under consideration.
    */    
    for (int l = 0; l < w; ++l) {
        
        /*
            Why do we have this vector?
                This vector basically stores the sum of a 'column', 'row-wise'
                For basically we update the column (or 'x') one by one and after every update,
                we update this vector by adding the values from that column. 
        */
        // Interesting Fact: std::vector default value is '0', so we dont have to write 'sums(h,0)'
        vector<int> sums(h);

        for (int r = l; r < w; ++r) {
            
            /*
                Why is this loop collecting sums over height?
                    This is a very interesting part. This line basically converts this 2d problem into a 
                    1d problem "Maximum sum of a subarray with value less than 'k'". 
            */
            for (int i = 0; i < h; ++i) 
                sums[i] += m[i][r];
            
            /*
                Why do we have this set?
                    One of the interesting facts about 'std::set' is that it stores the elements in ordered
                    manner. Why do we need order? Well, we want to perform binary search using 'lower_bound'
                    on this list of number. So we want to keep them in ascending order. 
                Why does it contain '0' by default?
                    *In case we want to consider the entire block from 'h==0' to height under consideration.
            */
            set<int> s = {0};
            int run_sum = 0; // Stores running sum
            
            /*
                What is this block doing?
                    Have you solved this problem? https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
                    If not, you should. If you already have, you would probably recognize this techinique in an instant.
                    In case you are too lazy, here's a bunch of math:
                        We want a block such that sum(block) <= k
                        We have collected the sum of all the columns row-wise.
                        We are maintaining a running sum 'run_sum' that holds the sum of current block row
                        and all the block rows before it. 
                        So, we want ((rs[y] - rs[j]) <= k) (where j < y)
                        Now, we can change this equation as:
                            rs[y] - rs[j] + rs[j] - k <= k + rs[j] - k
                            (rs[y] - k) <= rs[j]
                        Or, rs[j] >= (rs[y] - k)
                        'rs[y]' is basically the running sum (for current iteration)
                        We are already given 'k'
                        We just have to check if we have seen (rs[y] - k) (or a bigger value) 
                            before the current iteration.
                        So, we are storing all the values of running sum in a 'std::set', so we can
                        lookup previous values of running sum very quickly.
            */
            for (int sum : sums) {
                run_sum += sum; // Update running sum
                // Binary search for 'rs[j]'
                auto it = s.lower_bound(run_sum - k);
                // If 'rs[j]' or a higher value is found, we can update the answer
                if (it != end(s)) res = max(res, run_sum - *it);
                // Add running sum from current interation to a set.
                s.insert(run_sum);
            }

        }

    }
    
    return res;
}

};