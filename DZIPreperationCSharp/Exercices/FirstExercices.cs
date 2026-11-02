namespace FirstExercices{
	public static class FirstExercices {
		static public void Scramble(string number){//123
			Console.WriteLine($"{number[0]}{number[1]}{number[2]}");//123
			Console.WriteLine($"{number[1]}{number[2]}{number[0]}");//231
			Console.WriteLine($"{number[2]}{number[0]}{number[1]}");//312
			Console.WriteLine($"{number[0]}{number[2]}{number[1]}");//132
			Console.WriteLine($"{number[2]}{number[1]}{number[0]}");//321
			Console.WriteLine($"{number[1]}{number[0]}{number[2]}");//213
		}
	}
	 

}
