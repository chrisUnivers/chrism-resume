using TreeLib.BinaryNodes;

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
            nodeA.RightChild = nodeC;
            nodeB.RightChild = nodeD;
            nodeD.LeftChild = nodeE;
            nodeE.RightChild = nodeF;

            ProcessNodes(nodeA);
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