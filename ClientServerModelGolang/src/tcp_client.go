package main

import (
  "net"
  "log"
)

func main() {
  conn, err := net.Dial("tcp",":8080" )
  checkError(err)
  //defer conn.Close()
  _, err = conn.Write([]byte("Something needs to be sent"))
  checkError(err)

  var n []byte
  _, err = conn.Read(n)
  checkError(err)
  

}

func checkError(err error) {
  if err!= nil {
  log.Fatal(err)
  }
}
