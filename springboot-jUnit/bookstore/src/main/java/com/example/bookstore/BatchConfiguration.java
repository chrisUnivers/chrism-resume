package com.example.bookstore;

import javax.sql.DataSource;

import org.springframework.batch.core.Job;
import org.springframework.batch.core.Step;
import org.springframework.batch.core.job.builder.JobBuilder;
import org.springframework.batch.core.repository.JobRepository;
import org.springframework.batch.core.step.builder.StepBuilder;
import org.springframework.batch.item.database.JdbcBatchItemWriter;
import org.springframework.batch.item.database.builder.JdbcBatchItemWriterBuilder;
import org.springframework.batch.item.file.FlatFileItemReader;
import org.springframework.batch.item.file.builder.FlatFileItemReaderBuilder;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.io.ClassPathResource;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;

@Configuration
public class BatchConfiguration {
    
    @Bean
    public FlatFileItemReader<BookStore> reader() {
        return new FlatFileItemReaderBuilder<BookStore>().name("bookstoreItemReader").resource(new ClassPathResource("bookstore-data.csv")).delimited().names("bksName", "bksId", "bksAddress", "bksCollection").targetType(BookStore.class).build();
    }

    @Bean
    public BookStoreItemProcessor processor() {
        return new BookStoreItemProcessor();
    }

    @Bean
    public JdbcBatchItemWriter<BookStore> writer(DataSource dataSource) {
        // bksName bksAddress
        return new JdbcBatchItemWriterBuilder<BookStore>()
            .sql("INSERT INTO bookstores (bks_name, bks_id, bks_address, bks_collection) VALUES (:bksName, :bksId, :bksAddress, :bksCollection)")
            .dataSource(dataSource)
            .beanMapped()
            .build();
    }
    
    @Bean
    public Job importBookStoreJob(JobRepository jobRepository, Step step1, JobCompletionNotificationListener listener) {
        return new JobBuilder("importBookStoreJob", jobRepository).listener(listener).start(step1)
        .build();
    }

    @Bean
    public Step step1(JobRepository jobRepository, DataSourceTransactionManager transactionManager, FlatFileItemReader<BookStore> reader, BookStoreItemProcessor processor, JdbcBatchItemWriter<BookStore> writer) {
        return new StepBuilder("step1", jobRepository)
            .<BookStore, BookStore>chunk(3, transactionManager)
            .reader(reader)
            .processor(processor)
            .writer(writer)
            .build();
    }
}
