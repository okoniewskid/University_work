package com.dokoniewski.wejsciowka;

import static org.junit.Assert.*;

import org.jbehave.core.annotations.Given;
import org.jbehave.core.annotations.Then;
import org.jbehave.core.annotations.When;

public class BookSteps {
	
	private BookManager bookmanager;
	private Book book1 = new Book("Author","Title", 1234);
	private Book testbook = new Book();
	
	@Given("a bookmanager")
	public void bookSetup(){
		bookmanager = new BookManager();
	}

	@When("received title $title")
	public void setArguments(String title){
		testbook.title = title;
	}
		
	@Then("addBook should add $result")
	public void shouldAdd(String result){
		bookmanager.addBook(testbook);
		assertEquals(result, bookmanager.books.get(0).gettitle());
	}
	
	@Then("deleteBook should delete $result")
	public void shouldDelete(String result){
		bookmanager.addBook(book1);
		bookmanager.addBook(testbook);
		int size = bookmanager.getSize();
		
		bookmanager.deleteBook(testbook);
		int size2 = bookmanager.getSize();
		
		assertEquals(book1.title, bookmanager.books.get(0).gettitle());
		assertEquals(size, size2+1);
	}
}
