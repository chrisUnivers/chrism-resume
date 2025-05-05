// See https://aka.ms/new-console-template for more information

namespace StephenToubLINQ
{
    class Program
    {
        static void Main(string[] args)
        {
            //var account = new BanksOnThe("Chris", 12);
            //Console.WriteLine($"Account {account.Number} was created for {account.Owner} with {account.Balance}.");

            //Console.WriteLine(gettingStarted());

            //foreach (int i in getValues())
            //    Console.WriteLine(i);
            onEnumerable();
            tryExamples();
        }

        static public string gettingStarted()
        {
            var toStartOrNot = "Get Started";

            return toStartOrNot;

        }

        static IEnumerable<int> getValues()
        {
            yield return 1;
            yield return 2;
            yield return 3;
        }

        static void onEnumerable()
        {
            IEnumerable<int> e = getValues();
            using IEnumerator<int> enumerator = e.GetEnumerator();

            while (enumerator.MoveNext())
            {
                int i = enumerator.Current;
                Console.WriteLine(i);
            }

        }

        class Person
        {
            public string? Name { get; set; }
        }
        static void tryExamples()
        {
            // Example One.
            IEnumerable<Person> people = new List<Person>
            {
                new Person { Name = "Jim" },
                new Person { Name = "Alice" },
                new Person { Name = "Bob" }
            };

            IEnumerable<string> names = people.Select(p => p.Name!);

            using IEnumerator<string> enumerator = names.GetEnumerator();

            while (enumerator.MoveNext())
            {
                string i = enumerator.Current;
                Console.WriteLine("Hello " + i);
            }
        }
    }
}