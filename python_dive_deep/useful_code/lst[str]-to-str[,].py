while(input("press enter to continue , 'n' to exit: ").strip().lower() != "n" ):
    jt_sp = input('Enter SPACE seperated joint data: ').split(' ')
    count = len(jt_sp)
    itervar = 0
    while itervar < count:
        if jt_sp[itervar] == '':
            jt_sp.pop(itervar)
            count -= 1
        else:
            itervar += 1
    out_str = ",".join(jt_sp)
    print()
    print(out_str)
    print()