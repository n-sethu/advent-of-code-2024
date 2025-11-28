file = open("input1.txt", "r")
l1=[]
l2=[]
for line in file:
    num1, num2 = map(int, line.split())
    l1.append(num1)
    l2.append(num2)
l1.sort()
l2.sort()

total=0
for i in range(len(l1)):
    total+=abs(l1[i]-l2[i]);
print(total)
