namespace TreeLib.BinaryNodes{

    public interface IBinaryNode<T>
    {
        T? Data { get; set; }
        public bool HasLeftChild();
        public bool HasRightChild();
        public bool IsLeaf();
        public int GetNumbOfNodes();
        public int GetHeight();
        public BinaryNode<T> Clone();
    }
}