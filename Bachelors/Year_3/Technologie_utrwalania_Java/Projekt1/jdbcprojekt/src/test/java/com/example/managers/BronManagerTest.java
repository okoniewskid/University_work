package com.example.managers;

import static org.junit.Assert.*;
import java.util.List;
import org.junit.Test;
import com.example.tables.Bron;

public class BronManagerTest {
	
	BronManager bronManager = new BronManager();
	private final static String NAZWA_1 = "Miecz";
	private final static String OBRAZENIA_1 = "Sieczne";
	
	@Test
	public void checkConnection(){
		assertNotNull(bronManager.getConnection());
	}

	@Test
	public void checkAdding(){
		
		Bron bron = new Bron(NAZWA_1, OBRAZENIA_1);
		
		bronManager.clearBron();
		assertEquals(1,bronManager.addBron(bron));
	
		List<Bron> bronie = bronManager.getAllBron();
		Bron bronieRetrieved = bronie.get(0);
		assertEquals(NAZWA_1, bronieRetrieved.getNazwa());
		assertEquals(OBRAZENIA_1, bronieRetrieved.getObrazenia());	
	}
	
	
	
	
}
