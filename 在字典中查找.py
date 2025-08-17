dictionary = {'screen':'显示器',
              'CPU':'中央处理器',
              'GPU':'画面处理器',
              'memory':'内存',
              'keyboard':'键盘',
              'mouse':'鼠标',
              'system':'系统'}
user_input = input("请输入您想查找的电脑英语术语： ")
if user_input in dictionary.keys():
    print('您所查找的'+user_input+'的中文意思为'+dictionary[user_input])
else:
    print('抱歉，您所查找的'+user_input+'未被收录')
    print('目前已收录的条数为'+str(len(dictionary)))