package com.example.dokoniewski.domain;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement
public class Monitor {
	
	private long id;
	
	private String brand;
	private int pixels;
	
	public Monitor() {
	}

	public Monitor(String brand, int pixels) {
		this.brand = brand;
		this.pixels = pixels;
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public String getBrand() {
		return brand;
	}
	public void setBrand(String brand) {
		this.brand = brand;
	}
	public int getPixels() {
		return pixels;
	}
	public void setPixels(int pixels) {
		this.pixels = pixels;
	}
}
