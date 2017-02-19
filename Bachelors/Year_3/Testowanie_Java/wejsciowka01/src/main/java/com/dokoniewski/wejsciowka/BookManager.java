package com.dokoniewski.wejsciowka;

import java.util.ArrayList;
import java.util.List;

public class BookManager {
	public List<Book> books = new ArrayList<Book>();
	
	public void addBook(Book book){
		books.add(book);
	}
	
	public void deleteBook(Book book){
		books.remove(book);
	}
}
