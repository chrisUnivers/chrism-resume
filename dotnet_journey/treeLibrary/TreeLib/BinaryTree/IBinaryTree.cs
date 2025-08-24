namespace TreeLib.BinaryTree
{
    public interface IBinaryTree<T> : ITree<T>, ITreeEnumerables<T>
    {
        public int SetTree(T rootData, IBinaryTree<T> leftTree, IBinaryTree<T> rightTree);
        public void SetRootData(T rootData);
    }
}