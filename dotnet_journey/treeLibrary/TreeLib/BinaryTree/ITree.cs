namespace TreeLib.BinaryTree
{
    public interface ITree<T>
    {
        public T GetRootData();
        public int GetHeight();
        public int GetNumbOfNodes();
        public bool IsEmpty();
        public void Clear();
    }
}