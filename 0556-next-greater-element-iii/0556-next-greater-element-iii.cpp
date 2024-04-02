class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> ans;
        while(n!=0){
            int digit=n%10;
            n=n/10;
            ans.push_back(digit);
        }
        reverse(ans.begin(),ans.end());
        int k=ans.size();
        int index=k-1;
        int i=-1;
        for( i=k-2;i>=0;i--){
           if(ans[i]<ans[i+1]){
               while(ans[index]<=ans[i]) index--;
               swap(ans[i],ans[index]);
               sort(ans.begin()+i+1,ans.end());
               break;
           }
        }
        if(i==-1) return-1;
        long long num=0;
        for(int i=0;i<k;i++){
            num=num*10+ans[i];
        }
        if(num>INT_MAX) return -1;
        return num;
    }
};