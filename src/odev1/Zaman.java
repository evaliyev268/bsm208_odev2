package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* LocalDate kutuphanesiyle tarih verilerinin dogru bir sekilde islenmesi saglanir
* </p>
*
*/

import java.time.LocalDate;

public class Zaman 
{
	
	private int birGununKacSaatOldugu;
	private LocalDate tarihSuAn;
	Zaman(int s,LocalDate t)
	{
		this.birGununKacSaatOldugu=s;
		this.tarihSuAn=t;
	
	}
	public LocalDate getTarih() 
	{
		return this.tarihSuAn;
	}
	
	public void setTarih(LocalDate d) 
	{
		this.tarihSuAn=d;
	}
	public int  getBirGununKacSaatOldugu() 
	{
	return this.birGununKacSaatOldugu;	
	}

}
