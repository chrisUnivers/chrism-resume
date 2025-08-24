using TreeLib.BinaryNodes;

namespace TreeLib.BinaryTree
{
    public interface ITreeEnumerables<T>
    {
        public IEnumerator<T> GetInorderEnumerator();
    }
}