package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* Gezegenlere ait veriler bu sinif yapisina getirilir
* </p>
*
*/
import java.time.LocalDate;
public class Gezegen {
	private String gezegenAdi;
	private Zaman zamanCizelgesi;
	private long nufus;
	
	
	
	public void setNufus(long n) 
	{
		this.nufus=n;
	}
	public long getNufus() 
	{
		return this.nufus;
	}
	
	public String getGezegenAdi() 
	{
		return this.gezegenAdi;
	}


	Gezegen(String ga,String bks,LocalDate bgt)
	{
		this.gezegenAdi=ga;
		this.zamanCizelgesi=new Zaman(Integer.parseInt(bks),bgt);
		
	}
	
	public Zaman getZamanCizelgesi() 
	{
		return this.zamanCizelgesi;
	}
}


