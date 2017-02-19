package com.example.jdbcdemo.service;

import static org.junit.Assert.*;

import java.util.List;

import org.junit.Before;
import org.junit.Test;

import com.example.jdbcdemo.domain.Person;

public class PersonManagerTest {
	
	PersonManager personManager = new PersonManager();
	
	private final static String NAME_1 = "Zenek";
	private final static String NAME_2 = "Marian";
	private final static int YOB_1 = 1945;
	private final static int YOB_2 = 1993;
	
	private Person person = new Person(NAME_1, YOB_1);
	private Person person2 = new Person(NAME_2, YOB_2);
	private Person person3 = new Person(NAME_2, YOB_1);
	
	@Before
	public void InitializeDatabase(){
		personManager.clearPersons();
		personManager.addPerson(person);
		personManager.addPerson(person2);
		personManager.addPerson(person3);
	}
	
	@Test
	public void checkConnection(){
		assertNotNull(personManager.getConnection());
	}
	
	@Test
	public void checkAdding(){
		List<Person> persons = personManager.getAllPersons();
		Person personRetrieved = persons.get(0);
		
		assertEquals(NAME_1, personRetrieved.getName());
		assertEquals(YOB_1, personRetrieved.getYob());
	}
	
	@Test
	public void checkDeleting(){
		List<Person> before = personManager.getAllPersons();
		
		Person deleting = before.get(0);
		
		assertEquals(1,personManager.deletePerson(deleting));
		List<Person> after = personManager.getAllPersons();
		
		Person retrieved = after.get(0);
		
		assertEquals(before.size(), after.size()+1);
		assertEquals(NAME_2, retrieved.getName());
		assertEquals(YOB_2, retrieved.getYob());
	}
	
	@Test
	public void checkUpdating(){
		List<Person> persons = personManager.getAllPersons();
		Person retrieved = persons.get(0);
		
		assertEquals(1,personManager.updatePerson(retrieved, NAME_2, YOB_2));
		assertEquals(NAME_1, retrieved.getName());
		assertEquals(YOB_1, retrieved.getYob());
	}
	
	@Test
	public void checkGetById(){
		List<Person> persons = personManager.getAllPersons();
		long id = persons.get(1).getId();
		List<Person> retrieved = personManager.getPersonById(id);
		
		assertEquals(NAME_2, retrieved.get(0).getName());
		assertEquals(YOB_2, retrieved.get(0).getYob());
	}
	
	@Test
	public void checkGetByName(){		
		List<Person> persons = personManager.getAllPersons();
		String name = persons.get(2).getName();
		List<Person> retrieved = personManager.getPersonByName(name);
		
		assertEquals(2, retrieved.size());
		assertEquals(NAME_2, retrieved.get(0).getName());
		assertEquals(YOB_2, retrieved.get(0).getYob());
		assertEquals(NAME_2, retrieved.get(1).getName());
		assertEquals(YOB_1, retrieved.get(1).getYob());
	}
}
