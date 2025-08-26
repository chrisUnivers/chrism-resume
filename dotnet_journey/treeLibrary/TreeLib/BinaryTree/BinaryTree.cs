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

            InitTree(rootData, (BinaryTree<T>)leftTree, (BinaryTree<T>)rightTree);
            return 1;
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
            if (!IsEmpty())
                return Root!.Data!;
            return default!;
        }
        public void SetRootData(T rootData)
        {
            Root!.Data = rootData;
        }

        public bool IsEmpty() { return Root == null; }

        public void Clear() => Root = null;

        protected void SetRootNode(BinaryNode<T> rootNode) => Root = rootNode;

        protected BinaryNode<T> GetRootNode()
        {
            return Root!;
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

        public override bool Equals(object? obj)
        {
            if ((obj == null) || GetType() != obj.GetType())
                return false;
            BinaryTree<T>? othr = (BinaryTree<T>)obj;

            if (Root != null)
                return Root!.Data!.Equals(othr.Root!.Data);
            return false;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        public IEnumerator<T> GetInorderEnumerator()
        {
            return new InorderEnumerator(Root!);
        }

        public IEnumerator<T> GetPreorderEnumerator()
        {
            return new PreorderEnumerator(Root!);
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

            public void Dispose() { }
        }
        private class PreorderEnumerator : IEnumerator<T>
        {
            private IStack<BinaryNode<T>> rootStack;
            private BinaryNode<T> itrNode;
            private BinaryNode<T> CurrentNode_;
            public PreorderEnumerator(BinaryNode<T> root)
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
            object IEnumerator.Current => this.itrNode;
            public bool MoveNext()
            {
                BinaryNode<T>? nextNode = null;

                bool mvNext = false;

                if (itrNode != null)
                {
                    rootStack.Push(itrNode);

                }

                if (!(rootStack.IsEmpty()))
                {
                    nextNode = rootStack.Pop();
                    CurrentNode_ = nextNode.Clone();
                    if (nextNode.RightChild != null)
                        rootStack.Push(nextNode.RightChild);
                    itrNode = nextNode.LeftChild!;
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

            public void Dispose() { }
        }
    }
}