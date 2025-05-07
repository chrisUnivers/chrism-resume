using Microsoft.EntityFrameworkCore;
using Nht.NetHotel.Domain.DomainObjects;

namespace Nht.NetHotel.Domain.Database;

public class ApplicationContext : DbContext
{
    public ApplicationContext(DbContextOptions<ApplicationContext> options) : base(options)
    {
    }

    public DbSet<Booking>? Bookings { get; set; }
    public DbSet<Guest>? Guests { get; set; }
    public DbSet<Amenity>? Amenities { get; set; }
    public DbSet<Hotel>? Hotels { get; set; }
}
