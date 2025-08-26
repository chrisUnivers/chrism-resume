using TreeLib.BinaryTree;

namespace TreeLib.HandleInputs
{
    public interface ICreateTreeFromFile<T>
    {
        public int ProcessFile();
        public IBinaryTree<string> CreateTree();
    }
}