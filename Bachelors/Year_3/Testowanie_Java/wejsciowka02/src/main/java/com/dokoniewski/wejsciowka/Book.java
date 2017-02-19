package com.dokoniewski.wejsciowka;

public class Book {
	String author;
	String title;
	int isbn;
	
	public Book(){
		
	}
	
	public Book(String author, String title, int isbn){
		this.author = author;
		this.title = title;
		this.isbn = isbn;
	}
	
	public int getisbn(){
		return this.isbn;
	}
	
	public void setisbn(int isbn){
		this.isbn = isbn;
	}
	
	public String getauthor(){
		return this.author;
	}
	
	public void setauthor(String author){
		this.author = author;
	}
	
	public String gettitle(){
		return this.title;
	}
	
	public void settitle(String title){
		this.title = title;
	}
}
