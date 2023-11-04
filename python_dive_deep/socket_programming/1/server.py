import socket
STD_RECV_BYTE_SIZE = 1024
STD_ENCODING = "UTF-8"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((socket.gethostname(), 27015))

server.listen()


while True:
    client_socket, client_address = server.accept()
    print(f"Connection from {client_address} - Established")
    client_socket.send(bytes("vanakkam", STD_ENCODING))
    msg = ""
    while not msg.endswith("\r\n"):
        msg = client_socket.recv(STD_RECV_BYTE_SIZE).decode(encoding=STD_ENCODING)
        print(f"recv: {msg}")

    if msg.endswith("\r\n"):
        server.close()
        break

print("Server exited!")