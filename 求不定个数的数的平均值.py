total = 0
num = 0
while True:
    users_input = input('请输入数据以求平均值，停止输入时请输入q； ')
    if users_input != 'q':
        total+=float(users_input)
        num+=1
    else:
        break
if num !=0:
    average = total / num
    print('您所输入的数据的平均值为'+str(average))
else:
    print('您所输入的数据的平均值为0')