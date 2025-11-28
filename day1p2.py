file = open("input1.txt", "r")
l1=[]
l2=[]
for line in file:
    num1, num2 = map(int, line.split())
    l1.append(num1)
    l2.append(num2)
l1.sort()
l2.sort()

right_count = dict()
for i in range(len(l2)):
    right_count[l2[i]] = right_count.get(l2[i], 0) + 1   
     
sim_score=0
for i in range(len(l1)):
    if(l1[i] in right_count):
        sim_score+=l1[i]*right_count[l1[i]]

print(sim_score)