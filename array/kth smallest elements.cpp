int find(vector<int>& nums,int l,int r,int k){
        int p1=l,p2=r-1;
        int t=rand()%(r-l+1)+l;
        swap(nums[t],nums[r]);
        while(p1<p2){
            if(nums[p1]>nums[r]){
                swap(nums[p1],nums[p2]);
                p2--;
            }
            else p1++;
        }
        int rank,pivot;
        if(nums[p1]<nums[r]){
            swap(nums[p1+1],nums[r]);
            rank=p1+1-l+1;
            pivot=p1+1;
        }
        else{
            swap(nums[p1],nums[r]);
            rank=p1-l+1;
            pivot=p1;
        }
        if(rank==k)return nums[pivot];
        if(rank>k)return find(nums,l,pivot-1,k);
        return find(nums,pivot+1,r,k-rank);
    }
