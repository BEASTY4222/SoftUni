using System;
using System.Collections;

namespace DataAnalysis
{
    public class DataCollector
    {
            public static int[][] CreateScoreGrid(int students, int assignments)
        {
            // Write your code here
            int[][] scores = new int[students][];

            for (int i = 0; i < students; i++)
            {
                scores[i] = new int[assignments];
            }

            return scores;
        }
        
        public static bool ValidateScore(int? score)
        {
            // Write your code here
            return score >= 0 && score <= 100;
        }
        
        public static int[][] PopulateWithDefaultValues(int[][] scoreGrid)
        {
            // Write your code here
            for(int i = 0;i <  scoreGrid.Length;i++)
                for(int j = 0; j <  scoreGrid[i].Length;j++)
                    scoreGrid[i][j] = -1;
            
            return scoreGrid;
        }
    }
        public class DataEntry : DataCollector{
        public static int SetStudentScore(int[][] scoreGrid, int studentIndex, int assignmentIndex, int? score)
        {
            if(score == null || !ValidateScore(score)) return -2;
            try
            {
                scoreGrid[studentIndex][assignmentIndex] = score.Value;
            }
            catch (IndexOutOfRangeException)
            {
                return -1;
            }

            return 0;
        }

        public static int UpdateAllScores(int[][] scoreGrid, int[] studentIndices, int assignmentIndex, int score)
        {
            int counter = 0;
            for(int i = 0;i < studentIndices.Length; i++)
            {
                if (SetStudentScore(scoreGrid,studentIndices[i],assignmentIndex,score) == 0)
                {
                    counter++;
                }
            }
            return counter;
        }
    }

    public class DataAnalyzer : DataEntry
    {
        public static double CalculateStudentAverage(int[][] scoreGrid, int studentIndex)
        {
            double average = 0;
            int counter = 0;
            try{
                for(int i = 0; i < scoreGrid[studentIndex].Length; i++)
                {
                    if(scoreGrid[studentIndex][i] <= 0)
                        continue;

                    if(ValidateScore(scoreGrid[studentIndex][i]))
                    {
                        average += scoreGrid[studentIndex][i];
                        counter++;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }catch(IndexOutOfRangeException){return -1;}
            return counter > 0 ? average / counter : 0;
        }

        public static double CalculateAssignmentAverage(int[][] scoreGrid, int assignmentIndex)
        {
            int counter = 0;
            double average = 0;

            for (int i = 0; i < scoreGrid.Length; i++)
            {
                if (assignmentIndex >= scoreGrid[i].Length)
                    return -1;

                int score = scoreGrid[i][assignmentIndex];

                if (score <= 0)
                    continue;

                if (!ValidateScore(score))
                    return -1;

                average += score;
                counter++;
            }

            return counter > 0 ? average / counter : 0;
        }

        public static int[] FindHighestScore(int[][] scoreGrid)
        {
            int score = 0, indexS = 0, indexA = 0;

            try
            {
                for(int i = 0;i < scoreGrid.Length; i++)
                {
                    for (int j = 0;j < scoreGrid[i].Length;j++)
                    {
                        if(scoreGrid[i][j] > score)
                        {
                            score = scoreGrid[i][j];
                            indexS = i;
                            indexA = j;
                        }
                    }
                }
            }
            catch (IndexOutOfRangeException)
            {
                return new int[]{0,0,0};
            }

            return new int[]{indexS, indexA,score};
        }
    }

    public class GradingSystem : DataAnalyzer
    {
        public static string ConvertToLetterGrade(double? score)
        {
            if(score == null || !ValidateScore((int)score))
                return "N/A";
        
            if(score >= 90 && score <= 100) return "A";
            if(score >= 80 && score <= 89) return "B";
            if(score >= 70 && score <= 79) return "C";
            if(score >= 60 && score <= 69) return "D";
            
            return "F";
        }

        public static string GetStudentGrade(int[][] scoreGrid, int studentIndex)
        {
            return ConvertToLetterGrade(CalculateStudentAverage(scoreGrid,studentIndex));
        }

        public static int[] GetClassDistribution(int[][] scoreGrid)
        {
            // [A, B, C, D, F]
            int[] distribution = new int[5];

            for (int i = 0; i < scoreGrid.Length; i++)
            {
                string grade = GetStudentGrade(scoreGrid, i);

                switch (grade)
                {
                    case "A":
                        distribution[0]++;
                        break;

                    case "B":
                        distribution[1]++;
                        break;

                    case "C":
                        distribution[2]++;
                        break;

                    case "D":
                        distribution[3]++;
                        break;

                    case "F":
                        distribution[4]++;
                        break;
                }
            }

            return distribution;
        }
    }

    public class ReportGenerator : GradingSystem
    {
        public static string GenerateStudentReport(int[][] scoreGrid, int studentIndex)
        {
            //Student #X | Average: YY.Y | Grade: Z\nAssignment scores: S1, S2, S3, ...
            
            string result = $"Student #{studentIndex} | Average: {CalculateStudentAverage(scoreGrid,studentIndex):F1} | Grade: {GetStudentGrade(scoreGrid,studentIndex)}\n";
            result += "Assignment scores: ";

            ArrayList scores = new ArrayList();

            if (studentIndex >= scoreGrid.Length)
                    return "Invalid student index";
                
            short lenght = (short)scoreGrid[studentIndex].Length;
            for(int i = 0;i < lenght;i++)
            {
                if(scoreGrid[studentIndex][i] < 0) scores.Add("N/A");
                else scores.Add(scoreGrid[studentIndex][i]);
            }

            result +=  String.Join(", ",scores.ToArray());

            return result;
        }

        public static string GenerateClassSummary(int[][] scoreGrid)
        {
            double classAverage = 0;
            for(int i = 0;i < scoreGrid.Length; i++)
            {
                classAverage += CalculateStudentAverage(scoreGrid,i);
            }

            int[] clasDistibution = GetClassDistribution(scoreGrid);
            //Class Summary\nTotal Students: X\nClass Average: YY.Y\nGrade Distribution: A: #, B: #, C: #, D: #, F: #"
            string result = $"Class Summary\nTotal Students: {scoreGrid.Length}\nClass Average: {classAverage/(double)scoreGrid.Length:F1}\nGrade Distribution: A: {clasDistibution[0]}, B: {clasDistibution[1]}, C: {clasDistibution[2]}, D: {clasDistibution[3]}, F: {clasDistibution[4]}";

            return result;
        }

        public static string GenerateAssignmentReport(int[][] scoreGrid, int assignmentIndex)
        {
            //Assignment #X | Average: YY.Y | Completion Rate: Z%
            double assignmentAverage = CalculateAssignmentAverage(scoreGrid,assignmentIndex);

            double completed = 0;
            for (int i = 0; i < scoreGrid.Length; i++)
            {
                if (assignmentIndex >= scoreGrid[i].Length)
                    return "Invalid assignment index";

                int score = scoreGrid[i][assignmentIndex];

                if (score <= 0)
                {
                    continue;
                }
                if (!ValidateScore(score))
                {
                    continue;
                }
                completed++;

            }
            

            string result = $"Assignment #{assignmentIndex} | Average: {assignmentAverage:F1} | Completion Rate: {(completed / scoreGrid.Length)*100}%";


            return result;
        }
    }

    public class ErrorHandler : DataAnalyzer
    {
        public static string ValidateInput(int[][] scoreGrid, int studentIndex, int assignmentIndex)
        {
            if(studentIndex >= scoreGrid.Length) return "Invalid student index";
            if(assignmentIndex >= scoreGrid[studentIndex].Length) return "Invalid assignment index";

            return "";
        }

        public static int SafeGetScore(int[][] scoreGrid, int studentIndex, int assignmentIndex)
        {
            if(studentIndex >= scoreGrid.Length || assignmentIndex >= scoreGrid[studentIndex].Length) return -999;

            return scoreGrid[studentIndex][assignmentIndex];
        }

        public static string[] ProcessBatchUpdate(int[][] scoreGrid, int[][] updates)
        {
            List<string> errors = new List<string>();

            for (int i = 0; i < updates.Length; i++)
            {
                // Must contain exactly 3 values
                if (updates[i].Length != 3)
                {
                    errors.Add($"Error at index {i}: Invalid update format");
                    continue;
                }

                int studentIndex = updates[i][0];
                int assignmentIndex = updates[i][1];
                int score = updates[i][2];

                // Validate student index
                if (studentIndex < 0 || studentIndex >= scoreGrid.Length)
                {
                    errors.Add($"Error at index {i}: Invalid student index");
                    continue;
                }

                // Validate assignment index
                if (assignmentIndex < 0 || assignmentIndex >= scoreGrid[studentIndex].Length)
                {
                    errors.Add($"Error at index {i}: Invalid assignment index");
                    continue;
                }

                // Validate score
                if (!ValidateScore(score))
                {
                    errors.Add($"Error at index {i}: Invalid score value");
                    continue;
                }

                // Apply update
                scoreGrid[studentIndex][assignmentIndex] = score;
            }
            
            return errors.ToArray();
        }
    }
}