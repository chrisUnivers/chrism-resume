using TreeLib.BinaryNodes;
using TreeLib.BinaryTree;

namespace TreeLib.HandleInputs
{
    public class CreateTreeFromFile<T> : ICreateTreeFromFile<T>
    {
        private LinkedList<string[]> ListFileInputs_ { set; get; }
        private readonly StreamReader? myStream_;

        private LinkedList<IBinaryTree<string>> ListInitTree_ { set; get; }
        private int CanInitTree { set; get; }

        public CreateTreeFromFile() : this(null) { }
        public CreateTreeFromFile(StreamReader? rdr)
        {
            myStream_ = rdr;
            
            ListInitTree_ = new LinkedList<IBinaryTree<string>>();
        }

        public int ProcessFile()
        {

            try
            {
                ListFileInputs_ = new LinkedList<string[]>();
                string? line;
                while ((line = myStream_!.ReadLine()) != null)
                {
                    ListFileInputs_.AddLast(line.Split(" "));
                }
                CanInitTree = 1;
            }
            catch (IOException e)
            {
                Console.WriteLine($"CreateTreeFromFile could not read the file: {e.Message}");
            }
            return 0;
        }

        public IBinaryTree<string> CreateTree()
        {
            string vInput = "_";
            while (ListFileInputs_.Count > 0)
            {
                string[] treeInfo = ListFileInputs_.Last();
                IBinaryTree<string> tree = new BinaryTree<string>(treeInfo[0]);
                IBinaryTree<string> nlTree = treeInfo[1] == vInput ? null! : ListInitTree_.Find(new BinaryTree<string>(treeInfo[1]))!.Value;
                IBinaryTree<string> nrTree = treeInfo[2] == vInput ? null! : ListInitTree_.Find(new BinaryTree<string>(treeInfo[2]))!.Value;

                int setTree = tree.SetTree(tree.GetRootData(), treeInfo[1] == vInput ? null! : nlTree, treeInfo[2] == vInput ? null! : nrTree);

                ListInitTree_.AddLast(tree);
                ListFileInputs_.RemoveLast();
                if (ListInitTree_.Count > 0 && (ListInitTree_.First().GetRootData() == null)) { ListInitTree_.RemoveFirst(); }
                if (ListInitTree_.Count > 0 && (ListInitTree_.First().GetRootData() == null)) { ListInitTree_.RemoveFirst(); }
            }
            
            return ListInitTree_.Last();
        }
    }
}