class Solution:
    def checkDivisibility(self, n: int) -> bool:
        ori=n
        n1=ori
        summ=0
        prod=1
        while(n!=0):
        
            summ += n%10
            n//=10
        
        while(ori!=0):
        
            prod *= ori%10
            ori//=10
        
        sum_prod=summ+prod
        if(n1%sum_prod==0):
            return True
        else:
            return False