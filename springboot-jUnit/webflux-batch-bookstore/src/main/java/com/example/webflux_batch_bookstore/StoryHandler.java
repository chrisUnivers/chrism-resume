package com.example.webflux_batch_bookstore;


import org.springframework.batch.core.Job;
import org.springframework.batch.core.JobExecution;
import org.springframework.batch.core.JobParameters;
import org.springframework.batch.core.JobParametersBuilder;
import org.springframework.batch.core.launch.JobLauncher;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.MediaType;
import org.springframework.stereotype.Component;
import org.springframework.web.reactive.function.BodyInserters;
import org.springframework.web.reactive.function.server.ServerRequest;
import org.springframework.web.reactive.function.server.ServerResponse;
import reactor.core.publisher.Mono;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import static com.example.webflux_batch_bookstore.UtilsConstants.*;

@Component
public class StoryHandler {
    @Autowired
    private JobLauncher jobLauncher;

    @Autowired
    private Job importBookStoreJob;

    public Mono<ServerResponse> bkChapt(ServerRequest request) {
        return ServerResponse.ok().contentType(MediaType.APPLICATION_JSON).body(BodyInserters.fromValue(new Story("The beginning of a story!")));
    }

    public Mono<ServerResponse> bkBatchJob(ServerRequest request) {
        JobParametersBuilder jobParametersBuilder = new JobParametersBuilder().addString("JobID", String.valueOf(System.currentTimeMillis()));
        JobParameters params = jobParametersBuilder.toJobParameters();

        Mono<TheBook> reqString = request.bodyToMono(TheBook.class);
        try {
//            BufferedWriter writer = new BufferedWriter(new FileWriter(FILE_FOR_SUBMITTED_BOOKS, true));
//            writer.write(bookWebSubmit);
//            writer.close();
            JobExecution jobExecution = jobLauncher.run(this.importBookStoreJob, params);
            return ServerResponse.ok().contentType(MediaType.APPLICATION_JSON).body(BodyInserters.fromValue(new Story("New book is being created")));

        } catch (Exception e) {
            return ServerResponse.badRequest().contentType(MediaType.APPLICATION_JSON).body(BodyInserters.fromValue(new Story("bad request" + e.getMessage())));
        }
    }
}

