int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int max=mat[n-1][n-1];
  int min=mat[0][0];
  int desired=k;
  while(min<max)
  {
      int mid = min + (max - min) / 2; 
        int place = 0; 
        for (int i = 0; i < n; ++i) 
            place += upper_bound(mat[i], mat[i]+n, mid) - mat[i]; 
        if (place < desired) 
            min = mid + 1; 
        else
            max = mid; 
      
  }
  return min;
}
