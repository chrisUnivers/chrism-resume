package com.booktrackermongodb.booktrackermongodb.repository;

import com.booktrackermongodb.booktrackermongodb.model.Book;
import org.springframework.data.mongodb.repository.MongoRepository;

import java.util.List;

public interface BookRepository extends MongoRepository<Book, String> {
    List<Book> findByTitleStartsWithOrAuthor(String title, String author);
}


