## Purpose
  * This folde follows the tutorial from the link below
    + https://www.mongodb.com/developer/products/connectors/go-kafka-confluent-atlas/
## Comments
  * The `main.go` file uses the `walk` function from go to go through a directory's path and get information about the directory. This information is then pushed to a Confluent Kafka topic which then sinks to a mongodb cluster. The data/info is first modified to also include the time the file was processed. This new data is what's pushed to the Kafka topic which then sinks/writes the data to mongodb-cluster. This is similar to what was done in `chrism-resume/backend_spbootDev` but `confluent` is used instead of `apache kafka` and `mongodb` is used instead of writing to a file. 
## Getting Started:
  * To set up a `go` project
    + go mod init example/main
  * To add Confluent's Kafka dependency
    + go get -u gopkg.in/confluentinc/confluent-kafka-go.v1/kafka
  * To run
    + go run main.go