class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
    
        vector<int> v;
        
        int i=0,j=0;
    
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                if(v.empty() || nums1[i]!=v.back()){
                    v.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return v;
    }
};
