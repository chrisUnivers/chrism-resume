DROP TABLE bookstores IF EXISTS

CREATE TABLE bookstores (
    bks_id BIGINT IDENTITY NOT NULL PRIMARY KEY,
    bks_name VARCHAR(30),
    bks_address VARCHAR(40),
    bks_collection VARCHAR(300)
);