import socket
from random import random
from time import sleep
STD_RECV_BYTE_SIZE = 1024
STD_ENCODING = "UTF-8"
HEADER_SIZE = 10

# we can use the fixed length headers:
# the client/server must read this header size, some useful
# info can be added here about the incoming msg
# may be like the lenght of the characters!
# some people use the checksum, thus ensuring data loss is not present
# using checkum they can understand if incoming is the right data or not!

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((socket.gethostname(), 27015))

server.listen()


def sensor_data() -> float:
    sleep(3) # data processing or retrieval time from sensor!
    return random()*10

while True:
    client_socket, client_address = server.accept()
    msg = "Welcome to the Python server"
    msg = f"{len(msg):<{HEADER_SIZE}}{msg}"

    client_socket.send(bytes(msg, encoding=STD_ENCODING))

    #stream sensor data;
    while True:
        sensor_msg = str(sensor_data())
        sensor_msg = f"{len(sensor_msg):<{HEADER_SIZE}}{sensor_msg}"
        client_socket.send(bytes(sensor_msg, encoding="UTF-8"))
