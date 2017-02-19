package com.example.tables;

public class Postac {
	
	private long id;	
	private String gracz;
	private String nazwa;
	private long bronId;
	
	public Postac() {
	}
	
	public Postac(String gracz, String nazwa){
		this.gracz = gracz;
		this.nazwa = nazwa;
	}
	
	public Postac(String gracz, String nazwa, long bronId) {
		this.gracz = gracz;
		this.nazwa = nazwa;
		this.bronId = bronId;
	}
	
	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}
	
	public String getGracz() {
		return gracz;
	}
	public void setGracz(String gracz) {
		this.gracz = gracz;
	}
	
	public String getNazwa() {
		return nazwa;
	}
	public void setNazwa(String nazwa) {
		this.nazwa = nazwa;
	}
	
	public long getBronId() {
		return bronId;
	}
	public void setBronId(long bronId) {
		this.bronId = bronId;
	}
}
