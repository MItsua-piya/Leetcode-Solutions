class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n=nums.size();

        vector<int>R(n,n);
        stack<int>st;
        for(int i=n-1;i>=0;--i){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            R[i]=st.empty() ?n:st.top();
            st.push(i);
        }
        vector<int>vals=nums;
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        int m=vals.size();
        struct BIT{
            int n;
            vector<int>bit;
            BIT(int n):n(n),bit(n+1,0){}
            void add (int idx,int val){
                for(;idx<=n;idx+=idx&-idx) bit[idx]+=val;
              
            }
            int sum(int idx){
                int res=0;
                for(;idx>0;idx-=idx&-idx) res+=bit[idx];
                return res;
            }
        };
            BIT bit(m);
            struct Event {
                int pos;
                int the;
                int sig;
            };
            vector<Event>events;
            events.reserve(2*n);
            for(int i=0;i<n;++i){
            int L=i+1;
            int R_excl=R[i];
            if(L>=R_excl) continue;
            int left =i+2;
            int right=R_excl;
            if(left>right) continue;
            events.push_back({right,nums[i],1});
             events.push_back({left-1,nums[i],-1});
            }
        sort(events.begin(),events.end(),[](const Event& a ,const Event &b){
            return a.pos<b.pos;
        });
        long long ans=0;
        int cur =0;
        for(const auto & e:events){
            while(cur<e.pos){
                ++cur;
                int val =nums[cur-1];
                int idx =lower_bound(vals.begin(),vals.end(),val)-vals.begin()+1;
                bit.add(idx,1);
            }
            int idx_le=upper_bound(vals.begin(),vals.end(),e.the)-vals.begin();
            int le =(idx_le>0)? bit.sum(idx_le):0;
            int gt=cur-le;
            ans+=1LL * e.sig*gt;
        }
            
        
    return ans;
    }
};