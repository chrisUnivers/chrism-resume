## Purpose
  * This folder follows the tutorial from the link below
    + https://www.mongodb.com/developer/products/connectors/leverage-mongodb-data-kafka-tutorials/
  * The tutorial is a step-up from the `go` tutorial as it uses `docker` and a `source connector`.
  * See also [moreInfo](#usefull-info)

## Important
  * Remember to not add the initial git repository from the setup tutorial. Keeps things simple.
    + git clone https://github.com/mongodb-university/kafka-edu.git

## Usefull info
  1. For simplicity, I will not include the git repository needed to run the example, link below.
    `*` https://www.mongodb.com/docs/kafka-connector/current/tutorials/tutorial-setup/#std-label-kafka-tutorials-docker-setup
  2. The files in here assume that the git repository from `1.` is available. Might change later depending on final size.


## [Setup-1](#usefull-info)
### Steps
  * cd kafka-edu/docs-examples/mongodb-kafka-base/
  * docker-compose -p mongo-kafka up -d --force-recreate
  * docker exec mongo1 status
    + check for successful setup
### Tips
  * mongodb://localhost:35001/?directConnection=true
    + connects to the MongoDB cluster running in the development environment.
mongodb-kafka-exs/mongodbDocker-exs/README.md