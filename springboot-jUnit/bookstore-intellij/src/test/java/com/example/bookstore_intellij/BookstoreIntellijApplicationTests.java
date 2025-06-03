package com.example.bookstore_intellij;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.batch.core.Job;
import org.springframework.batch.core.JobExecution;
import org.springframework.batch.test.JobLauncherTestUtils;
import org.springframework.batch.test.JobRepositoryTestUtils;
import org.springframework.batch.test.context.SpringBatchTest;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.jdbc.core.DataClassRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;


import javax.sql.DataSource;



@SpringBootTest
@SpringBatchTest
class BookstoreIntellijApplicationTests {

	@Autowired
	private JobLauncherTestUtils jobLauncherTestUtils;

	private JdbcTemplate jdbcTemplate;

	@Autowired
	private JobRepositoryTestUtils jobRepositoryTestUtils;

	private static final Logger log = LoggerFactory.getLogger(BookstoreIntellijApplicationTests.class);

	@Autowired
	public void setDatasource(DataSource datasource) {
		this.jdbcTemplate = new JdbcTemplate(datasource);
	}

	@Test
	public void testUpdateDatabaseFromSubmittedFile(@Autowired Job job) throws Exception {
		this.jobLauncherTestUtils.setJob(job);
//		this.jdbcTemplate.query("SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores", new DataClassRowMapper<>(BookStore.class)).forEach(bookstore -> log.info("Test bookstores: <{}>", bookstore));

		String sqlStr = "SELECT bks_name, bks_address, bks_id, bks_collection FROM bookstores WHERE bks_id = 'IDONE'";

		int count_sz = this.jdbcTemplate.query(sqlStr, new DataClassRowMapper<>(BookStore.class)).size();


		JobExecution jobExecution = this.jobLauncherTestUtils.launchJob();

		Assertions.assertEquals(1, count_sz);
	}
}
