class Solution {
public:
    long long dividePlayers(vector<int>& skill) {

        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        int totalSkill = skill[0] + skill[n - 1]; 
        long long chemistrySum = 0;

        for (int i = 0; i < n / 2; i++) {

            if (skill[i] + skill[n - i - 1] != totalSkill) {
                return -1; 
            }

            chemistrySum += (long long)skill[i] * skill[n - i - 1];
        }

        return chemistrySum; 
    }
};
