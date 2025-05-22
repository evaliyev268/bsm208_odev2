package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* Uzay Araclarina ait veriler bu sinif yapisina getirilir
* </p>
*
*/
import java.time.LocalDate;


public class UzayAraci 
{
	
	private String uzayAraciAdi;
	private int kalanMesafe;
	private String varisGezegeniAdi;
	private String cikisGezegeniAdi;
	private long nufus;
	private String durum;
	private LocalDate cikisTarihi;
	private LocalDate varisTarihi;
	

	public LocalDate getCikisTarihi() 
	{
		return this.cikisTarihi;
	}
	public String getKalanMesafeString()
	{
		if(this.durum=="IMHA") 
		{
		return "===";
		}
		else 
		{
			return Integer.toString(this.kalanMesafe);
		}
	}
	public int getKalanMesafe() 
	{
		return this.kalanMesafe;
	}
	public void setKalanMesafe(int i) 
	{
		if(i>=0) {
		this.kalanMesafe=i;
		}
	}
	public long getNufus() 
	{
		return this.nufus;
	}
	public void  setNufus(long n) 
	{
		 this.nufus=n;
	}
	
	public String getUzayAraciAdi() 
	{
		return this.uzayAraciAdi;
	}
	
	
	
	
	public String getVarisGezegeniAdi()
	{
		return this.varisGezegeniAdi;
	}
	
	public String getCikisGezegeniAdi()
	{
		return this.cikisGezegeniAdi;
	}
	
	public String getDurum() 
	{
		return this.durum;
	}
	
	public void setVarisTarihi(LocalDate t) 
	{
		this.varisTarihi=t;
	}
	

	
	public void setDurum(String s) 
	{
		this.durum=s;
	}
	
	UzayAraci(String u,String cGe,String vGe, LocalDate ct,String k)
	{
		this.uzayAraciAdi=u;
		this.cikisGezegeniAdi=cGe;
		this.varisGezegeniAdi=vGe;
		this.cikisTarihi=ct;
		this.kalanMesafe=Integer.parseInt(k);	
		this.nufus=0;
		this.durum="Bekliyor";
		this.varisTarihi=null;
	}	
	public LocalDate getVarisTarihi() 
	{
		return this.varisTarihi;
	}
	public String getVarisTarihiString() 
	{
		if(this.durum=="IMHA") 
		{
			return "====";
		}
		else if(this.varisTarihi==null) 
		{
			return "Null";
		}
		else 
		{
			return this.varisTarihi.toString();
		}
	}
	
	public static void mesafeAzalt(UzayAraci u) 
	{
	    u.setKalanMesafe(u.getKalanMesafe() - Simulasyon.mode);
	    if(u.getKalanMesafe()/Simulasyon.mode==0) 
	    {
	    	u.setKalanMesafe(0);
	    }
	}
	
	
	}
