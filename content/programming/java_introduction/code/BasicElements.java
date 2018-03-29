package introduction;

import java.util.Scanner;

// This is a single-line comment.

/*
 * This is a multi-line comment.
 */

// The following is class declaration.
public class BasicElements {

	// The following is a variable of type String.
	public String name;
	// The following is a variable of type string array.
	public String[] favoriteColors;

	/*
	 * The following is the constructor of the class. With the help of a constructor
	 * objects of the type of the class are instantiated (Later more about that).
	 */
	public BasicElements(String name) {
		this.name = name;
		this.favoriteColors = new String[] { "red", "blue", "green" };
	}

	// The following is a method.
	public void printFavoriteColors() {
		int numberOfFavoriteColors = this.favoriteColors.length;

		// The following is a for loop.
		for (int i = 0; i < numberOfFavoriteColors; i++) {
			System.out.println(this.favoriteColors[i]);
		}
	}

	public static void main(String[] args) {

		// The following is a condition.
		if (args.length > 0) {
			for (String inputArgument : args) {
				System.out.println(inputArgument);
			}
		}
		
		// The following is using a class to perform input in Java.
		Scanner	sc = new Scanner(System.in);
		String name = sc.nextLine();
		sc.close();
		System.out.println("Hello, " + name + " nice to meet you!");
		
		// The following is an object of the class BasicElements.
		BasicElements firstInstance = new BasicElements(name);
		firstInstance.printFavoriteColors();
		System.out.println("Saved in the object's variable: " + firstInstance.name);
	}
}
