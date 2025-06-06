package com.example.webflux_batch_bookstore;

import org.springframework.http.MediaType;
import org.springframework.stereotype.Component;
import org.springframework.web.reactive.function.client.WebClient;
import reactor.core.publisher.Mono;


@Component
public class StoryClient {
    private final WebClient client;

    public StoryClient(WebClient.Builder builder) {
        this.client = builder.baseUrl("http://localhost:8080").build();
    }

    public Mono<String> getStory() {

        return this.client.get().uri("/story").accept(MediaType.APPLICATION_JSON).retrieve().bodyToMono(Story.class).map(Story::getBkStory);
    }


}
