class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int size=gas.length;
        int start=0;
        int currGas=0;
        int totalTank=0;

        for(int i=0;i<size;i++){
            totalTank+=gas[i]-cost[i];
            currGas+=gas[i]-cost[i];

            if(currGas<0){
                start=i+1;
                currGas=0;
            }
        }
      
        return totalTank>=0 ? start : -1;
    }
}