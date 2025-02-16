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
  2. The files in here assume that the git repository from `1.` is available. Might change later depending on final size. Those files are actually used in a docker image with the tutorial's container.


## [Setup-Link-1](#links)
### Steps
  * cd kafka-edu/docs-examples/mongodb-kafka-base/
  * docker-compose -p mongo-kafka up -d --force-recreate
  * docker exec mongo1 status
    + check for successful setup

## [Explore-Link-2](#links)
### Steps
  * See link for more info.

## [Replicate-Link-3](#links)
### Notes
  * The logic and implementions are in the docker image downloaded. For example monitoring kafka topics. This tutorial `replicate-with-cdc` is mostly on how to configure the `sink and source connectors`
  * Recall mongodb commands can be used in a javascript file by using `mongoose`. The `chrism-resume/mongooseExpress` repo an example on how to use mongoose.

## [Time-Serie-Ex-Link-4](#links)
### Notes
  * This tutorial show how to migrate an existing MongoDB collection to a time `series collection`. The tutorial in `../mongodb-go-exs` directory shows how to do so in a `go` project.
### Tips
  * mongodb://localhost:35001/?directConnection=true
    + connects to the MongoDB cluster running in the development environment.
mongodb-kafka-exs/mongodbDocker-exs/README.md

### Links
  1. https://www.mongodb.com/docs/kafka-connector/current/tutorials/tutorial-setup/#std-label-kafka-tutorials-docker-setup
  2. https://www.mongodb.com/docs/kafka-connector/current/tutorials/explore-change-streams/
  3. https://www.mongodb.com/docs/kafka-connector/current/tutorials/replicate-with-cdc/
  4. https://www.mongodb.com/docs/kafka-connector/current/tutorials/migrate-time-series/