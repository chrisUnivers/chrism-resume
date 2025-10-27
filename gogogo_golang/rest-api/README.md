### README FILE for rest-api
  * To run use:
    + make run
  * To run the tests use:
    + make test
  * Make sure you have a local MySql running for this application to run.

### Endpoints used(use something like postman):
* End point for creating a user:
    + http://localhost:3000/api/v1/users/register
  * JSON postman for creating a user
    + Postman json:
    {
      "email": "chris@mail.com"
      "firstName": "Chris"
      "lastName": "Findlay"
      "password": "okKeys331"
    }
  * End point for creating a task: 
    + +  http://localhost:3000/api/v1/tasks
  * Post request for creating a task:
    + {
      "name": "day to day tasks"
      "projectID":    "1",
			"assignedToID": "16",
    }

* Building Dockerfile:
  * docker build -t golang-rest-api .
* Running Dockerfile:
  * docker run