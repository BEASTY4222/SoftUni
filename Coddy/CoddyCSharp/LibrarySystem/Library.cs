using System.Runtime.CompilerServices;

namespace LibrarySystem
{
    public class Library
    {
        private List<User> _users;
        public List<User> Users {get => _users;}
        private List<Book> _books; 
        // TODO: Create auto-implemented property for Name (string)
        public string Name {get; set;}
        // TODO: Create a constructor that sets the Name
        public Library(string name)
        {
            _users = new List<User>();
            _books = new List<Book>();
            Name = name;
        }
        // TODO: Create a GetInfo() method that returns "{Name} Library System Initialized"
        public string GetInfo() => $"{Name} Library System Initialized";

        public void AddBook(Book book) => _books.Add(book);
        public void RegisterUser(User user) => _users.Add(user);
        public Book GetBookById(string id)
        {
            foreach(Book book in _books)
            {
                if(book.Id == id)
                    return book;
            }
            return null;
        }

        public User GetUserById(int memberId)
        {
            foreach(User user in _users)
            {
                if(user.MemberId == memberId)
                    return user;
            }
            return null;
        }
    

        public string BorrowBook(string bookId, int memberId)
        {
            Book curBook = GetBookById(bookId);
            User curUser = GetUserById(memberId);

            if(curBook == null)return "Book not found";
            
            if (curUser == null) return "User not found";
            

            if (!curBook.IsAvailable) return $"{curBook.Title} is not available";
            

            if (!curUser.CanBorrow()) return $"{curUser.Name} has reached the borrowing limit";
            

            curUser.AddBorrowedBook(curBook.Id,curBook.IsAvailable);
            curBook.Borrow();
            return $"{curUser.Name} borrowed {curBook.Title}";
        }

        public string ReturnBook(string bookId, int memberId)
        {
            Book curBook = GetBookById(bookId);
            User curUser = GetUserById(memberId);

            if(curBook == null)return "Book not found";
            
            if (curUser == null) return "User not found";
            
            if(!curUser.HasBook(bookId)) return $"{curUser.Name} did not borrow {curBook.Title}"; 

            curUser.RemoveBorrowedBook(curBook.Id,curBook.IsAvailable);
            curBook.Return();
            return $"{curUser.Name} returned {curBook.Title}";
        }
    }
}
