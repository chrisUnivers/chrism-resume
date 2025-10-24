### README FILE for rest-api
  * To run use:
    + make run
  * To run the tests use:
    + make test

### Endpoints used(use something like postman):
  * Post request for creating a user
    + Postman json:
    {
      "email": "chris@mail.com"
      "firstName": "Chris"
      "lastName": "Findlay"
      "password": "okKeys331"
    }
  * Post request for creating a task:
    +  http://localhost:3000/api/v1/tasks