namespace TreeLib.BinaryTree
{
    public class MyEmptyTreeExpection : Exception
    {
        public MyEmptyTreeExpection() : base("Can not perform operation on an empty tree") {}

        public MyEmptyTreeExpection(string message) : base(message) {}
    }
}