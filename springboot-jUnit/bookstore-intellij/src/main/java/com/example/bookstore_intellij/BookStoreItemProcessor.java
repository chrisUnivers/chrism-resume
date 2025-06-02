package com.example.bookstore_intellij;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.springframework.batch.item.ItemProcessor;

public class BookStoreItemProcessor implements ItemProcessor<BookStore, BookStore>{

    @Override
    public BookStore process(final BookStore bookStore) {
        List<TheBook> approvedBooks = findSubmittedBooks("submitted-books.csv", bookStore.bksId());
        String nwCollection = "";

        for (TheBook book : approvedBooks) {
            String strScore = String.valueOf(book.score());

            nwCollection += "(" + book.title() + ", " + book.authFirstName() + ", " + book.authLasName() + ", " + book.releaseDate() + ", " + strScore +"), ";
        }

        String writeStr = bookStore.bksCollection() + nwCollection;
        final String updatedCollection = bookStore.bksCollection() + nwCollection;


        // try {
        //     BufferedWriter writer = new BufferedWriter(new FileWriter("newCollection.txt", true));
        //     writer.write(writeStr);
        //     writer.close();
        // } catch (IOException e) {
        //     e.printStackTrace();
        // }

        String sameName    = bookStore.bksName();
        String sameAddress = bookStore.bksAddress();
        String sameId      = bookStore.bksId();
        final BookStore updatedBookStore = new BookStore(sameName, sameAddress, sameId, updatedCollection);

        return updatedBookStore;
    }

    public String processSubmittedBook(String submit, StringIndex strIndex) {

        String acceptedBook = "Book accepted";

        do {
            String[] revSubmitted = submit.split(" ");

        } while (acceptedBook == "hello");

        return acceptedBook;
    }

    /**
     *
     * @param file_to_use Can assume that each book store has a different file to read from. For now one file is used.
     * @return A list of TheBook objects that have been "reviewed" and approved. Can use Junit to test for this and look for edge cases to test for.
     */
    List<TheBook> findSubmittedBooks(String file_to_use, String uniqueId) {

        List<TheBook> rnBookList = new ArrayList<TheBook>();
        try {
            BufferedReader reader = new BufferedReader(new FileReader(file_to_use));
            String line = reader.readLine();

            while (line != null) {
                BookInfoUtils rawBookInfo = new BookInfoUtils(line);
                String[] bookStoreIds = rawBookInfo.returnBookStoreIds();

                for (String bookStoreId: bookStoreIds) {
                    if ((bookStoreId.equals(uniqueId))) { // each book migh have submitted to multiple book stores. This pre-processing can be fixed with improved input, however, plan on using it for unit tests.
                        TheBook nBook = new TheBook(rawBookInfo.getTitle(), rawBookInfo.getFirstName(), rawBookInfo.getLastName(), rawBookInfo.getReleaseDate(), "", rawBookInfo.getBookReviewScore(), "");
                        rnBookList.add(nBook);
                    }
                }
                line = reader.readLine();
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return rnBookList;
    }
}
