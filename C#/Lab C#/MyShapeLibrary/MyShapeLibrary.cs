namespace MyShapeLibrary
{
	public class Coordonnee(int x, int y)
	{
		public int X
		{
			get { return x; }
			set { x = value; }
		}
		public int Y
		{
			get { return y; }
			set { y = value; }
		}
		public Coordonnee() : this(0, 0) { }
		public override string ToString() => $"({X},{Y})";
	}

	public abstract class Forme(Coordonnee pointAccroche)
	{
		public Coordonnee PointAccroche
		{
			get { return pointAccroche; }
			set { pointAccroche = value; }
		}
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
		public double Longueur
		{
			get { return longueur; }
			set { longueur = value; }
		}
		public Carre() : this(0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return pointAccroche.X >= PointAccroche.X && pointAccroche.X <= PointAccroche.X + Longueur && pointAccroche.Y >= PointAccroche.Y && pointAccroche.Y <= PointAccroche.Y + Longueur;
		}
		public int NbSomments => 4;
		public override string ToString() => $"Square of side length {Longueur} and of anchor point {PointAccroche}";
		public int CompareTo(Carre? other)
		{
			ArgumentNullException.ThrowIfNull(other);
			return MathHelpers.MathHelpers.AireCarre(Longueur).CompareTo(MathHelpers.MathHelpers.AireCarre(other.Longueur));
		}
	}
	public class Cercle(int rayon, Coordonnee pointAccroche) : Forme(pointAccroche), IEstDans
	{
		public int Rayon
		{
			get { return rayon; }
			set { rayon = value; }
		}
		public Cercle() : this(0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return Math.Pow(pointAccroche.X - PointAccroche.X, 2) + Math.Pow(pointAccroche.Y - PointAccroche.Y, 2) <= Math.Pow(Rayon, 2);
		}
		public int Diametre => Rayon * 2;
		public override string ToString() => $"Circle of radius {Rayon} and of anchor point {PointAccroche}";
	}

	public class Rectangle(double longueur, double largeur, Coordonnee pointAccroche) : Forme(pointAccroche), IEstDans, IPolygone
	{
		public double Longueur
		{
			get { return longueur; }
			set { longueur = value; }
		}
		public double Largeur
		{
			get { return largeur; }
			set { largeur = value; }
		}
		public Rectangle() : this(0, 0, new Coordonnee()) { }
		public bool CoordonneeEstDans(Coordonnee pointAccroche)
		{
			return pointAccroche.X >= PointAccroche.X && pointAccroche.X <= PointAccroche.X + Longueur && pointAccroche.Y >= PointAccroche.Y && pointAccroche.Y <= PointAccroche.Y + Largeur;
		}
		public int NbSomments => 4;
		public override string ToString() => $"Rectangle of length {Longueur}, width {Largeur} and of anchor point {PointAccroche}";
	}
}
