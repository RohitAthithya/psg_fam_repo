# Functions are object data types

def functions_can_be_stored_in_variables():

    def shout(text):
        return text.upper()

    yell = shout

    print(yell("HOLA AMIGOOO!!!"))

def functions_can_be_passed_as_arguments_to_other_functions():

    def shout(text):
        return text.upper()

    def mumble(text):
        return text.lower()

    def greet(method:callable, text:str):
        print(method(text))

    greet(shout, "Inga paaru")
    greet(mumble, "watashiwa kami sama des")

def functions_can_return_another_function():

    def create_multiplier(x:int):
        def multiply_by_x(y:int):
            return (x * y)
        return multiply_by_x

    magic_function = create_multiplier(10)

    print(magic_function(3))
    print(magic_function(12))
    print(magic_function(-12))
    print(magic_function(0))
    print(magic_function(123.3231))
    print(magic_function(-0.999))

def addon_functions_can_return_another_function():

    def create_multiplier(x:int):
        print("I can also invariably do something else!")
        def multiply_by_x(y:int):
            return (x * y)
        return multiply_by_x

    magic_function = create_multiplier(10)

    print(magic_function(3))
    # print(magic_function(12))
    # print(magic_function(-12))
    # print(magic_function(0))
    # print(magic_function(123.3231))
    # print(magic_function(-0.999))

# functions_can_be_stored_in_variables()
# print("\n-------------------------------------------------------\n")
# functions_can_be_passed_as_arguments_to_other_functions()
# print("\n-------------------------------------------------------\n")
# functions_can_return_another_function()
# print("\n-------------------------------------------------------\n")
# addon_functions_can_return_another_function()
# print("\n-------------------------------------------------------\n")

#?---------------------------------------------------------------------------------------------------------------------------------
def internal_concept_of_decorators():
    def who_can_do_this_task(func:callable):

        def decorated_func_caller():
            print("who decorated this ? ")
            func()
            print("Oh! Okay!")

        # return decorated_func_caller() => this will just do an inital call not return an object lol!
        return decorated_func_caller

    def i_can_do_it():
        print("Decorated by komali")

        i_can_do_it()
        print("\n---------------After decoration----------------------------------------\n")
        i_can_do_it = who_can_do_this_task(i_can_do_it)
        i_can_do_it()

# internal_concept_of_decorators()

"""
# instead of doing
    i_can_do_it = who_can_do_this_task(i_can_do_it)
    i_can_do_it()

# what if we can do this:

    @heyDecorateThisFunction
    def i_can_do_it():
        print("Decorated by komali")
"""


import math
import time
def concept_of_decorators():

    def find_exceution_time(func:callable):
        print("Decorator applied")

        def _dummy_name(*args, **kwargs):
            start_time = time.time()
            _return_from_function = func(*args,**kwargs) # Return something that the funciton is going to return
            # func(*args,**kwargs)
            end_time = time.time()
            total_time_for_execution = end_time - start_time
            print(f"function's {total_time_for_execution =} ")
            return _return_from_function
            # return
        # return _dummy_name() => Don't do this mistake again ! CRIME!
        return _dummy_name

    @find_exceution_time
    def print_factorial_of_a_number(number:int):
        time.sleep(0.5)
        _ = math.factorial(number)
        # print( _ )
        return _

    print(print_factorial_of_a_number(5))



"""
    What if instead of doing a normal python function, you need a to perform something!?
    Okay, lets pass, other objects along with func:callable
"""

# def decorator_function(func:callable, temp_str:str):
#     def inner(*args, **kwargs):
#         print(temp_str)
#         val = func(*args, **kwargs)
#         print("Function decoarated!")
#         return val
#     return inner

# def factorial(num):
#     return math.factorial(num)

# factorial = decorator_function(factorial, "THis is factorial function")

# print(factorial(5))

# @decorator_function(factorial, temp_str="Oh my gawd")
# def factorial(num):
#     return math.factorial(num)

# print(factorial(5))

# the problem is we can't be able to send the arguments to the decorator like in this above section
# we get missing positional argument!

# that is why we have this bigger function!

# def argumeted_decorator(str1:str, str2:str):
#     def func_decorator(func:callable):
#         # need not use it here, but for sake of demonstration
#         def inner_wrapper(*args, **kwargs):
#             print(str1)

#             print("Pre processing")
#             _ret_val = func(*args, *kwargs)
#             print("Post processing")

#             print(str2)
#             return _ret_val
#         return inner_wrapper
#     return func_decorator


# def factorial(num):
#     print( math.factorial(num))

# real_decorator = argumeted_decorator("start", "end")
# factorial = real_decorator(factorial)
# factorial(5)

# @argumeted_decorator("start, ", "end ,")
# def factorial(num):
#     print( math.factorial(num))

# factorial(5)



"""
    WE can refactor this triple nested function with the itertools

Returns:
    _type_: _description_
"""


import functools

def func_decorator(func:callable, str1:str, str2:str):
    # need not use it here, but for sake of demonstration
    def inner_wrapper(*args, **kwargs):
        print(str1)

        print("Pre processing")
        _ret_val = func(*args, *kwargs)
        print("Post processing")

        print(str2)
        return _ret_val
    return inner_wrapper

str1 = "Start :"
str2 = ": end"
PreAndPostProcessor = functools.partial(func_decorator, str1=str1, str2=str2 )

@PreAndPostProcessor
def factorial(num):
    print( math.factorial(num))


factorial(5)
