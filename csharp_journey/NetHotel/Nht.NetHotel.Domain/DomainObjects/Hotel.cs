using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nht.NetHotel.Domain.DomainObjects
{
    public class Hotel
    {
        public int HotelId { get; set; }
        public string HotelName { get; set; }
        public int NumAvailableRooms { get; set; }
        public string phoneNum { get; set; }
        public List<Room> HotelRoomsList { get; set; }
        public List<Amenity> HotelAmenityList { get; set; }
    }
}
