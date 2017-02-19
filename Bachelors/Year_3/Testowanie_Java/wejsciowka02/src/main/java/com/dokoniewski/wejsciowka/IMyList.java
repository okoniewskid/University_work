package com.dokoniewski.wejsciowka;

import java.util.List;

public interface IMyList {
	
	public List<Book> getAll();
	public Book getByTitle(String title);
	public Book getByISBN(int isbn);
	boolean deleteBook(Book book);
	boolean addBook(Book book);
	
}
