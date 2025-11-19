
from dice import six_sided, make_test_dice
from ucb import main, trace, interact

GOAL = 100  # The goal of Hog is to score 100 points.

######################
# Phase 1: Simulator #
######################


def roll_dice(num_rolls, dice=six_sided):
    """模拟掷骰子恰好NUM_ROLLS次。返回结果之和，如果任何一个骰子结果为1，在这种情况下返回1。

    num_rolls: 掷骰子的次数。
    dice: 模拟单次骰子掷出结果的函数。默认为六面骰。
    """
    # 这些assert语句确保num_rolls是一个正整数。
    assert type(num_rolls) == int, 'num_rolls必须是整数。'
    assert num_rolls > 0, '必须至少掷一次。'
    # 开始问题1
    "*** 在这里填写你的代码 ***"
    k,total_score=0,0
    flag=0
    while k<num_rolls:
        score=dice()
        if(score==1):
            flag=1
        total_score+=score
        k+=1
    if(flag):
        return 1
    return total_score

    # 结束问题1


def boar_brawl(player_score, opponent_score):

    """根据Boar Brawl规则返回0次掷骰子得到的分数。
    
    选择掷零骰子的玩家得分为对手得分的十位数字与当前玩家得分的个位数字之间的绝对差值的三倍，

    或 1，以较大者为准。个位是指最右边的数字，十位是指倒数第二个数字。

    如果玩家的分数是个位数（小于 10），则该玩家分数的十位数为 0。
    player_score: 当前玩家的总分。
    opponent_score: 对手的总分。
    """
    # 开始问题2
    #在这里开始填写你的代码
    num1=opponent_score%100//10
    num2=player_score%10
    score=3*abs(num1-num2)
    return max(score,1)
    # 结束问题2


def take_turn(num_rolls, player_score, opponent_score, dice=six_sided):
    """返回在当前玩家有PLAYER_SCORE分，对手有OPPONENT_SCORE分时，掷NUM_ROLLS次骰子得到的分数。

    num_rolls: 掷骰子的次数。
    player_score: 当前玩家的总分。
    opponent_score: 对手的总分。
    dice: 模拟单次骰子掷出结果的函数。
    """
    # 留下这些assert语句，它们有助于检查错误。
    assert type(num_rolls) == int, 'num_rolls必须是整数。'
    assert num_rolls >= 0, '在take_turn中不能掷负数次骰子。'
    assert num_rolls <= 10, '不能掷超过10次骰子。'
    # 开始问题3
    #在这里开始填写你的代码
    if(num_rolls==0):
        return boar_brawl(player_score,opponent_score)
    else:
        return roll_dice(num_rolls,dice)
    # 结束问题3


def simple_update(num_rolls, player_score, opponent_score, dice=six_sided):
    """返回一个玩家开始回合时有PLAYER_SCORE分，然后掷NUM_ROLLS次骰子后的总分，忽略Sus Fuss规则。
    """
    score = player_score + take_turn(num_rolls, player_score, opponent_score, dice)
    return score

def is_prime(n):
    """返回N是否为质数。"""
    if n == 1:
        return False
    k = 2
    while k < n:
        if n % k == 0:
            return False
        k += 1
    return True

def num_factors(n):
    """返回N的因子数量，包括1和N本身。"""
    # 开始问题4
    #在这里开始填写你的代码
    num,k=1,2
    while k<=n:
        if n%k==0:
            num+=1
        k+=1
    return num

    # 结束问题4

def sus_points(score):
    """返回考虑Sus Fuss规则的玩家新分数。

    如果一个数正好有 3 或 4 个因数（包括 1 和该数本身），我们称该数为 sus 。

    如果滚动后当前玩家的分数是 sus 数字，则他们的分数立即增加到下一个素数。"""
    # 开始问题4
    #在这里开始填写你的代码
    factors=num_factors(score)
    if(factors==3 or factors==4):
        while(not is_prime(score)):
            score+=1
    return score
    # 结束问题4

def sus_update(num_rolls, player_score, opponent_score, dice=six_sided):
    """返回一个玩家开始回合时有PLAYER_SCORE分，然后掷NUM_ROLLS次骰子后的总分，*包括*Sus Fuss规则。
    """
    # 开始问题4
    #在这里开始填写你的代码
    score=simple_update(num_rolls,player_score,opponent_score,dice)
    score=sus_points(score)
    return score
    # 结束问题4


def always_roll_5(score, opponent_score):
    """无论玩家的分数或对手的分数如何，总是掷5次骰子的策略。"""
    return 5


def play(strategy0, strategy1, update,
         score0=0, score1=0, dice=six_sided, goal=GOAL):
    """模拟一局游戏并返回两位玩家的最终分数，玩家0的分数在前，玩家1的分数在后。

    例如，play(always_roll_5, always_roll_5, sus_update)模拟了一局游戏中两位玩家总是选择掷5次骰子，并且Sus Fuss规则生效。

    策略函数，如always_roll_5，接受当前玩家的分数和对手的分数，并返回当前玩家选择掷的骰子数量。

    更新函数，如sus_update或simple_update，接受掷骰子的数量、当前玩家的分数、对手的分数以及用于模拟掷骰子的dice函数。它返回当前玩家回合结束后更新的分数。

    strategy0: 玩家0的策略。
    strategy1: 玩家1的策略。
    update: 更新函数（对两位玩家都使用）。
    score0: 玩家0的起始分数。
    score1: 玩家1的起始分数。
    dice: 一个无参数函数，用于模拟掷骰子。
    goal: 游戏结束并且有人获胜的分数。
    """
    who = 0   # 谁即将进行回合，0（第一个）或1（第二个）
    # 开始问题5
    #在这里开始填写你的代码
    while(score0<goal and score1<goal):
        if who==0:
            score0=update(strategy0(score0,score1),score0,score1,dice)
        else:
            score1=update(strategy1(score1,score0),score1,score0,dice)
        who=1-who
    # 结束问题5
    return score0, score1


#######################
# Phase 2: Strategies #
#######################


def always_roll(n):
    """返回一个总是掷N次骰子的玩家策略。

    玩家策略是一个函数，它接受两个总分数作为参数（当前玩家的分数和对手的分数），并返回当前玩家这一回合将掷的骰子数量。

    >>> strategy = always_roll(3)
    >>> strategy(0, 0)
    3
    >>> strategy(99, 99)
    3
    """
    assert n >= 0 and n <= 10
    # 开始问题6
    #在这里开始填写你的代码
    def strategy(player_score,opponent_score):
        return n
    return strategy
    # 结束问题6


def catch_up(score, opponent_score):
    """一个总是掷5次骰子的玩家策略，除非对手的分数更高，在这种情况下掷6次。

    >>> catch_up(9, 4)
    5
    >>> strategy(17, 18)
    6
    """
    if score < opponent_score:
         return 6   # 多掷一次以追上
    else:
         return 5


def is_always_roll(strategy, goal=GOAL):
    """返回STRATEGY是否总是选择掷相同数量的骰子，给定一个达到GOAL点的游戏。

    >>> is_always_roll(always_roll_5)
    True
    >>> is_always_roll(always_roll(3))
    True
    >>> is_always_roll(catch_up)
    False
    """
    # 开始问题7
    #在这里开始填写你的代码
    first_call=strategy(0,0)
    for player_score in range(0,goal):
        for(opponent_score) in range(0,goal):
            if(strategy(player_score,opponent_score)!=first_call):
               return False
    return True
    # 结束问题7


def make_averaged(original_function, times_called=1000):
    """返回一个函数，它返回调用ORIGINAL_FUNCTION多次后的平均值。

    要实现这个函数，你将不得不使用*args语法。

    >>> dice = make_test_dice(4, 2, 5, 1)
    >>> averaged_dice = make_averaged(roll_dice, 40)
    >>> averaged_dice(1, dice)   # 10个4，10个2，10个5和10个1的平均值
    3.0
    """
    # 开始问题8
    #在这里开始填写你的代码
    def averaged_function(*args):
        total=0
        for i in range(1,times_called+1):
            total+=original_function(*args)
        total/=times_called
        return total
    return averaged_function
    # 结束问题8


def max_scoring_num_rolls(dice=six_sided, times_called=1000):
    """返回掷1到10次骰子中，每次能得到期望分数最高时对应的次数。
    假设骰子总是返回正数结果。

    >>> dice = make_test_dice(1, 6)
    >>> max_scoring_num_rolls(dice)
    1
    """
    # 开始问题9
    #在这里开始填写你的代码
    roll_dice_average=make_averaged(roll_dice,times_called)
    max_score=0
    num_roll=0
    for i in range(1,11):
        current_score=roll_dice_average(i,dice)
        if(max_score<current_score):
            max_score=current_score
            num_roll=i
    return num_roll
    # 结束问题9


def winner(strategy0, strategy1):
    """如果strategy0战胜strategy1返回0，否则返回1。"""
    score0, score1 = play(strategy0, strategy1, sus_update)
    if score0 > score1:
         return 0
    else:
         return 1


def average_win_rate(strategy, baseline=always_roll(6)):
    """返回STRATEGY相对于BASELINE的平均胜率。计算当作为玩家0和玩家1开始游戏时的胜率平均值。
    """
    win_rate_as_player_0 = 1 - make_averaged(winner)(strategy, baseline)
    win_rate_as_player_1 = make_averaged(winner)(baseline, strategy)

    return (win_rate_as_player_0 + win_rate_as_player_1) / 2


def run_experiments():
    """运行一系列策略实验并报告结果。"""
    six_sided_max = max_scoring_num_rolls(six_sided)
    print('六面骰子最大得分次数:', six_sided_max)

    print('always_roll(6)胜率:', average_win_rate(always_roll(6))) # 接近0.5
    print('catch_up胜率:', average_win_rate(catch_up))
    print('always_roll(3)胜率:', average_win_rate(always_roll(3)))
    print('always_roll(8)胜率:', average_win_rate(always_roll(8)))

    print('boar_strategy胜率:', average_win_rate(boar_strategy))
    print('sus_strategy胜率:', average_win_rate(sus_strategy))
    print('final_strategy胜率:', average_win_rate(final_strategy))
    "*** 你可以根据需要添加更多的实验 ***"



def boar_strategy(score, opponent_score, threshold=11, num_rolls=6):
    """这个策略在Boar Brawl得分至少为THRESHOLD时返回0次掷骰子，否则返回NUM_ROLLS。忽略分数和Sus Fuss。
    """
    # 开始问题10
    current_score=boar_brawl(score,opponent_score)
    if current_score>=threshold:
        return 0
    return num_rolls   # 一旦实现，删除这行代码。
    # 结束问题10


def sus_strategy(score, opponent_score, threshold=11, num_rolls=6):
    """这个策略在你的分数至少增加THRESHOLD时返回0次掷骰子。"""
    # 开始问题11
    current_score=sus_update(0,score,opponent_score)
    if current_score-score>=threshold:
        return 0
    return num_rolls   # 一旦实现，删除这行代码。
    # 结束问题11


def final_strategy(score, opponent_score):
    """写一段关于你的最终策略的简短描述。

    *** 你的描述在这里 ***
    """
    # 开始问题12
    return 6   # 一旦实现，删除这行代码。
    # 结束问题12


##########################
# Command Line Interface #
##########################

# 注意：这个部分的函数不需要改变。它使用了课程尚未涵盖的Python特性。

@main
def run(*args):
    """读取命令行参数并调用相应的函数。"""
    import argparse
    parser = argparse.ArgumentParser(description="Play Hog")
    parser.add_argument('--run_experiments', '-r', action='store_true',
                        help='运行策略实验')

    args = parser.parse_args()

    if args.run_experiments:
         run_experiments()