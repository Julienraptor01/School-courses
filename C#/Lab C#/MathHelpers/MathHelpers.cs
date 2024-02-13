namespace MathHelpers
{
	public class MathHelpers
	{
		public static double AireRectangle(double longueur, double largeur)
		{
			return longueur * largeur;
		}

		public static double AireCarre(double longueur)
		{
			return longueur * longueur;
		}

		public static double AireCercle(double rayon)
		{
			return Math.PI * Math.Pow(rayon, 2);
		}
	}
}
