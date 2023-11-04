# import socket
# import select

# HEADER_LENGTH = 10

# IP = "127.0.0.1"
# PORT = 1234

# # Create a socket
# # socket.AF_INET - address family, IPv4, some otehr possible are AF_INET6, AF_BLUETOOTH, AF_UNIX
# # socket.SOCK_STREAM - TCP, conection-based, socket.SOCK_DGRAM - UDP, connectionless, datagrams, socket.SOCK_RAW - raw IP packets
# server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# # SO_ - socket option
# # SOL_ - socket option level
# # Sets REUSEADDR (as a socket option) to 1 on socket
# server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# # Bind, so server informs operating system that it's going to use given IP and port
# # For a server using 0.0.0.0 means to listen on all available interfaces, useful to connect locally to 127.0.0.1 and remotely to LAN interface IP
# server_socket.bind((IP, PORT))

# # This makes server listen to new connections
# server_socket.listen()

# # List of sockets for select.select()
# sockets_list = [server_socket]

# # List of connected clients - socket as a key, user header and name as data
# clients = {}

# print(f'Listening for connections on {IP}:{PORT}...')

# # Handles message receiving
# def receive_message(client_socket):

#     try:

#         # Receive our "header" containing message length, it's size is defined and constant
#         message_header = client_socket.recv(HEADER_LENGTH)

#         # If we received no data, client gracefully closed a connection, for example using socket.close() or socket.shutdown(socket.SHUT_RDWR)
#         if not len(message_header):
#             return False

#         # Convert header to int value
#         message_length = int(message_header.decode('utf-8').strip())

#         # Return an object of message header and message data
#         return {'header': message_header, 'data': client_socket.recv(message_length)}

#     except:

#         # If we are here, client closed connection violently, for example by pressing ctrl+c on his script
#         # or just lost his connection
#         # socket.close() also invokes socket.shutdown(socket.SHUT_RDWR) what sends information about closing the socket (shutdown read/write)
#         # and that's also a cause when we receive an empty message
#         return False

# while True:

#     # Calls Unix select() system call or Windows select() WinSock call with three parameters:
#     #   - rlist - sockets to be monitored for incoming data
#     #   - wlist - sockets for data to be send to (checks if for example buffers are not full and socket is ready to send some data)
#     #   - xlist - sockets to be monitored for exceptions (we want to monitor all sockets for errors, so we can use rlist)
#     # Returns lists:
#     #   - reading - sockets we received some data on (that way we don't have to check sockets manually)
#     #   - writing - sockets ready for data to be send thru them
#     #   - errors  - sockets with some exceptions
#     # This is a blocking call, code execution will "wait" here and "get" notified in case any action should be taken
#     read_sockets, _, exception_sockets = select.select(sockets_list, [], sockets_list)


#     # Iterate over notified sockets
#     for notified_socket in read_sockets:

#         # If notified socket is a server socket - new connection, accept it
#         if notified_socket == server_socket:

#             # Accept new connection
#             # That gives us new socket - client socket, connected to this given client only, it's unique for that client
#             # The other returned object is ip/port set
#             client_socket, client_address = server_socket.accept()

#             # Client should send his name right away, receive it
#             user = receive_message(client_socket)

#             # If False - client disconnected before he sent his name
#             if user is False:
#                 continue

#             # Add accepted socket to select.select() list
#             sockets_list.append(client_socket)

#             # Also save username and username header
#             clients[client_socket] = user

#             print('Accepted new connection from {}:{}, username: {}'.format(*client_address, user['data'].decode('utf-8')))

#         # Else existing socket is sending a message
#         else:

#             # Receive message
#             message = receive_message(notified_socket)

#             # If False, client disconnected, cleanup
#             if message is False:
#                 print('Closed connection from: {}'.format(clients[notified_socket]['data'].decode('utf-8')))

#                 # Remove from list for socket.socket()
#                 sockets_list.remove(notified_socket)

#                 # Remove from our list of users
#                 del clients[notified_socket]

#                 continue

#             # Get user by notified socket, so we will know who sent the message
#             user = clients[notified_socket]

#             print(f'Received message from {user["data"].decode("utf-8")}: {message["data"].decode("utf-8")}')

#             # Iterate over connected clients and broadcast message
#             for client_socket in clients:

#                 # But don't sent it to sender
#                 if client_socket != notified_socket:

#                     # Send user and message (both with their headers)
#                     # We are reusing here message header sent by sender, and saved username header send by user when he connected
#                     client_socket.send(user['header'] + user['data'] + message['header'] + message['data'])

#     # It's not really necessary to have this, but will handle some socket exceptions just in case
#     for notified_socket in exception_sockets:

#         # Remove from list for socket.socket()
#         sockets_list.remove(notified_socket)

#         # Remove from our list of users
#         del clients[notified_socket]


import socket
import pickle
from time import sleep

# manage different clients

import select # os level options, to select a partiuclar process

STD_ENCODING = "UTF-8"
HEADER_LENGTH = 10
IP = "127.0.0.1"
PORT = 27015


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Sometimes the port number get engaged if another instance of the same code is running!
# error: port is being utilised by some other program or so!
# socket option level => SOL
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # allows us to reconnect
server.bind((IP, PORT))

server.listen() # this is what makes this socket a 'server'

socket_list = [server]


client_dict:dict[socket.socket, dict] = {}

# Server's work:
# simply receive messages from the clients

def receive_messages(client_socket:socket.socket):
    try:
        msg_header = client_socket.recv(HEADER_LENGTH)

        # if we dont receive any msg => client closed the connection probably!
        if not len(msg_header):
            return False

        msg_len = int(msg_header.decode(encoding=STD_ENCODING).strip())

        return {
            'header' : msg_header,
            'data' : client_socket.recv(msg_len) # notice we receiving and appending the bytes till we reach that particular length!
        }

    except:
        return False


# __main__
while True: # read list, write list, sockets that might error out
    read_sockets, _, exception_socket = select.select(socket_list, [], socket_list)

    # core logic
    for notified_socket in read_sockets:
        #if someone just connected!
        if notified_socket  == server:
            client_socket, client_address = server.accept()

            user_msg = receive_messages(client_socket)

            if not user_msg :
                continue

            socket_list.append(client_socket)

            client_dict[client_socket] = user_msg

            print(f"Accepted new connection from the {client_address[0]}:{client_address[1]}"
                f"username:{user_msg['data'].decode(encoding=STD_ENCODING)}"
            )

        else:
            # if already connected user
            message = receive_messages(notified_socket)

            if not message:
                print(f"Closed the connection:"
                    f"{client_dict[notified_socket]['data'].decode(encoding=STD_ENCODING)}"
                )
                socket_list.remove(notified_socket)
                del client_dict[notified_socket]
                continue

            user = client_dict[notified_socket]
            print(f"Received msg from {user['data'].decode(encoding=STD_ENCODING)}"
                    F":{message['data'].decode(encoding=STD_ENCODING)}"
            )

            # notify all the clients about the info received
            for client_socket in client_dict:
                if client_socket != notified_socket:
                    client_socket.send(user['data'] + message['header'] + message['data'])


    for notified_socket in exception_socket:
        socket_list.remove(notified_socket)
        del client_dict[notified_socket]























