import java.util.Scanner;

public class HeartRateCalculator {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    
    System.out.println("Enter first name: ");
    String firstName = scan.nextLine();
    
    System.out.println("Enter last name: ");
    String lastName = scan.nextLine();
    
    System.out.println("Enter date of birth (mm/dd/yy): ");
    String dateOfBirth = scan.nextLine();
    
    System.out.println("Enter your heart rate: ");
    int heartRate = scan.nextInt();
    
    if (heartRate <= 0) {
      System.out.println("Invalid heart rate! Please enter a valid value.");
      return;
    }
    
    int maxHeartRate = 220 - (2020 - Integer.parseInt(dateOfBirth.split("/")[2]));
    int targetHeartRateMin = (int)(maxHeartRate * 0.5);
    int targetHeartRateMax = (int)(maxHeartRate * 0.85);
    
    System.out.println("\n" + firstName + " " + lastName + ":");
    System.out.println("Max heart rate: " + maxHeartRate + " bpm");
    System.out.println("Target heart rate range: " + targetHeartRateMin + "-" + targetHeartRateMax + " bpm");
  }
}