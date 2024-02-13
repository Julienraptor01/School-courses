using MathHelpers;
using System.Diagnostics.CodeAnalysis;

namespace MyShapeLibrary
{
	public class Coordonnee(int x, int y)
	{
		public int X { get; set; } = x;
		public int Y { get; set; } = y;
		public Coordonnee() : this(0, 0) { }
		public override string ToString()
		{
			return $"({X},{Y})";
		}
	}

	public abstract class Forme(Coordonnee pointAccroche)
	{
		public Coordonnee PointAccroche { get; set; } = pointAccroche;
		public Forme() : this(new Coordonnee()) { }
	}

	public class FormeAbscisseComparer : IComparer<Forme>
	{
		int IComparer<Forme>.Compare(Forme? x, Forme? y)
		{
			ArgumentNullException.ThrowIfNull(x);
			ArgumentNullException.ThrowIfNull(y);
			return x.PointAccroche.X.CompareTo(y.PointAccroche.X);
		}
	}

	public interface IEstDans
	{
		bool CoordonneeEstDans(Coordonnee p);
	}

	public interface IPolygone
	{
		int NbSomments { get; }
	}

	public class Carre(double longueur, Coordonnee pointAccroche) : Forme(pointAccroche), IEstDans, IPolygone, IComparable<Carre>
	{
		public double Longueur { get; set; } = longueur;
		public Carre() : this(0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return pointAccroche.X >= PointAccroche.X && pointAccroche.X <= PointAccroche.X + Longueur && pointAccroche.Y >= PointAccroche.Y && pointAccroche.Y <= PointAccroche.Y + Longueur;
		}
		public int NbSomments
		{
			get { return 4; }
		}
		public override string ToString()
		{
			return $"Square of side length {Longueur} and of anchor point {PointAccroche}";
		}

		public int CompareTo(Carre? other)
		{
			ArgumentNullException.ThrowIfNull(other);
			return MathHelpers.MathHelpers.AireCarre(Longueur).CompareTo(MathHelpers.MathHelpers.AireCarre(other.Longueur));
		}
	}
	public class Cercle(int rayon, Coordonnee pointAccroche) : Forme(pointAccroche), IEstDans
	{
		public double Rayon { get; set; } = rayon;
		public Cercle() : this(0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return Math.Pow(pointAccroche.X - PointAccroche.X, 2) + Math.Pow(pointAccroche.Y - PointAccroche.Y, 2) <= Math.Pow(Rayon, 2);
		}
		public double Diametre
		{
			get { return Rayon * 2; }
		}
		public override string ToString()
		{
			return $"Circle of radius {Rayon} and of anchor point {PointAccroche}";
		}
	}

	public class Rectangle(double longueur, double largeur, Coordonnee pointAccroche) : Forme(pointAccroche), IEstDans, IPolygone
	{
		public double Longueur { get; set; } = longueur;
		public double Largeur { get; set; } = largeur;
		public Rectangle() : this(0, 0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return pointAccroche.X >= PointAccroche.X && pointAccroche.X <= PointAccroche.X + Longueur && pointAccroche.Y >= PointAccroche.Y && pointAccroche.Y <= PointAccroche.Y + Largeur;
		}
		public int NbSomments
		{
			get { return 4; }
		}
		public override string ToString()
		{
			return $"Rectangle of length {Longueur}, width {Largeur} and of anchor point {PointAccroche}";
		}
	}
}
