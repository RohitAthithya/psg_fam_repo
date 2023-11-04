


def convert_form_base10(number:int, new_base:int) -> list:
    if new_base < 2:
        raise ValueError("new_base must be > 2")
    if number < 0:
        raise ValueError("-ve numbers are not supported in this function")
    if number == 0:
        return [0]

    digits = []
    while number > 0:
        number, new_digit = divmod(number, new_base)
        # number = number // new_base
        # remainder = number % new_base
        digits.insert(0, new_digit)
    return digits
    # note that this program does not provide the
    # encoded symbol for numbers
    # whose value >= 10 in decimal base


def encoding(digits, digit_map):
    if max(digits) >= len(digit_map):
        raise ValueError("given digit_map does not contain encoding info of given digits")

    encoding = ""
    for digit in digits:
        encoding += digit_map[digit]
    return encoding

hex_encoding = {
    0 : '0',
    1 : '1',
    2 : '2',
    3 : '3',
    4 : '4',
    5 : '5',
    6 : '6',
    7 : '7',
    8 : '8',
    9 : '9',
    10 : 'A',
    11 : 'B',
    12 : 'C',
    13 : 'D',
    14 : 'E',
    15 : 'F'
}


#combined functionality
def rebase_from_10(target_number:int, target_base:int):
    encoding_values = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if (target_base < 2) or (target_base > 36):
        raise ValueError("Target base needs to be in range [2 ,36]")

    sign = -1 if target_number < 0 else 1
    target_number *= sign
    # consider only the +ve no., once rebased, sign can be added to the front!

    digits = convert_form_base10(target_number, target_base)
    rebased_number:str = encoding(digits, encoding_values)
    sign_str:str = "-" if sign < 0 else ""

    return  sign_str+rebased_number





if __name__ == "__main__":
    # 10 as binary
    print(convert_form_base10(100, 2))
    # 255 as hex value
    # print(encoding(convert_form_base10(255, 16), hex_encoding))
    # print(encoding(convert_form_base10(123, 16), hex_encoding))

    print(rebase_from_10(100, 16))
    print(rebase_from_10(100, 2))
    print(rebase_from_10(999123, 36))