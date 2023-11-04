import socket

STD_RECV_BYTE_SIZE = 1024
STD_ENCODING = "UTF-8"


client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((socket.gethostname(),27015))

# msg = client.recv(STD_RECV_BYTE_SIZE).decode(STD_ENCODING)
# print(msg)
while True:
    msg = client.recv(STD_RECV_BYTE_SIZE).decode(STD_ENCODING)
    print(msg)
    msg = f"I received: {msg}\r\n"
    # while not msg.endswith("\r\n"):
    client.send(bytes(msg, STD_ENCODING))
    # client.close()


