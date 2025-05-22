package odev1;
/**
*
* @author Elvin Valiyev - elvin.valiyev@sakarya.edu.tr
* @since 31.03.2025
* <p>
	Windows Isletim sistemi icin konsol ekraninin temizlenmesi
* </p>
*
*/
import java.io.IOException;
public class Console 
{
	 public static void clearConsole() 
    {
        try 
        {
    
            new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
        } catch (IOException | InterruptedException ex) {
            System.out.println("Konsol temizleme hatası: " + ex.getMessage());
        }
    }
}

