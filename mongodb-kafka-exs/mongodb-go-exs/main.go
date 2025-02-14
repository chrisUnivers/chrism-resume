package main

import (
   "fmt"
   "encoding/json"
   "time"
   "os"
   "path/filepath"
)

type Message struct {
  Name string
  Size float64
  Time int64
}

func samplePath (startPath string)  error {
   err := filepath.Walk(startPath,
    func(path string, info os.FileInfo, err error) error {
 
       var bytes int64
       bytes = info.Size()


       var kilobytes int64
       kilobytes = (bytes / 1024)

       var megabytes float64
       megabytes = (float64)(kilobytes / 1024)   // cast to type float64

       var gigabytes float64
       gigabytes = (megabytes / 1024)

      now := time.Now().Unix()*1000




      m := Message{info.Name(), gigabytes, now}
      value, err := json.Marshal(m)

      
      if err != nil {
         panic(fmt.Sprintf("Failed to parse JSON: %s", err))
      }


      fmt.Printf("value: %v\n", string(value))
      return nil;
  })
  if err != nil {
     return err
  }
  return nil;
}

func main() {
   for {
       err := samplePath("./files");
       if err != nil {
            panic(fmt.Sprintf("Failed to run sample : %s", err))
       }
       time.Sleep(time.Minute)
   }

}