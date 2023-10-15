# Program to convert a Comma separated string into  Space seperated string

while(input("press enter to continue , 'n' to exit: ").strip().lower() != "n" ):
    numbers_list = input("Enter comma separated string: ").split(',')
    tab_separated_str = '    '.join(numbers_list)
    print(tab_separated_str)
