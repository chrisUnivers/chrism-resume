namespace TreeLib.BinaryTree
{
    public class MyEmptyTreeException : Exception
    {
        public MyEmptyTreeException() : base("Can not perform operation on an empty tree") {}

        public MyEmptyTreeException(string message) : base(message) {}
    }
}