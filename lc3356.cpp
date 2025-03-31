class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size(),sum=0;
            int k=0;
            vector<int>diffarray(n+1);
            for(int i=0;i<n;++i){
                while(sum+diffarray[i]<nums[i]){
                    k++;
                    if(k>queries.size()){
                        return -1;
                    }
                    int l=queries[k-1][0],r=queries[k-1][1],v=queries[k-1][2];
                    if(r>=i){
                        diffarray[max(l,i)]+=v;
                        diffarray[r+1]-=v;
                    }
                }
                sum+=diffarray[i];
            }
            return k;
        }
    };