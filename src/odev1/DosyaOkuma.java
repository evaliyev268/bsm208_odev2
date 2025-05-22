package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
* .txt dosyalari okunarak uzerinde islem yapilabilecek listeler halinde toplanir.
* </p>
*
*/
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;
import java.util.regex.*;
import java.time.temporal.ChronoUnit;
public class DosyaOkuma 
{
	
//DosyaYollari	
private String KisilerPath="C:\\Users\\evali\\Downloads\\B231210565\\dist\\TXTS\\Kisiler.txt";
private String GezegenlerPath="C:\\Users\\evali\\Downloads\\B231210565\\dist\\TXTS\\Gezegenler.txt";
private String AraclarPath="C:\\Users\\evali\\Downloads\\B231210565\\dist\\TXTS\\Araclar.txt";
//


//.txt lerden okunan verilerin kaydedileceyi listeler
private static List<Kisi> kisiList=new ArrayList<>();
private static List<Gezegen> gezegenList=new ArrayList<>();
private static List<UzayAraci> uzayAraciList=new ArrayList<>();
//

//Regex Kaliplari
private String kisiPattern="([A-Za-z0-9]+)#([0-9]{2})#([0-9]+)#([A-Z][0-9]{1,2})";
private String gezegenPattern="([A-Z][0-9]{1,2})#([0-9]+)#([0-9]{2}\\.[0-9]{2}\\.[0-9]{4})";
private String uzayAraciPattern="([A-Z][0-9]{1,2})#([A-Z][0-9]{1,2})#([A-Z][0-9]{1,2})#([0-9]{2}\\.[0-9]{2}\\.[0-9]{4})#([0-9]+)";
//

//Regex Pattern leri ve Tarih icin ozel pattern
private Pattern aracRegex=Pattern.compile(uzayAraciPattern);
private Pattern gezegenRegex=Pattern.compile(gezegenPattern);
private Pattern kisiRegex=Pattern.compile(kisiPattern);
private DateTimeFormatter formatter=DateTimeFormatter.ofPattern("dd.MM.yyyy");
//


private void readKisiler() 
{//Kisiler.txt yi oku
	try(BufferedReader reader=new BufferedReader(new FileReader(KisilerPath))) 
	{
	
		String kisiLine;
	while ((kisiLine = reader.readLine()) != null) 
	{
			    kisiLine = kisiLine.trim();
			    Matcher matcher = kisiRegex.matcher(kisiLine);
	if (matcher.matches()) 
	{//Dosyadaki tekrar eden veri listelere kayit edilmeyecek
			        boolean kisiAyniMi = false;
			        ListIterator<Kisi> kisiItr = kisiList.listIterator();
	while(kisiItr.hasNext()) 
	{ 
			        	Kisi kisi=kisiItr.next();
	if (kisi.getKisiAdi().equals(matcher.group(1)) && kisi.getYasString().equals(matcher.group(2))) 
	{ //Ayni isme sahip ve ya Ayni yasa sahip....
		//.....Birden fazla kisi ola bilir ancak hem Ismi hem de Yasi ayni olan 2ci bir kisi olamaz
			                kisiAyniMi = true; 
			                break; 
			            }
			        }
			      
	 if (!kisiAyniMi)  
	 {
		 kisiItr.add(new Kisi(matcher.group(1), matcher.group(2), matcher.group(3), matcher.group(4)));
	 }
			    }   
			     else 
			     {
			        System.out.println("Hata! Kisiler.txt dosyasinin icerisinde yazim formatina uymayan veri var!");
			        System.out.println("Yazim Formati: "+ kisiPattern);
			        Simulasyon.Durdur(true);
			        break;
			     }
			}
		}
	catch(IOException e)
	{
		System.out.println("File read error"+e.getMessage());
	}
	
	if(kisiList.isEmpty()) {
		System.out.println("Kisiler.txt bos ola bilir, icerisinde uyumsuz kalip buluna bilir");
	}
}

public static void setAllVarisTarihi(List<UzayAraci> t) 
{ 
	//UzayAraci listesinde Varis tarihi buluna bilen UzayAraclarinin VarisTarihlerini otomatik olarak ayarlar.
	//Bu VarisTarihine sahip olmayan verilerin sistemi yormamasi icin gerekledir.
	
	ListIterator<Gezegen> gItr11=DosyaOkuma.getGezegenList().listIterator(); 
	while(gItr11.hasNext())
	{
		Gezegen g=gItr11.next();
	ListIterator<UzayAraci> uItr14=t.listIterator();
	while(uItr14.hasNext())
	{
		UzayAraci u=uItr14.next();
		if(u.getVarisGezegeniAdi().equals(g.getGezegenAdi())) 
		{
			
			
			LocalDate vT=g.getZamanCizelgesi().getTarih().plusDays(u.getKalanMesafe()/g.getZamanCizelgesi().getBirGununKacSaatOldugu());
			u.setVarisTarihi(vT);
			
			if(u.getVarisTarihi().isBefore(g.getZamanCizelgesi().getTarih())) {
				u.setVarisTarihi(null);
			}
		}
	}
				
		}
	
	
	farkHesabi(t);
}

private static void farkHesabi(List<UzayAraci> t) {
	ListIterator<Gezegen> gItr20=gezegenList.listIterator();
	while(gItr20.hasNext()) {
		Gezegen g1 =gItr20.next();
		
		ListIterator<UzayAraci> uItr20=t.listIterator();
		while(uItr20.hasNext()){
			UzayAraci u1=uItr20.next();
		if((u1.getCikisGezegeniAdi().equals(g1.getGezegenAdi())) && (u1.getVarisTarihi()!=null)) {
			
			
			long gunSayi=ChronoUnit.DAYS.between(g1.getZamanCizelgesi().getTarih(),u1.getCikisTarihi());
		
			if(gunSayi>0) {
				
			u1.setVarisTarihi(u1.getVarisTarihi().plusDays(gunSayi));
		
			
			}
			else {
		
			u1.setVarisTarihi(null);
			;
			}
			
		}
		}
	}
}
private void readAraclar() 
{
	//Araclar.txt yi oku
	List<UzayAraci> veri=new ArrayList<>();
try(BufferedReader reader=new BufferedReader(new FileReader(AraclarPath))) 
{
		String aracLine;
		
while((aracLine=reader.readLine())!=null) 
{
			aracLine=aracLine.trim();
			Matcher matcher=aracRegex.matcher(aracLine);
		if(matcher.matches()) 
		{
				
				LocalDate cta=LocalDate.parse(matcher.group(4),formatter);
			veri.add(new UzayAraci(matcher.group(1),matcher.group(2),matcher.group(3),cta,matcher.group(5)));
			
			
			}
			
			else 
			{
				
				System.out.println("Hata! Araclar.txt dosyasinin icerisinde yazim formatina uymayan veri var!");
				 System.out.println("Yazim Formati: "+ uzayAraciPattern);
				 Simulasyon.Durdur(true);
				break;
			}
			
			
		}
 
	}
	catch(IOException e)
{
		System.out.println("File read error"+e.getMessage());
	}

    setAllVarisTarihi(veri);
	ListIterator<Gezegen> gItr6=gezegenList.listIterator();
	while(gItr6.hasNext()) 
	{
	
	Gezegen gezegen=gItr6.next();
	
	ListIterator<UzayAraci> uItr7=veri.listIterator();
	
	while(uItr7.hasNext())
	{
	
		UzayAraci arac=uItr7.next();
		if(arac.getCikisGezegeniAdi().equals(gezegen.getGezegenAdi()) && (arac.getVarisTarihi()!=null)) 
		{
			//VarisTarihi bulunan veriler kalici listeye aktariliyor.
			
			ListIterator<UzayAraci> uItr9=uzayAraciList.listIterator();
			boolean aynisiVarmi=false;
			OtherWhile:
			while(uItr9.hasNext()) {
				UzayAraci u=uItr9.next();
				
				if(u.getUzayAraciAdi().equals(arac.getUzayAraciAdi()) || arac.getCikisGezegeniAdi().equals(arac.getVarisGezegeniAdi())) {
					
					aynisiVarmi=true;
					break OtherWhile;
				}
			}
				
			if(aynisiVarmi==false) 
			{
				
					uzayAraciList.add(arac);
				}
			
			
			
		 
		}
		
	}
	
}
	System.out.println("SizeU "+ uzayAraciList.size());
	if(uzayAraciList.isEmpty()) {
		System.out.println("Cikis gezegeni ve Varis gezegeninin her ikisi hakkinda bilgi bulunmayan Uzay Araclari sisteme dahil edilmez!");
		System.out.println("Cikis ve ya Varis tarihi acisindan tutarsizlik olusturan Uzay Araclari sisteme dahil edilmez!");
		System.out.println("Araclar.txt bos ola bilir, icerisinde uyumsuz kalip buluna bilir ve ya yukaridaki sart saglanmamaktadir.");
	}
}

static int c=0;
private void readGezegenler() 
{
	//Gezegenler.txt  yi oku
	try(BufferedReader reader=new BufferedReader(new FileReader(GezegenlerPath))) 
	{
		String gezegenLine;
		
	while((gezegenLine=reader.readLine())!=null) 
	{
			gezegenLine=gezegenLine.trim();
			Matcher matcher=gezegenRegex.matcher(gezegenLine);
	if(matcher.matches()) 
	{
			boolean gezegenAyniMi=false;	
			LocalDate gSt=LocalDate.parse(matcher.group(3),formatter);
			ListIterator<Gezegen> gezegenItr = gezegenList.listIterator();
	while(gezegenItr.hasNext())
	{
			Gezegen gezegen=gezegenItr.next();	
	 if(gezegen.getGezegenAdi().equals(matcher.group(1))) 
	 { //Ayni gezegen hakkinda sadece ilk veri kayit altina alinir.
				gezegenAyniMi=true;
				break;
			}
			}
	
	
	
	 if(!gezegenAyniMi) 
	 {
		 
		 gezegenItr.add(new Gezegen(matcher.group(1),matcher.group(2),gSt));	
	 }
			}
			else 
			{
				//System.out.println(gezegenLine);
				System.out.println("Hata! Gezegenler.txt dosyasinin icerisinde yazim formatina uymayan veri var!");
				 System.out.println("Yazim Formati: "+ gezegenPattern);
				 Simulasyon.Durdur(true);
				break;
			}
		}
		
	}
	catch(IOException e)
	{
		System.out.println("File read error"+e.getMessage());
	}
	if(gezegenList.isEmpty()) {
		System.out.println("Gezegenler.txt bos ola bilir, icerisinde uyumsuz kalip buluna bilir");
	}
}



	//Get Metodlari
	public static  List<Gezegen> getGezegenList() 
	{
		return gezegenList;
	}
	public static List<Kisi> getKisiList() 
	{
		return kisiList;
	}
	public static List<UzayAraci> getUzayAraciList() 
	{
		return uzayAraciList;
	}
	//

 //Kurucu
	DosyaOkuma()
	{
		readKisiler();
		readGezegenler();
		readAraclar();
	}
}
