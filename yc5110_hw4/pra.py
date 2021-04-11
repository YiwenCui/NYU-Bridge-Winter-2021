sum =0
num = 38
while num>0:
    currentDigit = num%10
    sum += currentDigit
    num=num/10
            
    if num==0 and len(str(sum))!=1:
        num = sum
    elif num==0 and len(str(sum))==1:
        break
print(sum)