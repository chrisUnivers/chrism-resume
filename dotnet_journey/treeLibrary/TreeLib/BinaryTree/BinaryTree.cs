using System.Collections;
using TreeLib.BinaryNodes;
using TreeLib.StackLibrary;

namespace TreeLib.BinaryTree
{
    public class BinaryTree<T> : IBinaryTree<T>
    {
        private BinaryNode<T>? Root { set; get; }
        public BinaryTree() { Root = null; }

        public BinaryTree(T rootData) => Root = new(rootData);
        public BinaryTree(T rootData, BinaryTree<T>? leftTree, BinaryTree<T>? rightTree)
        {

            InitTree(rootData, leftTree, rightTree);
        }

        public int SetTree(T rootData, IBinaryTree<T> leftTree, IBinaryTree<T> rightTree)
        {
            if ((leftTree is BinaryTree<T> nwLeftTree) && (rightTree is BinaryTree<T> nwRightTree))
            {
                InitTree(rootData, nwLeftTree, nwRightTree);
                return 1;
            }
            return -1;
        }
        private void InitTree(T rootData, BinaryTree<T>? leftTree, BinaryTree<T>? rightTree)
        {
            Root = new BinaryNode<T>(rootData);

            if ((leftTree != null) && !leftTree.IsEmpty())
            {
                Root.LeftChild = leftTree.Root;
            }
            if ((rightTree != null) && !rightTree.IsEmpty())
            {
                if (rightTree != leftTree)
                {
                    Root.RightChild = rightTree.Root;
                }
                else
                {
                    if (rightTree.Root != null) { Root.RightChild = rightTree.Root.Clone(); }
                }
            }
            if ((leftTree != null) && (leftTree != this)) { leftTree.Clear(); }

            if ((rightTree != null) && (rightTree != this)) { rightTree.Clear(); }
        }

        public T GetRootData()
        {
            if (Root.Data != null)
                return Root.Data;
            else
                throw new MyEmptyTreeExpection();
        }
        public void SetRootData(T rootData)
        {
            Root.Data = rootData;
        }

        public bool IsEmpty() { return Root.Data == null; }

        public void Clear() => Root = null;

        protected void SetRootNode(BinaryNode<T> rootNode) => Root = rootNode;

        protected BinaryNode<T> GetRootNode()
        {
            return Root;
        }

        public int GetHeight()
        {
            int height = 0;
            if (Root != null)
                height = Root.GetHeight();
            return height;
        }

        public int GetNumbOfNodes()
        {
            int numberOfNodes = 0;
            if (Root != null)
                numberOfNodes = Root.GetNumbOfNodes();
            return numberOfNodes;
        }

        public IEnumerator<T> GetInorderEnumerator()
        {
            return new InorderEnumerator(Root!);
        }

        private class InorderEnumerator : IEnumerator<T>
        {
            private IStack<BinaryNode<T>> rootStack;
            private BinaryNode<T> itrNode;
            private BinaryNode<T> CurrentNode_;
            public InorderEnumerator(BinaryNode<T> root)
            {
                rootStack = new LinkedStack<BinaryNode<T>>();
                CurrentNode_ = root;
                itrNode = CurrentNode_;
            }
            public T Current
            {
                get
                {
                    return CurrentNode_.Data!;
                }
            }
            private bool HasNext() { return !rootStack.IsEmpty() || (CurrentNode_ != null); }
            object IEnumerator.Current => this.itrNode;
            public bool MoveNext()
            {
                BinaryNode<T>? nextNode = null;

                bool mvNext = false;

                while (itrNode != null)
                {
                    rootStack.Push(itrNode);
                    itrNode = itrNode.LeftChild!;
                }
                
                if (!(rootStack.IsEmpty()))
                {
                    nextNode = rootStack.Pop();
                    CurrentNode_ = nextNode.Clone();
                    itrNode = nextNode.RightChild!;
                    mvNext = true;
                }
                else
                    throw new MyEmptyStackException();
                return mvNext;
            }
            public void Reset()
            {
                rootStack.Clear();
            }

            public void Dispose() {}
        }
    }
}