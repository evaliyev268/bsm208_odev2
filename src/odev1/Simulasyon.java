package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* Iterasyon, Surekli ekranin temizlenmesi, mesafe ve nufus gibi hesaplamalar yapilir
* </p>
*
*/

import java.util.ListIterator;

import java.util.*;

public class Simulasyon 
{
	public static int mode=30;//<--------------MODE  Bir refresh in kac saat olarak hesaplanacagi
	

	private static int gecenZaman=0;
	private static boolean Dur=false;

	
	public static void programStart() throws InterruptedException 
	{	
		DosyaOkuma d=new DosyaOkuma();
			while(!Dur) 
			{
				programRestart();
				System.out.println("Dikkat: bir refresh, " +mode+" saat anlamina gelmektedir (Simulasyon sinifinda en ustden degistire bilirsiniz.)");
				System.out.println("Cikis gezegeni ve Varis gezegeninin her ikisi hakkinda bilgi bulunmayan Uzay Araclari sisteme dahil edilmez!");
				System.out.println("Cikis ve ya Varis tarihi acisindan tutarsizlik olusturan Uzay Araclari sisteme dahil edilmez!");
				Thread.sleep(100);
				Console.clearConsole();
				Azalt();
				control();
				gecenZaman++;
				gunuBirArtir();
			
				
			} 
			
			programRestart();
			System.out.println("Dikkat: bir refresh, " +mode+" saat anlamina gelmektedir (Simulasyon sinifinda en ustden degistire bilirsiniz.)");
			System.out.println("Cikis gezegeni ve Varis gezegeninin her ikisi hakkinda bilgi bulunmayan Uzay Araclari sisteme dahil edilmez!");
			System.out.println("Cikis ve ya Varis tarihi acisindan tutarsizlik olusturan Uzay Araclari sisteme dahil edilmez!");
	}
	
	
	
	
	


	

	

	private static void Azalt() 
	{
		//kisiOmrunu ve Mesafeyi azaltan fonksiyon
	    ListIterator<UzayAraci> uItr18 = DosyaOkuma.getUzayAraciList().listIterator();	   
	    while (uItr18.hasNext()) 
	    {
	        UzayAraci u = uItr18.next();
	            ListIterator<Kisi> kItr10 = DosyaOkuma.getKisiList().listIterator();
	            while (kItr10.hasNext()) 
	            {
	                Kisi k = kItr10.next();
	                if (k.getUzayAraciAdi().equals(u.getUzayAraciAdi())) 
	                {
	                    Kisi.kisiOmurAzalt(k);
	                }
	            }
	            if(u.getDurum().equals("Yolda")) 
	            { //Yola ciktigi an mesafe azalmaya baslar
	            UzayAraci.mesafeAzalt(u); 
	      }
	    }
	    }
	    
	private static void control() 
		{//Programin durdurulma kontrolu 
			int counter=DosyaOkuma.getUzayAraciList().size();
	  ListIterator<UzayAraci> uItrF =DosyaOkuma.getUzayAraciList().listIterator();
	        while(uItrF.hasNext()) {
	        	UzayAraci u=uItrF.next();
	        if (u.getDurum().equals("Vardi") || u.getDurum().equals("IMHA")) {
	        	counter--;
	        }
		    } 
	        if (counter == 0) {
		        Dur = true;
		    }
	        }
	private static  void programRestart() 
	{//Ekrana nufuslarida hesaplayarak yazan fonksiyon  
		AracNufus();
		GezegenNufus();
		Durum();
		
		ListIterator<Gezegen> gItr1=DosyaOkuma.getGezegenList().listIterator();
		ListIterator<Gezegen> gItr2=DosyaOkuma.getGezegenList().listIterator();
		ListIterator<Gezegen> gItr4=DosyaOkuma.getGezegenList().listIterator();
		System.out.printf("%s \t","Gezegenler:");
		
		while(gItr1.hasNext()) {
			Gezegen gezegen=gItr1.next();
			System.out.printf("%s %s %s %s \t","----","----",gezegen.getGezegenAdi(),"----");	
		}
		System.out.println("\n");
		System.out.printf("%s %s \t","Tarih:","-----");
		
		while(gItr2.hasNext()){
			Gezegen gezegen1=gItr2.next();
		System.out.printf("%s  %s %s  \t" ,"----",gezegen1.getZamanCizelgesi().getTarih(),"----");
			
		}
		System.out.println("\n");
		System.out.printf("%s %s \t","Nufus:","-----");
		while(gItr4.hasNext()) {
			Gezegen g=gItr4.next();
			System.out.printf("%s %s %d %s \t","----","-----",g.getNufus(),"----");
		}
		System.out.println("\n");
		System.out.printf("%s \n","Uzay Araclari: ");
		
		System.out.printf("%s %s %s %s %s %s %s %s %s %s %s","Arac adi","----","Durum","----","Cikis","----","Varis","----","Hedefe kalan saat", "----","Hedefe varacagi tarih");
		System.out.println("\n");
		
		
		ListIterator<UzayAraci> uItr3=DosyaOkuma.getUzayAraciList().listIterator();
		while(uItr3.hasNext()) {
			UzayAraci arac=uItr3.next();
			System.out.printf("%s %s %s %s %s %s %s %s %s %s %s \n" ,arac.getUzayAraciAdi(),"----------",arac.getDurum(),"-----",arac.getCikisGezegeniAdi(),"------",arac.getVarisGezegeniAdi(),"-------------",arac.getKalanMesafeString(),"----------------",arac.getVarisTarihiString());
		}
	
	}
	private static void AracNufus()
	{
		List<Kisi> kList = DosyaOkuma.getKisiList();
	    List<UzayAraci> uList = DosyaOkuma.getUzayAraciList();
	    
	    uList.parallelStream().forEach(u -> {
	        long toplamNufus = kList.parallelStream()
	            .filter(k -> k.getUzayAraciAdi().equals(u.getUzayAraciAdi()) && k.getKalanOmur()!=0 ) 
	            .count();
	        u.setNufus(toplamNufus);
	
	    });
	
	}
	
    private static void GezegenNufus() 
    {
	    List<Gezegen> gezegenList = DosyaOkuma.getGezegenList();
	    List<UzayAraci> uzayAraciList = DosyaOkuma.getUzayAraciList();
	    
	    gezegenList.parallelStream().forEach(g -> {
	        long toplamNufus = uzayAraciList.parallelStream()
	            .filter(uz -> !uz.getDurum().equals("Yolda"))  
	            .filter(uz -> (uz.getCikisGezegeniAdi().equals(g.getGezegenAdi())&& uz.getDurum().equals("Bekliyor")) ||
	                          (uz.getVarisGezegeniAdi().equals(g.getGezegenAdi()))&& uz.getDurum().equals("Vardi"))
	            .mapToLong(UzayAraci::getNufus)
	            .sum();

	        g.setNufus(toplamNufus);
	    
	
	    });
	}
	
	private static void Durum() 
	{
		ListIterator<UzayAraci> uItr12=DosyaOkuma.getUzayAraciList().listIterator();
		while(uItr12.hasNext()) {
		UzayAraci u=uItr12.next();	
		if(u.getKalanMesafe()==0 && u.getNufus()!=0) {
			 u.setDurum("Vardi");
				continue;
			}
		if(u.getNufus()==0) {
			u.setDurum("IMHA");
			continue;
		}
		ListIterator<Gezegen> gItr12=DosyaOkuma.getGezegenList().listIterator();
		while(gItr12.hasNext()) {
			Gezegen g=gItr12.next();
			if((g.getZamanCizelgesi().getTarih().isAfter(u.getCikisTarihi()) || g.getZamanCizelgesi().getTarih().isEqual(u.getCikisTarihi()))&& g.getGezegenAdi().equals(u.getCikisGezegeniAdi())) {
				u.setDurum("Yolda");
			}
			
		

			
		
		}
		}
	}


	private static void gunuBirArtir() 
	{
		ListIterator<Gezegen> gItr16=DosyaOkuma.getGezegenList().listIterator();
		while(gItr16.hasNext()) {
			Gezegen g=gItr16.next();
			if(gecenZaman%g.getZamanCizelgesi().getBirGununKacSaatOldugu()==0) {
			g.getZamanCizelgesi().setTarih(g.getZamanCizelgesi().getTarih().plusDays(mode));
		
			}
			
		}
	
	}
	public static void Durdur(boolean b) 
	{
		Dur=b;
	}

	
	}












