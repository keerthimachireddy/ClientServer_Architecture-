# ClientServer_Architecture-
This cpp program is about Client Server Architecture, how a socket allows end point communication, how a client and server is communicated etc.

step-1: create a socket
step-2: bind the socket (which ip and port does this server listens to?)
step-3: 



                 SERVER                         CLIENT
                   │                              │
                socket()                       socket()
                   │                              │
                bind()                           │
                   │                              │
               listen()                          │
                   │                              │
               accept() ◄──────────────────── connect()
                   │
                   │
                   │◄─────── "Hello Server!" ────┤
                   │         send()
                   │
                 recv()
                   │
                   │
                 send()
                   │
                   ├─────── "Hello Client!" ────►│
                   │                              │
                   │                            recv()
                   │                              │
                 close()                        close()
