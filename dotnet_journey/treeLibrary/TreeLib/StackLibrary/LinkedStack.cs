using System.Diagnostics.CodeAnalysis;

namespace TreeLib.StackLibrary
{

    public class LinkedStack<T>(T? newT) : IStack<T>
    {
        private NodeStack<T>? RootNode_ { set; get; } = new NodeStack<T>(newT!);
        public LinkedStack() : this(default) { }
        public void Push(T newData) => RootNode_ = new NodeStack<T>(newData, RootNode_);
        public T Pop()
        {
            if (!IsEmpty())
            {
                T data = Peek();
                RootNode_ = RootNode_!.GetNextNode();
                return data;
            }
            else
            {
                throw new MyEmptyStackException();
            }

        }
        public T Peek()
        {
            if (!IsEmpty())
            {
                return RootNode_!.GetData();
            }else
            {
                throw new MyEmptyStackException();
            }
        }
        public bool IsEmpty()
        {
            return RootNode_!.GetData() == null;
        }
        public void Clear()
        {
            RootNode_ = null;
        }
        [SuppressMessage("Compiler", "CS0693", Justification = "Same type is used")]
        private class NodeStack<T>
        {
            private T Data { set; get; }
            private NodeStack<T>? Next { set; get; }
            public NodeStack(T data) : this(data, null) { }
            public NodeStack(T data, NodeStack<T>? nextNode)
            {
                Data = data;
                Next = nextNode;
            }
            public T GetData()
            {
                return Data;
            }
            public NodeStack<T> GetNextNode()
            {
                return Next!;
            }
        }
    }
}
