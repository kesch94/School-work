drop database c20antka;
create database c20antka;
use c20antka;

create table person(
	pnr char (13),
    namn varchar (20),
    primary key (pnr)
)engine=innodb;

create table husdjur(
	namn varchar (20),
    typ varchar (10),
    pnr char (13),
    primary key(pnr, namn),
    foreign key(pnr) references person(pnr)
)engine=innodb;

insert into person(pnr, namn) values ('1122334-1234', 'Kalle');
insert into person(pnr, namn) values ('2233445-5678' , 'Lisa');

insert into husdjur(namn, typ, pnr) values ('Fido', 'Hund', '1122334-1234');
insert into husdjur(namn, typ, pnr) values ('Missan', 'Katt' , '2233445-5678');

select * from person;

    
    
    