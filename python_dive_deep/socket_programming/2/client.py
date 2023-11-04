import socket

STD_ENCODING = "UTF-8"
HEADER_SIZE = 10
STD_RECV_BYTE_SIZE = HEADER_SIZE + 4

# Header size should be atleast big enough to read the
# incoming message's header!

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((socket.gethostname(),27015))

while True:

    full_msg = ""
    flag_new_msg = True

    while True:
        msg = client.recv(STD_RECV_BYTE_SIZE)
        full_msg += msg.decode(STD_ENCODING)
        if flag_new_msg:
            in_msg_len = int(full_msg[:HEADER_SIZE].strip())
            print(f"incoming message length = {in_msg_len}")
            flag_new_msg = False


        if ((in_msg_len + HEADER_SIZE) <= len(full_msg)): # reached the end of the input msg as indicated by the number in the header of the input msg.
            print("Full msg recvd")
            print(f"{full_msg[HEADER_SIZE:(in_msg_len + HEADER_SIZE)]=}") # We dont't want to se the HEADER in the outptu!
            # we have agreed that the the first 10 characters will be containing the length of the msg to be sent
            flag_new_msg = True
            full_msg = full_msg[(in_msg_len + HEADER_SIZE):]




