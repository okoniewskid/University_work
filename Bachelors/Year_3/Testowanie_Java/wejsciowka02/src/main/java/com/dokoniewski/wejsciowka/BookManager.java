package com.dokoniewski.wejsciowka;

import java.util.ArrayList;
import java.util.List;

public class BookManager {
	
	//public List<Book> books = new ArrayList<Book>();
	public IMyList myList;
	
	public BookManager(IMyList myList){
		this.myList = myList;
	}
	
	public boolean addBook(Book book){
		return myList.addBook(book);
	}
	
	public boolean deleteBook(Book book){
		return myList.deleteBook(book);
	}
	
	public List<Book> getAllBooks(){
		return myList.getAll();
	}
	
	public Book getByTitle(String title){
		return myList.getByTitle(title);
	}
	
	public Book getByISBN(int isbn){
		return myList.getByISBN(isbn);
	}
}
