package com.example.dokoniewski;

import static org.junit.Assert.*;

import java.util.List;

import org.junit.Before;
import org.junit.Test;

import com.example.dokoniewski.domain.Monitor;
import com.example.dokoniewski.service.MonitorManager;

public class MonitorManagerTest {
	
	MonitorManager monitorManager = new MonitorManager();
	
	private final static String BRAND_1 = "BenQ";
	private final static String BRAND_2 = "Hyundai";
	private final static int HD = 720;
	private final static int FULL_HD = 1080;
	
	private Monitor monitor = new Monitor(BRAND_1, HD);
	private Monitor monitor2 = new Monitor(BRAND_2, FULL_HD);
	private Monitor person3 = new Monitor(BRAND_2, HD);
	
	@Before
	public void InitializeDatabase(){
		monitorManager.clearMonitors();
		monitorManager.addMonitor(monitor);
		monitorManager.addMonitor(monitor2);
		monitorManager.addMonitor(person3);
	}
	
	@Test
	public void checkConnection(){
		assertNotNull(monitorManager.getConnection());
	}
	
	@Test
	public void checkAdding(){
		List<Monitor> monitors = monitorManager.getAllMonitors();
		Monitor monitorRetrieved = monitors.get(0);
		
		assertEquals(BRAND_1, monitorRetrieved.getBrand());
		assertEquals(HD, monitorRetrieved.getPixels());
	}
	
	@Test
	public void checkDeleting(){
		List<Monitor> before = monitorManager.getAllMonitors();
		
		Monitor deleting = before.get(0);
		
		assertEquals(1,monitorManager.deleteMonitor(deleting));
		List<Monitor> after = monitorManager.getAllMonitors();
		
		Monitor retrieved = after.get(0);
		
		assertEquals(before.size(), after.size()+1);
		assertEquals(BRAND_2, retrieved.getBrand());
		assertEquals(FULL_HD, retrieved.getPixels());
	}
	
	@Test
	public void checkUpdating(){
		List<Monitor> monitors = monitorManager.getAllMonitors();
		Monitor retrieved = monitors.get(0);
		
		assertEquals(1,monitorManager.updateMonitor(retrieved, BRAND_2, FULL_HD));
		assertEquals(BRAND_1, retrieved.getBrand());
		assertEquals(HD, retrieved.getPixels());
	}
	
	@Test
	public void checkGetById(){
		List<Monitor> monitors = monitorManager.getAllMonitors();
		long id = monitors.get(1).getId();
		List<Monitor> retrieved = monitorManager.getMonitor(id);
		
		assertEquals(BRAND_2, retrieved.get(0).getBrand());
		assertEquals(FULL_HD, retrieved.get(0).getPixels());
	}
	
	@Test
	public void checkGetByPixels(){		
		List<Monitor> monitors = monitorManager.getAllMonitors();
		int pixels = monitors.get(2).getPixels();
		List<Monitor> retrieved = monitorManager.getMonitorByPixels(pixels);
		
		assertEquals(2, retrieved.size());
		assertEquals(BRAND_1, retrieved.get(0).getBrand());
		assertEquals(HD, retrieved.get(0).getPixels());
		assertEquals(BRAND_2, retrieved.get(1).getBrand());
		assertEquals(HD, retrieved.get(1).getPixels());
	}
}
