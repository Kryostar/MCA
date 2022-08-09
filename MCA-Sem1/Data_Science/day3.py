# Abhijit S A
# Day 3 Assigment
tup=(121,123,234,343)
for item in tup:
    rev=0
    temp=item
    while(temp>0):
        rem=temp%10
        rev=rev*10+rem
        temp=temp//10
    if(item==rev):
        print("The number is palindrome!")
    else:
        print("Not a palindrome!")
