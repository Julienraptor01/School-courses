namespace MathHelpers
{
	public class MathHelpers
	{
		public static double AireRectangle(double longueur, double largeur) => longueur * largeur;

		public static double AireCarre(double longueur) => longueur * longueur;

		public static double AireCercle(double rayon) => Math.PI * Math.Pow(rayon, 2);
	}
}
