package main

import (
  "net"
  "log"
)

func main() {
  ln, err := net.Listen("tcp", ":8080")
checkError(err)
for {
	conn, err := ln.Accept()
	if err != nil {
		continue
	}
	go handleClient(conn)
}
}

func checkError(err error) {
  if err!= nil {
  log.Fatal(err)
  }
}

func handleClient(conn net.Conn) {
    defer conn.Close()

    var buf []byte
    for {
        n, err := conn.Read(buf[0:])
        if err != nil {
            return
        }
        _, err2 := conn.Write(buf[0:n])
        if err2 != nil {
            return
        }
    }
}
