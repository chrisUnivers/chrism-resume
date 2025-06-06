package com.example.webflux_batch_bookstore;

import org.springframework.batch.core.configuration.annotation.EnableBatchProcessing;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
public class WebfluxBatchBookstoreApplication {

	public static void main(String[] args) {

		ConfigurableApplicationContext context = SpringApplication.run(WebfluxBatchBookstoreApplication.class, args);
		StoryClient storyClient = context.getBean(StoryClient.class);
		System.out.println("The story: " + storyClient.getStory().block());
	}

}
