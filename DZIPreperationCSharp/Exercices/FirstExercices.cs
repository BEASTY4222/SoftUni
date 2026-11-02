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

		static public void flightTimes()
		{
			int startTimeHours = Convert.ToInt32(Console.ReadLine());
			int startTimeMins = Convert.ToInt32(Console.ReadLine());
			int flightTimeHours = Convert.ToInt32(Console.ReadLine());
			int flightTimeMins = Convert.ToInt32(Console.ReadLine());

			int landingHours = startTimeHours + flightTimeHours;

			int landingMins = startTimeMins + flightTimeMins;
			if(landingMins > 60)
			{
				landingMins -= 60;
				landingHours++;
			}

			if(landingHours > 24) landingHours -= 24;

			string landingHoursString = String.Empty;
			string landingminsString = String.Empty;

			if(landingHours < 10) landingHoursString = "0" +  Convert.ToString(landingHours);
			if(landingMins < 10) landingminsString = "0" + Convert.ToString(landingMins);
		
			Console.WriteLine($"{landingHoursString}:{landingminsString}");
		} 
	}
	 

}
