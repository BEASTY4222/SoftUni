namespace LibrarySystem
{
    public class User
    {
        // TODO: Create auto-implemented property for Name (string)
        public string Name {get; set;}
        // TODO: Create auto-implemented property for MemberId (int)
        public int MemberId {get; private set;}
        private List<string> _borrowedBooks;
        public int BorrowedBooksCount {get => _borrowedBooks.Count;}
        public const int MAX_BORROWED_BOOKS = 3; 
        // TODO: Create a constructor that accepts name and memberId
        public User(string name, int memberId)
        {
            _borrowedBooks = new List<string>();
            Name = name;
            MemberId = memberId;
        }

        public void AddBorrowedBook(string bookId, bool available)
        {
            if(available)_borrowedBooks.Add(bookId);
        }

        public void RemoveBorrowedBook(string bookId, bool available)
        {
            if(!available)_borrowedBooks.Remove(bookId);
        }

        public bool HasBook(string bookId) => _borrowedBooks.Contains(bookId);
        public bool CanBorrow() => BorrowedBooksCount < MAX_BORROWED_BOOKS;
    }
}