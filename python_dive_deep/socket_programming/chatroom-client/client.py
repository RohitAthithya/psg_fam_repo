import socket
import select
import errno
import sys
from traceback import format_exc
HEADER_LENGTH = 10

IP = "127.0.0.1"
PORT = 27015
my_username = input("Username: ")

# Create a socket
# socket.AF_INET - address family, IPv4, some otehr possible are AF_INET6, AF_BLUETOOTH, AF_UNIX
# socket.SOCK_STREAM - TCP, conection-based, socket.SOCK_DGRAM - UDP, connectionless, datagrams, socket.SOCK_RAW - raw IP packets
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to a given ip and port
client_socket.connect((IP, PORT))

# Set connection to non-blocking state, so .recv() call won;t block, just return some exception we'll handle
client_socket.setblocking(False)

# Prepare username and header and send them
# We need to encode username to bytes, then count number of bytes and prepare header of fixed size, that we encode to bytes as well
username = my_username.encode('utf-8')
username_header = f"{len(username):<{HEADER_LENGTH}}".encode('utf-8')
client_socket.send(username_header + username)

while True:

    # Wait for user to input a message
    message = input(f'{my_username} > ')

    # If message is not empty - send it
    if message:

        # Encode message to bytes, prepare header and convert to bytes, like for username above, then send
        message = message.encode('utf-8')
        message_header = f"{len(message):<{HEADER_LENGTH}}".encode('utf-8')
        client_socket.send(message_header + message)

    try:
        # Now we want to loop over received messages (there might be more than one) and print them
        while True:

            # Receive our "header" containing username length, it's size is defined and constant
            username_header = client_socket.recv(HEADER_LENGTH)

            # If we received no data, server gracefully closed a connection, for example using socket.close() or socket.shutdown(socket.SHUT_RDWR)
            if not len(username_header):
                print('Connection closed by the server')
                sys.exit()

            # Convert header to int value
            username_length = int(username_header.decode('utf-8').strip())

            # Receive and decode username
            username = client_socket.recv(username_length).decode('utf-8')

            # Now do the same for message (as we received username, we received whole message, there's no need to check if it has any length)
            message_header = client_socket.recv(HEADER_LENGTH)
            message_length = int(message_header.decode('utf-8').strip())
            message = client_socket.recv(message_length).decode('utf-8')

            # Print message
            print(f'{username} > {message}')

    except IOError as e:
        # This is normal on non blocking connections - when there are no incoming data error is going to be raised
        # Some operating systems will indicate that using AGAIN, and some using WOULDBLOCK error code
        # We are going to check for both - if one of them - that's expected, means no incoming data, continue as normal
        # If we got different error code - something happened
        if e.errno != errno.EAGAIN and e.errno != errno.EWOULDBLOCK:
            print(f'Reading error: {e} :: {format_exc()}')
            sys.exit()

        # We just did not receive anything
        continue

    except Exception as e:
        # Any other exception - something happened, exit
        print(f'Reading error: {e} :: {format_exc()}')
        sys.exit()

# import sys
# import socket
# import select
# import errno



# # on immediate conenction client tells the server what theeir username is
# # then whenever the clients has a message , it will send the message to the server


# STD_ENCODING = "UTF-8"
# HEADER_LENGTH = 10

# IP = "127.0.0.1"
# PORT = 27015

# my_username = input("Username? :")
# client_socket  = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# client_socket.connect((IP, PORT))
# client_socket.setblocking(False)

# ``

# username = my_username.encode(encoding=STD_ENCODING)
# username_header = f"{len(username):<{HEADER_LENGTH}}".encode(encoding=STD_ENCODING)

# client_socket.send(username_header + username)

# # we want to send and receive msgs
# while True:
#     message = input(f"{my_username} > ")

#     if message:
#         message = message.encode(encoding=STD_ENCODING)
#         message_header =  f"{len(message):<{HEADER_LENGTH}}".encode(encoding=STD_ENCODING)

#         final_msg = message_header + message
#         client_socket.send(final_msg)

#     # regardless or whether or not there are updates,
#     # lets re
#     try:
#         while True:
#             # receive things
#             username_header = client_socket.recv(HEADER_LENGTH)
#             if not len(username_header):
#                 print("Connection closed by the server")
#                 sys.exit()
#             # otherwie conver the username header into a int
#             username_length = int(username_header.decode(encoding=STD_ENCODING).strip())
#             username = client_socket.recv(username_length).decode(encoding=STD_ENCODING)

#             message_header = client_socket.recv(HEADER_LENGTH)
#             message_length = int(message_header.decode(STD_ENCODING))
#             message = client_socket.recv(message_length).decode(STD_ENCODING)
#             print(f"{username} > {message}")


#     except IOError as e:
#         if e.errno != errno.EAGAIN or e.errno != errno.EWOULDBLOCK:# os related error!
#             print(f"Reading Error : {str(e)}")
#             sys.exit()
#         continue

#     except Exception as e:
#         pass
