package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* Kisilere ait veriler bu sinif yapisina getirilir
* </p>
*
*/



public class Kisi 
{
	
	
	
	private int yas;
	private String isim;
	private int kalanOmur;
	private String bulunduguUzayAraciAdi;
	
	public int getKalanOmur() 
	{
		return kalanOmur;
	}
	public void setKalanOmur(int ko) 
	{
		if(ko>=0) this.kalanOmur=ko;
	}
	public String getUzayAraciAdi() 
	{
		return this.bulunduguUzayAraciAdi;
	}
	public String getKisiAdi()
	{
		return this.isim;
	}
	Kisi(String a, String p, String r,String m)
	{
		this.isim=a;
		this.yas=Integer.parseInt(p);
		this.kalanOmur=Integer.parseInt(r);
		this.bulunduguUzayAraciAdi=m;
		
	}
	public int getYas() 
	{
		return this.yas;
	}
	public String getYasString() 
	{
		return Integer.toString(this.yas);
	}

	
	public static void kisiOmurAzalt(Kisi k) 
	{
	    k.setKalanOmur(k.getKalanOmur() - Simulasyon.mode);
	    if(k.getKalanOmur()/Simulasyon.mode==0) 
	    {
	    	k.setKalanOmur(0);
	    }
	}

}
