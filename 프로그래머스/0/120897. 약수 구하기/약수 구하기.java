import java.util.*;
class Solution {
    public List<Integer> solution(int n) {
        List<Integer> ret = new ArrayList<>();
        
        for(int i = 1; i <= n; i++){
            if(n % i == 0) ret.add(i);
        }
        return ret;   
    }
}