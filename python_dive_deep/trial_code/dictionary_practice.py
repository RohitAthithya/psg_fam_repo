dictt = {0:0, 1:1, 2:2}

print(dictt)

for _,__ in dictt.items():
    print(_ , __)


dictt[1] = 123123
dictt[0] = -134

for _,__ in dictt.items():
    print(_ , __)


