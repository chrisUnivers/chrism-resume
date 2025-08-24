namespace TreeLib.StackLibrary
{
    public class MyEmptyStackException : Exception
    {
        public MyEmptyStackException() : base("Trying to access an empty stack") { }
        
        public MyEmptyStackException(string message) : base(message) {}
    }
}