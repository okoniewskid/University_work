package com.example.dokoniewski.rest;

import java.util.List;

import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

import com.example.dokoniewski.domain.Monitor;
import com.example.dokoniewski.service.MonitorManager;

@Path("monitor")
public class MonitorRESTService {	
	
	private MonitorManager pm = new MonitorManager();
	
	@GET
	@Path("/")
	@Produces(MediaType.APPLICATION_JSON)
	public List<Monitor> getAllMonitor(){
		List<Monitor> monitor = pm.getAllMonitors();
		return monitor;
	}
	
	@GET
	@Path("/pixels/{pixels}")
	@Produces(MediaType.APPLICATION_JSON)
	public List<Monitor> getMonitorByPixels(@PathParam("pixels") int pixels){
		List<Monitor> monitor = pm.getMonitorByPixels(pixels);
		return monitor;
	}
	
	@GET
	@Path("/{monitorId}")
	@Produces(MediaType.APPLICATION_JSON)
	public Monitor getMonitor(@PathParam("monitorId") Long id){
		List<Monitor> monitor = pm.getMonitor(id);
		Monitor m = monitor.get(0);
		return m;
	}
	
	@POST
	@Path("/")
	@Consumes(MediaType.APPLICATION_JSON)
	public Response addMonitor(Monitor monitor){
		pm.addMonitor(monitor);
		return Response.status(201).entity("Monitor").build(); 
	}
	
	@POST
	@Path("/{monitorId}") 
	public Response updateMonitor(@PathParam("monitorId") Long id){
		List<Monitor> m = pm.getMonitor(id);
		Monitor monitor = m.get(0);
		pm.updateMonitor(monitor, "Edytowany", 720);
		return Response.status(200).build();
	}
	
	
	@GET
	@Path("/test")
	@Produces(MediaType.TEXT_HTML)
	public String test(){
		return "REST API /monitor is running";
	}
	
	@DELETE
	@Path("/")
	public Response clearMonitors(){
		pm.clearMonitors();
		return Response.status(200).build();
	}
	
	@DELETE
	@Path("/{monitorId}")
	public Response deleteMonitor(@PathParam("monitorId") Long id){
		List<Monitor> m = pm.getMonitor(id);
		Monitor monitor = m.get(0);
		pm.deleteMonitor(monitor);
		return Response.status(200).build();
	}

}
