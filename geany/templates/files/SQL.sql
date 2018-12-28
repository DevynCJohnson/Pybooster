CREATE DATABASE XXXdb;


CREATE TABLE tblXXX (
	user_id BIGINT UNSIGNED NOT NULL IDENTITY(0,1) PRIMARY KEY,
	user_name CHAR(63) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL UNIQUE,
	pswd CHAR(63) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	firstname CHAR(63) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
	lastname CHAR(63) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
	user_email CHAR(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL UNIQUE,
	user_date DATETIME NOT NULL,
	user_last_login DATETIME,
	CONSTRAINT min_user_name CHECK (LEN(user_name)>2),
	CONSTRAINT min_pswd CHECK (LEN(pswd)>7)
) TYPE=INNODB;


CREATE TABLE tblXXX (
	post_id BIGINT UNSIGNED NOT NULL IDENTITY(0,1) PRIMARY KEY,
	owner_id BIGINT UNSIGNED NOT NULL,
	title CHAR(31) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	body CHAR(511) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
	postdate DATETIME NOT NULL,
	FOREIGN KEY (owner_id) REFERENCES tblXXX(user_id),
	INDEX userposts (post_id, owner_id),
	CONSTRAINT min_body CHECK (LEN(body)>10)
) TYPE=INNODB;
