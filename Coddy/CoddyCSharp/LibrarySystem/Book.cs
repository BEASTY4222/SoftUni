namespace LibrarySystem
{
    public class Book
    {
        // TODO: Create auto-implemented property for Title (string)
        public string Title{get; set;}
        // TODO: Create auto-implemented property for Author (string)
        public string Author {get; set;}
        // TODO: Create auto-implemented property for IsAvailable (bool, default to true)
        public bool IsAvailable {get; set;}
        public string Id {get; set;} 
        // TODO: Create a constructor that takes title and author as parameters
        public Book(string title, string author, bool available, string id){
            Title = title;
            Author = author;
            IsAvailable = available;
            Id = id;
        }

        public void Borrow()
        {
            
            IsAvailable = false;
               
        }
        public void Return()
        {
            
            IsAvailable = true;
            
        }
    }
}