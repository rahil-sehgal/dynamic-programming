// try subtracting two subarrays to make a new subarray and then check its sum in a hash map
//in this case no need of hash map instead a set is enough 

for(int i=0;i<N;i++){
 sum+=a[i];
 s.insert(sum);
  if(s.find(sum-k)!=s.end()){
   // now that element is found 
   return true ;
   break;
   }
   }
   return false;
   
   // basically a x=y-k // sum-k
