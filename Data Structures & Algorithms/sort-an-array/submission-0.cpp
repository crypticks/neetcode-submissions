class Solution {
public:

    int partition(vector<int>& arr, int p, int q)
    {
        int i = p;
        int b = i;
        int ele = arr[q-1];
        int temp;
        while(i<q-1)
        {
            if(arr[i] <= ele)
            {
                temp = arr[i];
                arr[i] = arr[b];
                arr[b] = temp;
                b++; 
            }
            i++;
        }
        arr[q-1] = arr[b];
        arr[b] = ele;
        return b;
    }

    void quicksort(vector<int>& arr, int p, int q)
    {
        if (p>=q-1) return;
        int a = partition(arr, p, q);
        quicksort(arr, p, a);
        quicksort(arr, a+1, q);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> res = nums;
        quicksort(res, 0, res.size());
        return res;
    }
};