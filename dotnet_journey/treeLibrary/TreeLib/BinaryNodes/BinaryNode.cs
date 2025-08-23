namespace TreeLib.BinaryNodes
{
    public class BinaryNode<T> : IBinaryNode<T>
    {
        public T? Data { get; set; }
        public BinaryNode<T>? LeftChild { get; set; }
        public BinaryNode<T>? RightChild { get; set; }

        public BinaryNode(T? newData)
        {
            Data = newData;
        }
        public BinaryNode() : this(default(T)) { }

        public BinaryNode(T newData, BinaryNode<T> lChild, BinaryNode<T> rChild)
        {
            Data = newData;
            LeftChild = lChild;
            RightChild = rChild;
        }

        public bool HasLeftChild()
        {
            return LeftChild != null;
        }
        public bool HasRightChild()
        {
            return RightChild != null;
        }
        public bool IsLeaf()
        {
            return ((LeftChild == null) && (RightChild == null));
        }
        public int GetNumbOfNodes()
        {
            int leftNumbNodes = 0, rightNumbNodes = 0;

            if (LeftChild != null) { leftNumbNodes = LeftChild.GetNumbOfNodes(); }
            if (RightChild != null) { rightNumbNodes = RightChild.GetNumbOfNodes(); }

            return 1 + leftNumbNodes + rightNumbNodes;
        }
        
        public int GetHeight()
        {
            int height = GetHeight(this);
            return height;
        }
        private static int GetHeight(BinaryNode<T>? node)
        {
            int height = 0;

            if (node != null)
            {
                height = 1 + Math.Max(GetHeight(node.LeftChild), GetHeight(node.RightChild));
            }
            return height;
        }
        public BinaryNode<T> Clone()
        {
            BinaryNode<T> newRoot = new(Data);
            if (LeftChild != null) { newRoot.LeftChild = LeftChild.Clone(); }
            if (RightChild != null) { newRoot.RightChild = RightChild.Clone(); }
            return newRoot;
        }
    }
}