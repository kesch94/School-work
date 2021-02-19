drop database c20antka;
create database c20antka;
use c20antka;

CREATE TABLE skidåkare (
namn    VARCHAR(30)  NOT NULL,
vikt    INT(2)       NOT NULL,
PRIMARY KEY (namn)
)engine=innodb;

insert into skidåkare(namn, vikt) values ('Therese Johaug', '46');

CREATE TABLE tävling (
namn	VARCHAR(30) NOT NULL,
datum	DATE,
tid		TIME,
väder	VARCHAR(20),
deltagare VARCHAR(30),
PRIMARY KEY (namn)
)engine=innodb;

insert into tävling(namn, datum, tid, väder, deltagare) values ('Mördarbacken','2016-01-10',null,null,'Charlotte Kalla');

    