using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Nht.NetHotel.Domain.DomainObjects
{
    public class Booking
    {
        public int BookingId { get; set; }
        public DateTime CheckIn { get; set; }
        public DateTime CheckOut { get; set; }
        public Guest? Guest { get; set; }
        public Hotel? Hotel { get; set; }
        public Amenity? Amenity { get; set; }
    }
}
