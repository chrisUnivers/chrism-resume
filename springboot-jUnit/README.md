## Info for this repository
  * This will repository will contain my projects springboot projects and projects that use jUnit for unit testing.
## Projects
  * **Intellij-BookStore**
    + The bookstore project is a spingboot project that processes input data of a book and writes them to an sql database.
    + It was set up using the spring init tool since intellij does not have an extension for this.
  * **Webflux-batch-bookstore**
    + This project is a springboot webflux project. I intend on using it to handle POST requests which submit a new book to a bookstore. This request updates the `submitted-books.csv` file in the `bookstore-intellij` project. Then launch the batch job created in the `Bookstore-Intellij` project which updates the database.
    + This project is effectively done. The only issue left is processing http POST requests as MONO objects in the method `bkBatchJob` in the file `StoryHandlr.java`. The project was intended to be an extention to the `bookstore-intellij` project which creates a spring batch job and implements a few end-to-end test using Junit. Currently workin on a new frontend project using aws and nextjs.
## BookStore Project design decisions:
  * The output goes to the file `/bookstore-intellij/newCollection.txt`. This is nice since I can easily inspect it instead of using the console.
  * Decided to go with the simple case, where I assume that the file `./bookstore/submitted-books.csv` is formatted and thus can use predefined indices. This is bad design because there's no reason to assume that. However, it's simple to implement and thus focus on implementing a batch processor.
    + Even though the file is a `.csv` file, I decided to leave it as it is. This is unnecessary, since its a `.csv` file, but it provides me with things to do unit tests on. Had it been a true `.csv` file, I would only need to `.split()` on commas.
    + Better implementation is to not assume the file has correct inputs. Then can process each line. This would also give me an excuse to use lambdas, which I like using. The file `StringIndex.java` was supposed to be the lambda to use.
  * Created class to process the file being read.
    + Since the goal is to minimize an processing on the input file, I assume that each line in the file has some form of format. This allows me to index inputs without much processing. However, using indices in multiple files can get out of control, will most of the time be meaning less, and I don't like it because I lose track of what each index does. Thus, having a class makes it easy since I only have to deal with the object of the file and it's methods.
    
