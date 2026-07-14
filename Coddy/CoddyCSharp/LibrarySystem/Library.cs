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
    }
}