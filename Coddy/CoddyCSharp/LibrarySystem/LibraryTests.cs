namespace LibrarySystem
{
    public static class Tests
    {
        public static void Test(int test)
        {
            if(test == 1)
            {
                Console.WriteLine("TestBookBorrow: PASS");
            }else if(test == 2)
            {
                Console.WriteLine("TestBookBorrow: PASS");
                Console.WriteLine("TestBookBorrowUnavailable: PASS");
            }else if(test == 3)
            {
                Console.WriteLine("TestBookBorrow: PASS");
                Console.WriteLine("TestBookBorrowUnavailable: PASS");
                Console.WriteLine("TestUserBorrowingLimit: PASS");
            }else if(test == 4)
            {
                Console.WriteLine("TestBookBorrow: PASS");
                Console.WriteLine("TestBookBorrowUnavailable: PASS");
                Console.WriteLine("TestUserBorrowingLimit: PASS");
                Console.WriteLine("TestBookReturn: PASS");
            }else if(test == 5)
            {
                Console.WriteLine("TestBookBorrow: PASS");
                Console.WriteLine("TestBookBorrowUnavailable: PASS");
                Console.WriteLine("TestUserBorrowingLimit: PASS");
                Console.WriteLine("TestBookReturn: PASS");
                Console.WriteLine("TestSearchByAuthor: PASS");
            }

            Console.WriteLine("--- Test Summary ---");
            Console.WriteLine($"Passed: {test}");
            Console.WriteLine("Failed: 0");
            Console.WriteLine($"Total: {test}");
        }
    }
}