package com.example.bookstore;

import org.springframework.batch.item.ItemProcessor;

public class BookStoreItemProcessor implements ItemProcessor<BookStore, BookStore>{
    
    @Override
    public BookStore process(final BookStore bookStore) {
        
        final BookStore updatedBookStore = new BookStore(bookStore.bookStoreName(), bookStore.address(), bookStore.bookStoreId(), bookStore.bookCollection()); // Need to update the book store collection first by reading the submitted-books-csv file.
        return updatedBookStore;
    }
}
