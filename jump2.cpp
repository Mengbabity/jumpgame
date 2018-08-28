class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==0||n==1)
            return 0;
        
        int start=0,end=0,nextend=0;
        int step=0;
        
        while(end<n-1)   //没走到最后一个，不结束
        {
            step++;
            
            for(int i=start;i<=end;i++)   //循环是为了不错过中间任何一个数字，只要在循环里，都只需要一步
            {
                if(end>=n-1)   //走到了结束
                    return step;
                nextend=max(nextend,i+nums[i]);   //可走到的，最远的元素下标
            }
            start=end+1;   //局部最优即可，就保证了全局最优
            end=nextend;   //最远下标赋给end
        }
        
        return step;
    }
};
