package com.example.bookstore_intellij;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.batch.core.BatchStatus;
import org.springframework.batch.core.JobExecution;
import org.springframework.batch.core.JobExecutionListener;
import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;

@Component
public class JobCompletionNotificationListener implements JobExecutionListener{

    private static final Logger log = LoggerFactory.getLogger(JobCompletionNotificationListener.class);


    private final JdbcTemplate jdbcTemplate;

    public JobCompletionNotificationListener(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    @Override
    public void afterJob(JobExecution jobExecution) {
        if (jobExecution.getStatus() == BatchStatus.COMPLETED) {
            jdbcTemplate
                    .query("SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores", new DataClassRowMapper<>(BookStore.class))
                    .forEach(bookstore -> log.info("database book: .", bookstore));
        } // bks_name bks_address bks_id bks_collection
    }
}
