package com.example.managers;

import static org.junit.Assert.*;
import java.util.List;
import org.junit.Test;
import com.example.tables.Postac;
import com.example.tables.Bron;

public class PostacManagerTest {
	BronManager bronManager = new BronManager();
	PostacManager postacManager = new PostacManager();
	private final static String GRACZ_1 = "Robert";
	private final static String NAZWA_1 = "Geralt z Rivii";
	private final static long BRON_1 = 0;
	private final static String BRON_2 = "Maczuga";
	private final static String BRON_3 = "Obuchowe";
	
	Bron bron = new Bron(BRON_2, BRON_3);
		@Test
	public void checkConnection(){
		assertNotNull(postacManager.getConnection());
	}

	@Test
	public void checkAdding(){
		
		Postac postac = new Postac(GRACZ_1, NAZWA_1, BRON_1);
		
		postacManager.clearPostac();
		assertEquals(1,postacManager.addPostac(postac));
	
		List<Postac> postacie = postacManager.getAllPostac();
		Postac postacieRetrieved = postacie.get(0);
		assertEquals(GRACZ_1, postacieRetrieved.getGracz());
		assertEquals(NAZWA_1, postacieRetrieved.getNazwa());
		assertEquals(BRON_1, postacieRetrieved.getBronId());	
	}
	
	@Test
	public void checkDeleting(){
		Postac postac = new Postac("Gracz1", "Postac1", 0);
		
		postacManager.addPostac(postac);
		List<Postac> postacie = postacManager.getAllPostac();
		int p = postacie.size();
		
		postacManager.deletePostac(postacie.get(0).getId());
		postacie = postacManager.getAllPostac();
		assertEquals(p-1,postacie.size());
	}

	@Test
	public void checkSelect(){
		List<Postac> postac = postacManager.selectPostac(BRON_1);
		int i = postac.size() - 1;
		while (i >= 0){
			Postac postacRetrieved = postac.get(i);
			assertEquals(BRON_1, postacRetrieved.getBronId());
			i--;
		}				
	}
	
	@Test
	public void checkAddFK(){	
		Postac postac2 = new Postac("Gracz2", "Postac2");
		
		postacManager.clearPostac();
		bronManager.addBron(bron);
		postacManager.addPostac(postac2);
		
		List<Postac> postacie = postacManager.getAllPostac();
		List<Bron> bronie = bronManager.getAllBron();
		
		postacManager.addID(postacie.get(0).getId(), bronie.get(0).getId());
		postacie = postacManager.getAllPostac();
		assertEquals(postacie.get(0).getBronId(), bronie.get(0).getId());	
	}
	
	@Test
	public void checkRemoveFK(){
		Postac postac2 = new Postac("Gracz2", "Postac2");
		
		postacManager.clearPostac();
		postacManager.addPostac(postac2);
		
		List<Postac> postacie = postacManager.getAllPostac();
		
		postacManager.removeID(postacie.get(0).getId());
		postacie = postacManager.getAllPostac();
		assertEquals(0, postacie.get(0).getBronId());
	}
}
