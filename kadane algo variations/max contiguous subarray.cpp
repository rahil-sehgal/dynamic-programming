int maxSoFar = a[0];
int maxEndingHere = a[0];

for(int i=0;i<a.size();i++){
 // 2 choices // use  DP
// see subproblems

maxEndingHere = max (maxEndingHere +a[i], a[i]);
maxSoFar= max(maxSoFar, maxEndingHere);

}

return maxSoFar;

// this prints the max contiguous sum in a subarray 
