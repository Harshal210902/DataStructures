class SGTree{
    vector<int> seg;
public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int ind, int low, int high, int arr[])
    {
        if(low==high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = low + (high-low)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);//var
    }

    int query(int ind, int l, int r, int low, int high)
    {
        if(l>high || r<low) return INT_MAX;
        if(l<=low && high<=r) return seg[ind]; //if range is under then return it.
        
        int mid = low+ (high-low)/2;
        int left= query(2*ind+1, l, r, low, mid);
        int right = query(2*ind+2,l,r,mid+1,high);
        return min(left,right);//var
    }

    void update(int ind, int low, int high, int i, int val)//ind->index to be changed, low->starting range(0), high->ending range(n-1), i->each root index(2i+1/2i+2), val->val to be changed
    {
        if(low==high)
        {
            seg[ind] = val;
            return;
        }
        int mid = low + (high-low)/2;
        if(i<=mid) update(2*ind+1,low,mid,i,val);
        else update(2*ind+2,mid+1,high,i,val);
        seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);//var
    }
};
