using Humanizer;

namespace Simple_Select
{
    internal class Transaction
    {
        public decimal Amount { get; }

        public string AmountForHumans
        {
            get
            {
                return ((int)Amount).ToWords();
                // return ((int)Amount);
            }
        }
        public DateTime Date { get; }
        public string Notes { get; }

        public Transaction(decimal amount, DateTime date, string note)
        {
            this.Amount = amount; this.Date = date; this.Notes = note;
        }
    }
}
