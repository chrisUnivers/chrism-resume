namespace TreeLib.StackLibrary
{
    public interface IStack<T>
    {
        public T Pop();
        public T Peek();
        public bool IsEmpty();
        public void Push(T entry);
        public void Clear();
    }
}