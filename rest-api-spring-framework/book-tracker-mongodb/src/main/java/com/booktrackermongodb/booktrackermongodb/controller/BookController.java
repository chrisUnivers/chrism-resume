package com.booktrackermongodb.booktrackermongodb.controller;


import com.booktrackermongodb.booktrackermongodb.model.Book;
import com.booktrackermongodb.booktrackermongodb.repository.BookRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
public class BookController {

    @Autowired
    private BookRepository bookRepository;
    
    @GetMapping({"/index", "/search"})
    public String showBooks(Model model, String keyword) {
        if (keyword != null) {
            model.addAttribute("books",
                this.bookRepository.findByTitleStartsWithOrAuthor(keyword, keyword));
            model.addAttribute("keyword", keyword);
        } else {
            List<Book> books = this.bookRepository.findAll();
            model.addAttribute("books", books);
        }
        return "index";
    }
    
    @GetMapping("/add-book")
    public String showAddBookForm(Book book) {
        return "add-book";
    }
    
    @PostMapping("/add-book")
    public String addBook(Book book, BindingResult result, Model model) {
        if (result.hasErrors()) {
            return "add-book";
        }
        this.bookRepository.save(book);
        return "redirect:/index";
    }
    
    @GetMapping("/edit-book/{id}")
    public String showUpdateForm(@PathVariable("id") String id, Model model) {
        Book book = this.bookRepository.findById(id).orElseThrow(() -> new IllegalArgumentException("Invalid book Id:" + id));
        model.addAttribute("book", book);

        return "edit-book";
    }

    @PostMapping("/edit-book/{id}")
    public String updateBook(@PathVariable("id") String id, Book book, BindingResult result, Model model) {
        if (result.hasErrors()) {
            book.setId(id);
            return "edit-book";
        }

        this.bookRepository.save(book);

        return "redirect:/index";
    }

    @GetMapping("/delete-book/{id}")
    public String deleteUser(@PathVariable("id") String id, Model model) {
        Book book = this.bookRepository.findById(id).orElseThrow(() -> new IllegalArgumentException("Invalid book Id:" + id));
        this.bookRepository.delete(book);

        return "redirect:/index";
    }
}


