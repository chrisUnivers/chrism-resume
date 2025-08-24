using TreeLib.BinaryNodes;
using TreeLib.BinaryTree;
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
            BinaryTree<string> treeL = new(linkedNodeds[6]);
            BinaryTree<string> treeR = new(linkedNodeds[4]);
            BinaryTree<string> root = new();
            int tree_set = root.SetTree(linkedNodeds[0], treeL, treeR);

            IEnumerator<string> treeInOdrItr = root.GetInorderEnumerator();

            try
            {
                while (treeInOdrItr.MoveNext())
                {
                    Console.WriteLine($"Next Data value is: {treeInOdrItr.Current}");
                }
            }
            catch (MyEmptyStackException e)
            {
                Console.WriteLine(e.Message);
            }       
            
        }
        public static void ProcessNodes(BinaryNode<string> node)
        {
            if (node != null) {
                Console.WriteLine($"Node is: {node.Data}");
                ProcessNodes(node.LeftChild!);
                ProcessNodes(node.RightChild!); 
            }
        }
            
    }

}