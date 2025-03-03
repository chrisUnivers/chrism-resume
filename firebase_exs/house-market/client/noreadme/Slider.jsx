<Swiper slidesPerView={1} pagination={{clickable: true}}>
                {listings.map(({data, id}) => (
                    <SwiperSlide key={id} onClick={() => navigate(`/category/${data.type}/${id}`)}>
                        <div style ={{background: `url(${data.imgUrls[0]}) center no-repeat`, backgroundSize: "cover",}} className="swiperSlideDiv"></div>
                    </SwiperSlide>
                ))}
            </Swiper>