import socket
from random import random
from time import sleep
import pickle





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



# random_set = {1,10,123,4431,589134,101}

# msg = pickle.dumps(random_set)
# print(msg)




def sensor_data() -> float:
    sleep(3) # data processing or retrieval time from sensor!
    return random()*10

def sensor_data_advanced() -> bytes:
    """Collect and Return pickled sensor data

    Returns:
        bytes: temperature and humidity data in bytes of pickled dict.
            e.g.:   data = {
                        'temperature':
                            ...,
                        'humidity':
                            ...
                    }
    """
    sleep(3)
    data = {
        'temperature':
            random()*10,
        'humidity':
            round(random()*100)
    }
    return pickle.dumps(data)


while True:
    client_socket, client_address = server.accept()
    # msg = "Welcome to the Python server"
    # msg = f"{len(msg):<{HEADER_SIZE}}{msg}"

    # client_socket.send(bytes(msg, encoding=STD_ENCODING))

    # random_set = {1,10,123,4431,589134,101}

    # msg = pickle.dumps(random_set)
    # msg = bytes(f"{len(msg):<{HEADER_SIZE}}", encoding=STD_ENCODING) + msg


    #stream sensor data;
    while True:
        sensor_msg = sensor_data_advanced()
        sensor_msg = bytes(f"{len(sensor_msg):<{HEADER_SIZE}}", encoding=STD_ENCODING) + sensor_msg
        client_socket.send(sensor_msg)

















