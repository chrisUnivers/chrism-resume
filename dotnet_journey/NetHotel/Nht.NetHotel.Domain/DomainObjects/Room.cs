namespace Nht.NetHotel.Domain.DomainObjects
{
    public class Room
    {
        public int RoomNumber { get; set; }
        public int HotelId { get; set; }
        public string HotelName { get; set; }
        public Amenity RoomAmenity { get; set; }
    }
}
