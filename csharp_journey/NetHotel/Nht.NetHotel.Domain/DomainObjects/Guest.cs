namespace Nht.NetHotel.Domain.DomainObjects
{
    public class Guest
    {
        public int GuestId { get; set; }
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public int Age { get; set; }
        public string email { get; set; }
        public string phoneNum { get; set; }
        public Hotel GuestHotel { get; set; }
    }
}
