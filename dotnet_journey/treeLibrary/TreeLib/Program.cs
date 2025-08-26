using TreeLib.BinaryNodes;
using TreeLib.BinaryTree;
using TreeLib.HandleInputs;
using TreeLib.StackLibrary;

namespace TreeLib
{
    public class Program
    {
        public static void Main()
        {
            string[] linkedNodeds = ["A", "B", "C", "D", "E", "F", "G"];
            BinaryNode<string> nodeA = new(linkedNodeds[0]);
            BinaryNode<string> nodeB = new(linkedNodeds[1]);
            BinaryNode<string> nodeC = new(linkedNodeds[2]);
            BinaryNode<string> nodeD = new(linkedNodeds[3]);
            BinaryNode<string> nodeE = new(linkedNodeds[4]);
            BinaryNode<string> nodeF = new(linkedNodeds[5]);
            nodeA.LeftChild = nodeB;
            nodeB.LeftChild = nodeE;
            nodeA.RightChild = nodeC;

            nodeB.RightChild = nodeD;
            nodeC.LeftChild = nodeF;

            ProcessNodes(nodeA);
            BinaryTree<string> treeH = new("H");
            BinaryTree<string> treeG = new("G");
            BinaryTree<string> treeD = new("D");
            BinaryTree<string> treeB = new("B");
            BinaryTree<string> treeC = new("C");
            BinaryTree<string> treeF = new("F");
            BinaryTree<string> treeE = new("E");
            BinaryTree<string> root = new();

            int setF = treeF.SetTree(treeF.GetRootData(), null!, treeG);
            int setC = treeC.SetTree(treeC.GetRootData(), treeF, treeH);

            int setB = treeB.SetTree(treeB.GetRootData(), treeD, treeE);
            int tree_set = root.SetTree("A", treeB, treeC);

            IEnumerator<string> treeInOdrItr = root.GetInorderEnumerator();
            IEnumerator<string> treePreOdrItr = root.GetPreorderEnumerator();

            GetEnumerator(treeInOdrItr, "Inorder");
            GetEnumerator(treePreOdrItr, "Preorder");

            int readFile = ProcessInputFile("./Inputs/treeInputs.txt");
        }
        public static void ProcessNodes(BinaryNode<string> node)
        {
            if (node != null)
            {
                Console.WriteLine($"Node is: {node.Data}");
                ProcessNodes(node.LeftChild!);
                ProcessNodes(node.RightChild!);
            }
        }

        public static void GetEnumerator(IEnumerator<string> itr, string itrName)
        {
            try
            {
                Console.WriteLine($"Enumerator: {itrName}");
                while (itr.MoveNext())
                {
                    Console.WriteLine($"Next Data value is: {itr.Current}");
                }
            }
            catch (MyEmptyStackException e)
            {
                Console.WriteLine(e.Message);
            }
        }
        public static int ProcessInputFile(string filepath)
        {
            Console.WriteLine("Processing File Input!");
            using (StreamReader reader = new(filepath))
            {
                CreateTreeFromFile<string> treeFile = new(reader);
                treeFile.ProcessFile();
                IBinaryTree<string> root = treeFile.CreateTree();
                IEnumerator<string> treePreOdrItr = root.GetPreorderEnumerator();
                GetEnumerator(treePreOdrItr, "PreOrdr");
            }
            return 0;
        } 
    }
}
