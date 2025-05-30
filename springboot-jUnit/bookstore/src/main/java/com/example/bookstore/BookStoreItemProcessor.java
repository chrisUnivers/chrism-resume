package com.example.bookstore;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

import org.springframework.batch.item.ItemProcessor;

public class BookStoreItemProcessor implements ItemProcessor<BookStore, BookStore>{
    
    @Override
    public BookStore process(final BookStore bookStore) {
        List<TheBook> approvedBooks;
        
        
        final BookStore updatedBookStore = new BookStore(bookStore.bookStoreName(), bookStore.address(), bookStore.bookStoreId(), bookStore.bookCollection()); // Need to update the book store collection first by reading the submitted-books-csv file.
        
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
    List<TheBook> findApprovedBooks(String file_to_use) {

        try {
            BufferedReader reader = new BufferedReader(new FileReader(file_to_use));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
