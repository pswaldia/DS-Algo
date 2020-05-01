def main():
    t=int(input())
    for _ in range(t):
        n=int(input())
        arr=list(map(int,input().split()))
        print(solve(arr,n))
import math
def solve(arr,n):
    dictt={}
    for num in arr:
        for i in range(2,int(math.sqrt(num))+1):
            count=0
            if num%i==0:
                while num%i==0:
                    count+=1
                    num=num//i
                if i not in dictt:
                    dictt[i]=count;
                else:
                    dictt[i]+=count
        if num!=1:
            if num not in dictt:
                dictt[num]=1
            else:
                dictt[num]+=1
    res=1
    for value in dictt.values():
        res*=(value+1)
    return res
main()
