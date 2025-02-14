package main


import (
   "fmt"
   "encoding/json"
   "time"
   "os"
   "path/filepath"
   "github.com/confluentinc/confluent-kafka-go/kafka")

type Message struct {
  Name string
  Size float64
  Time int64
}

// Creating the Confluent cloud credentials and DNS information to use
const (
   bootstrapServers = "<SERVER-DNS>:<SERVER-PORT>"
   ccloudAPIKey     = "<ACCESS-KEY>"
   ccloudAPISecret  = "<SECRET-KEY>"
)

func samplePath (startPath string)  error {
  
   err := filepath.Walk(startPath,
    func(path string, info os.FileInfo, err error) error {
    if err != nil {
            return err
    }
    fmt.Println(path, info.Size())

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

               topic := "files"
               // Produce a new record to the topic...
                   producer, err := kafka.NewProducer(&kafka.ConfigMap{
                       "bootstrap.servers":       bootstrapServers,
                       "sasl.mechanisms":         "PLAIN",
                       "security.protocol":       "SASL_SSL",
                       "sasl.username":           ccloudAPIKey,
                       "sasl.password":           ccloudAPISecret})
  
                   if err != nil {
                       panic(fmt.Sprintf("Failed to create producer: %s", err))
                   }
  
                   producer.Produce(&kafka.Message{
                       TopicPartition: kafka.TopicPartition{Topic: &topic,
                           Partition: kafka.PartitionAny},
                       Value: []byte(value)}, nil)
  
                   // Wait for delivery report
                   e := <-producer.Events()
  
                   message := e.(*kafka.Message)
                   if message.TopicPartition.Error != nil {
                       fmt.Printf("failed to deliver message: %v\n",
                           message.TopicPartition)
                   } else {
                       fmt.Printf("delivered to topic %s [%d] at offset %v\n",
                           *message.TopicPartition.Topic,
                           message.TopicPartition.Partition,
                           message.TopicPartition.Offset)
                   }
  
                   producer.Close()

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