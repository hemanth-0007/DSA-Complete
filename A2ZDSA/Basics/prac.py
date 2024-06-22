
N = int(input())
names = []
for i in range(N):
    names.append(list(input().split(" ")))
mp = {}
for i in range(N):
    temp_str = ""
    for j in range(len(names[i]) -1):
        temp_str += names[i][j].lower()
    # print(temp_str, names[i][len(names[i])-1])
    cur_val  = int(names[i][len(names[i]) -1])
    if mp.get(temp_str) is not None:
        prev_ind , value = mp.get(temp_str)
        # print(prev_ind, value)
        if value <= cur_val:
            mp[temp_str] = [prev_ind,cur_val ]
    else:
        mp[temp_str] = [i, cur_val]
# ind , value = mp.get("kesavibhavya")
# print(ind , value)
# print(mp)
max_val = -1
max_ind = -1
max_name = ""
for name, lis in mp.items():
    # print(name, lis)
    ind , value = lis
    print(name , ind , value)
    if value > max_val:
        max_ind = ind
        max_val = value
        max_name = name
print(max_name + " " + str(max_val))



# command to run the code with the input file input.txt in the same directory
# python prac.py < input.txt
# for windows the command is diffrent from the linux 
# for windows the command is
