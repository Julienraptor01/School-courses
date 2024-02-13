using MyShapeLibrary;

namespace Lab_1
{
	internal class Program
	{
		static void Main(string[] args)
		{
			Coordonnee[] coordonnee = [new(1, 2), new(3, 4)];
			Console.WriteLine("Coordinates:");
			foreach (Coordonnee c in coordonnee)
				Console.WriteLine(c);

			Console.WriteLine();

			Carre[] carre = [new(5, coordonnee[0]), new(6, coordonnee[1])];
			Console.WriteLine("Carres:");
			foreach (Carre c in carre)
				Console.WriteLine(c);

			Console.WriteLine();

			Cercle[] cercle = [new(7, coordonnee[0]), new(8, coordonnee[1])];
			Console.WriteLine("Circles:");
			foreach (Cercle c in cercle)
				Console.WriteLine(c);

			Console.WriteLine();

			Rectangle[] rectangle = [new(9, 10, coordonnee[0]), new(11, 12, coordonnee[1])];
			Console.WriteLine("Rectangles:");
			foreach (Rectangle r in rectangle)
				Console.WriteLine(r);

			Console.WriteLine();

			List<Forme> formes =
			[
				carre[0],
				carre[1],
				cercle[0],
				cercle[1],
				rectangle[0],
				rectangle[1],
			];
			Console.WriteLine("Shapes:");
			foreach (Forme f in formes)
				Console.WriteLine(f);

			Console.WriteLine();

			List<Forme> formesPolygones = [];
			List<Forme> formesNonPolygones = [];
			foreach (Forme f in formes)
				if (f is IPolygone)
					formesPolygones.Add(f);
				else
					formesNonPolygones.Add(f);
			Console.WriteLine("Polygons:");
			foreach (Forme f in formesPolygones)
				Console.WriteLine(f);
			Console.WriteLine("Non-polygons:");
			foreach (Forme f in formesNonPolygones)
				Console.WriteLine(f);

			Console.WriteLine();

			List<Carre> carres =
			[
				carre[0],
				carre[1],
				new Carre(13, coordonnee[0]),
				new Carre(14, coordonnee[1]),
				new Carre(15, coordonnee[0]),
			];
			Console.WriteLine("Carres:");
			foreach (Carre c in carres)
				Console.WriteLine(c);
			Helpers.Helpers.Shuffle(carres);

			Console.WriteLine();

			Console.WriteLine("Carres shuffled:");
			foreach (Carre c in carres)
				Console.WriteLine(c);
			carres.Sort();
			Console.WriteLine("Carres sorted:");
			foreach (Carre c in carres)
				Console.WriteLine(c);

			Console.WriteLine();

			Helpers.Helpers.Shuffle(carres);
			Console.WriteLine("Carres shuffled:");
			foreach (Carre c in carres)
				Console.WriteLine(c);
			FormeAbscisseComparer formeAbscisseComparer = new();
			carres.Sort(formeAbscisseComparer);
			Console.WriteLine("Carres sorted by abscisse (using formeAbscisseComparer):");
			foreach (Carre c in carres)
				Console.WriteLine(c);

			Console.WriteLine();

			Helpers.Helpers.Shuffle(carres);
			Console.WriteLine("Carres shuffled:");
			foreach (Carre c in carres)
				Console.WriteLine(c);
			Console.WriteLine("Carres sorted by abscisse (using OrderBy):");
			foreach (Carre c in carres.OrderBy(c => c.PointAccroche.X))
				Console.WriteLine(c);

			Console.WriteLine();

			double coteReference = 10;
			Carre carreReference = carres.Find(c => c.Longueur > coteReference) ?? throw new Exception("No square with side length superior to {coteReference}");
			int index = carres.FindIndex(c => c.Longueur > coteReference);
			Console.WriteLine($"First square with side length superior to {coteReference} is \"{carreReference}\" at index {index}");

			Console.WriteLine();

			carreReference = carres.FindLast(c => c.Longueur > coteReference) ?? throw new Exception("No square with side length superior to {coteReference}");
			index = carres.FindLastIndex(c => c.Longueur > coteReference);
			Console.WriteLine($"Last square with side length superior to {coteReference} is \"{carreReference}\" at index {index}");

			Console.WriteLine();

			List<Carre> carresReference = carres.FindAll(c => c.Longueur > coteReference);
			Console.WriteLine($"Squares with side length superior to {coteReference}:");
			foreach (Carre c in carresReference)
				Console.WriteLine(c);

			Console.WriteLine();

			if (carres.Exists(c => c.Longueur == coteReference))
				Console.WriteLine($"List contains a square with side length equal to {coteReference}");
			else
				Console.WriteLine($"List does not contain a square with side length equal to {coteReference}");

			Console.WriteLine();

			if (carres.Contains(carreReference))
				Console.WriteLine($"List contains \"{carreReference}\"");
			else
				Console.WriteLine($"List does not contain \"{carreReference}\"");

			Console.WriteLine();

			List<Forme> formesCoordonnee = formes.FindAll(f => f is IEstDans forme && forme.CoordonneeEstDans(coordonnee[0]));
			Console.WriteLine($"Shapes containing {coordonnee[0]}:");
			foreach (Forme f in formesCoordonnee)
				Console.WriteLine(f);
		}
	}
}
