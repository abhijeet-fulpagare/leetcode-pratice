class ProductOfNumbers {
public:
    
    vector<int>t;
    int size;
    ProductOfNumbers() 
    {
        size=0;
    }
    
    void add(int num) 
    {
        t.push_back(num);
        size++;
        
    }
    
    int getProduct(int k) 
    {
        if(t.empty() == 1)
        {
            return 0;
        }
         
        int ans=1;
        for(int i=size-k ; i<size ; i++)
        {
           ans=ans*t[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */