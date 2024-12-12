import socket

host = '127.0.0.1'
port = 8000
lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.bind((host, port))
lk.listen()
while True:
    client, address = lk.accept()
    response = client.recv(1024)
    if response:
        print("text received is: " + response.decode())
        msg = "text in uppercase: " + response.decode().upper()
        client.send(msg.encode())
    client.close()