import socket

host = '127.0.0.1'
port = 8000
lk = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
lk.connect((host, port))
print("sending data hello")
lk.send("server client hello".encode())
response = lk.recv(1024)
print(response.decode())
lk.close()
