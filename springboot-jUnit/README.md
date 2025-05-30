## Info for this repository
  * This will repository will contain my projects springboot projects and projects that use jUnit for unit testing.

## Projects
  * **BookStore**
    + The bookstore project is a spingboot project that processes input data of a book and writes them to an sql database.

## BookStore Project design decesions:
  * Decided to go with the simple case, where I assume that the file `./bookstore/../src/resources/submitted-books.csv` is formatted and thus can use predefined indices. This is bad design because there's no reason to assume that. However it's simple to implement and thus focus on implementing a batch processor.
    + Better implementation is to not assume the file has correct inputs. Then can process each line. This would also give me an excuse to use lambdas, which I like using. The file `StringIndex.java` was supposed to be the lambda to use.
  * Create class to process the file being read.
    + Since the goal is to minimize an processing on the input file, I assume that each line in the file has some form of format. This allows me to index inputs without much processing. However, using indices in multiple files can get out of control, will most of the time be meaning less, and I don't like it. Thus, having a class makes it easy since I only have to deal with the object of the file and it's methods
    
