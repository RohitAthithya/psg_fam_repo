def my_func():
    a = 24 * 60
    b = 1000 * 1231313123
    d = 'ab' * 10
    c = 'ab' * 11
    f = [1,2]  * 10
    g = [1,2]  * 11

def my_func2():
    a = 24 * 60
    b = 1000 * 1231313123
    d = 'ab' * 10
    c = 'ABCDEF' * 11
    g = [1]  * 10


print(f"{my_func.__code__.co_consts=}")


print(f"{my_func2.__code__.co_consts=}")




