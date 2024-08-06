/*
    int * intersection(int arr1[],int n,int arr2[],int m)
    {
        // Complexity High

        int *ans = new int[n];
        int k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr1[i]==arr2[j])
                {
                    ans[k]=arr1[i];
                    k++;
                    arr2[j]=INT_MAX;
                    break;
                }
            }
        }
        return ans;

        // Optimized Solution

        int *ans = new int[n];
        int i=0,j=0,k=0;

        // Bcz both arrays are Sorted so...

        while(i<n && j<m)
        {
            if(arr1[i]==arr2[j])
            {
                ans[k]=arr1[i];
                i++;
                j++;
                k++;
            }
            else if(arr1[i]<arr2[j])
            {
                i++;
            }
            else
            {
                j++;
            }    
        }
        return ans;
    }
*/