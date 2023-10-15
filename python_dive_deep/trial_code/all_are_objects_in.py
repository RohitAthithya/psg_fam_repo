def add(a,b):
    print( a+b)

def sub(a,b):
    print( a-b)

def decide(input_str):
    if input_str == "ADD":
        return add
    elif input_str == "SUB":
        return sub
    else:
        return None

decide("ADD")(5, 10)
decide("SUB")(10, 40)

print(add is decide("ADD"))
print(sub is decide("SUB"))
