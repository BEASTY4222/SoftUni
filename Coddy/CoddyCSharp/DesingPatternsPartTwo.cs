using System;

namespace patternsPartTwo
{
    public class Document
    {
        // TODO: Add a private string field to store content (initialize to empty string)
        private string _content;

        public Document()
        {
            // TODO: Initialize content
            _content = "";
        }

        // TODO: Implement Append method to add text to content
        public void Append(string text)
        {
            // TODO: Add text to the content
            _content += text;
        }

        // TODO: Implement RemoveLast method to remove last count characters
        // If count exceeds content length, clear all content
        public void RemoveLast(int count)
        {
            // TODO: Remove last count characters from content
            if(count >= _content.Length)
            {
                _content = "";
                return;
            }
            _content = _content.Remove(_content.Length - count, count);
        }

        // TODO: Implement GetContent method to return current content
        public string GetContent()
        {
            // TODO: Return the content
            return _content;
        }
    }
    
    // TODO: Define the ICommand interface with an Execute() method
    public interface ICommand
    {
        // TODO: Add the Execute method signature
        void Execute();
    }

    // TODO: Create InsertCommand class that implements ICommand
    // - Constructor takes Document and string text
    // - Execute() should append text to document and print "Inserted: {text}"
    public class InsertCommand : ICommand
    {
        private Document _document;
        private string _text;

        public InsertCommand(Document document, string text)
        {
            _document = document;
            _text = text;
        }

        public void Execute()
        {
            // TODO: Implement Execute - append text and print message
            _document.Append(_text);
            Console.WriteLine($"Inserted: {_text}");
        }
    }

    // TODO: Create DeleteCommand class that implements ICommand
    // - Constructor takes Document and int count
    // - Execute() should remove last count characters and print "Deleted: {count} characters"
    public class DeleteCommand : ICommand
    {
        private Document _document;
        private int _count;

        public DeleteCommand(Document document, int count)
        {
            _document = document;
            _count = count;
        }

        public void Execute()
        {
            // TODO: Implement Execute - remove characters and print message
            _document.RemoveLast(_count);
            Console.WriteLine($"Deleted: {_count} characters");
        }
    }


    // This represents an existing library you can't modify
    // TODO: Create a LegacyAudioPlayer class with a PlayMp3 method
    // The method should take a filename and return "Playing MP3: {filename}"
    
    public class LegacyAudioPlayer
    {
        // TODO: Implement the PlayMp3 method
        public string PlayMp3(string filename) => $"Playing MP3: {filename}";
    }

    // TODO: Define the IMediaPlayer interface with a Play method
    // The Play method should take a filename and return a string
    
    public interface IMediaPlayer
    {
        // TODO: Define the Play method signature
        string Play(string filename);
    }
    
    // TODO: Create the MediaPlayerAdapter class that implements IMediaPlayer
    // The adapter should:
    // 1. Accept a LegacyAudioPlayer in its constructor
    // 2. Store the legacy player as a private field
    // 3. Implement Play by delegating to the legacy player's PlayMp3 method
    
    public class MediaPlayerAdapter : IMediaPlayer
    {
        // TODO: Add private field for LegacyAudioPlayer
        private LegacyAudioPlayer _legacyAudioPlayer;
        // TODO: Implement constructor that accepts LegacyAudioPlayer
        public MediaPlayerAdapter(LegacyAudioPlayer audioPlayer)
        {
            _legacyAudioPlayer = audioPlayer;
        }
        // TODO: Implement the Play method
        public string Play(string filename) => _legacyAudioPlayer.PlayMp3(filename);
        
    }


    // TODO: Define the IPizza interface with two methods:
    // - GetDescription() returning a string
    // - GetPrice() returning a decimal
    public interface IPizza
    {
        string GetDescription();
        decimal GetPrice();
    }
    // TODO: Create a PlainPizza class that implements IPizza
    // - GetDescription() should return "Pizza"
    // - GetPrice() should return 8.00m
    public class PlainPizza : IPizza
    {
        public string GetDescription() => "Pizza";
        public decimal GetPrice() => 8.00m;
    }


    // TODO: Create an abstract ToppingDecorator class that:
    // - Implements IPizza
    // - Has a protected field to hold the wrapped pizza
    // - Takes an IPizza in its constructor
    // - Has virtual methods that delegate to the wrapped pizza
    public abstract class ToppingDecorator : IPizza{
        protected IPizza _pizza;
        public ToppingDecorator(IPizza pizza) => _pizza = pizza;
        public virtual string GetDescription() => _pizza.GetDescription();
        public virtual decimal GetPrice() => _pizza.GetPrice(); 
    }
    // TODO: Create CheeseTopping class that extends ToppingDecorator
    // - Appends ", Cheese" to description
    // - Adds 1.50m to price
    public class ChesseTopping : ToppingDecorator
    {
        public ChesseTopping(IPizza pizza) : base(pizza){}
        public override string GetDescription() => base.GetDescription() + ", Cheese";
        public override decimal GetPrice() => base.GetPrice() + 1.50m;
    }
    // TODO: Create PepperoniTopping class that extends ToppingDecorator
    // - Appends ", Pepperoni" to description
    // - Adds 2.00m to price
    public class PepperoniTopping : ToppingDecorator
    {
        public PepperoniTopping(IPizza pizza) : base(pizza){}
        public override string GetDescription() => base.GetDescription() + ", Pepperoni";
        public override decimal GetPrice() => base.GetPrice() + 2.00m;
    }
    // TODO: Create MushroomTopping class that extends ToppingDecorator
    // - Appends ", Mushrooms" to description
    // - Adds 1.25m to price
    public class MushroomTopping : ToppingDecorator
    {
        public MushroomTopping(IPizza pizza) : base(pizza){}
        public override string GetDescription() => base.GetDescription() + ", Mushrooms";
        public override decimal GetPrice() => base.GetPrice() + 1.25m;
    }
}