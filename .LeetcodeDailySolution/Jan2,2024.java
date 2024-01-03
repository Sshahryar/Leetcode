class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
    int n = nums.length;

    Arrays.sort(nums);

    List<List<Integer>> ans = new ArrayList<>();
    int k = 0;

    for(int i = 0; i < n; i++){
        if(ans.size() <= k) ans.add(new ArrayList<>());
        ans.get(k).add(nums[i]);
        if(i+1 < n && nums[i] != nums[i+1])  k=0;
        else k++;
    }
    return ans;
    }
}
