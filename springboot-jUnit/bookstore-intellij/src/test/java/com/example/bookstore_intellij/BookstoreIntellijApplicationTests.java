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

import static com.example.bookstore_intellij.TestUtils.*;

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

		// is idOne and idTwo in the database?
		int count_rtn_two = this.jdbcTemplate.query(SQL_TWO_BKS_IDS, new DataClassRowMapper<>(BookStore.class), ID_ONE, ID_TWO).size();

		int fls_rst = this.jdbcTemplate.query(SQL_ONE_BKS_ID, new DataClassRowMapper<>(BookStore.class), NOT_ID).size();

		int findstoneStance_rst = this.jdbcTemplate.query(SQL_FINDSTONE_STANCE, new DataClassRowMapper<>(BookStore.class), INPUT_FINDSTONE_STANCE).size();

		Assertions.assertEquals(2, count_rtn_two);
		Assertions.assertEquals(1, findstoneStance_rst);
		Assertions.assertEquals(1, fls_rst);
		JobExecution jobExecution = this.jobLauncherTestUtils.launchJob();

	}
}
