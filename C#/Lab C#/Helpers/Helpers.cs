namespace Helpers
{
	public class Helpers
	{
		public static void Shuffle<T>(List<T> list)
		{
			Random random = new();
			int n = list.Count;
			while (n > 1)
			{
				int k = random.Next(n--);
				(list[k], list[n]) = (list[n], list[k]);
			}
		}
	}
}
