package com.example.webflux_batch_bookstore;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.MediaType;
import org.springframework.web.reactive.function.server.RouterFunction;
import org.springframework.web.reactive.function.server.RouterFunctions;
import org.springframework.web.reactive.function.server.ServerResponse;

import static org.springframework.web.reactive.function.server.RequestPredicates.GET;
import static org.springframework.web.reactive.function.server.RequestPredicates.accept;

@Configuration(proxyBeanMethods = false)
public class StoryRouter {

    @Bean
    public RouterFunction<ServerResponse> route(StoryHandler storyHandler) {
        RouterFunction<ServerResponse> route = RouterFunctions.route().GET("/story", accept(MediaType.APPLICATION_JSON), storyHandler::bkChapt).GET("/story/batch", accept(MediaType.APPLICATION_JSON), storyHandler::bkBatchJob).build();
        return route;
    }
}
