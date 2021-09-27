drop database c20antka;
create database c20antka;
use c20antka;
CREATE TABLE Tomtenisse (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    LonRussin INT(2) NOT NULL,
    LonNotter INT(2) NOT NULL,
    AdressBarack INT(1) NOT NULL,
    AdressSangNr INT(3) UNIQUE NOT NULL,
    PRIMARY KEY (NAMN , IdNr)
)  ENGINE=INNODB;

CREATE TABLE Byggare (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    Kladfarg VARCHAR(55) NOT NULL,
    Specialitet VARCHAR(55) NOT NULL,
    Antal INT(10) NOT NULL,
    Verktygskostnad INT(10) NOT NULL,
    PRIMARY KEY (Namn , IdNr),
    FOREIGN KEY (Namn , IdNr)
        REFERENCES Tomtenisse (Namn , IdNr)
)  ENGINE=INNODB;
  
CREATE TABLE Mellanchef (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    Skostorlek VARCHAR(10) NOT NULL,
    Total INT(20),
    AnsvarAvdelning VARCHAR(55),
    Teamlista VARCHAR(55),
    PRIMARY KEY (Namn , IdNr),
    FOREIGN KEY (Namn , IdNr)
        REFERENCES Tomtenisse (Namn , IdNr)
)  ENGINE=INNODB;
  
CREATE TABLE Handlaggare (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    Kategori VARCHAR(55) NOT NULL,
    Knatoffsar VARCHAR(55) NOT NULL,
    Andel VARCHAR(55) NOT NULL,
    Total VARCHAR(55) NOT NULL,
    Medel VARCHAR(55) NOT NULL,
    PRIMARY KEY (Namn , IdNr),
    FOREIGN KEY (Namn , IdNr)
        REFERENCES Tomtenisse (Namn , IdNr)
)  ENGINE=INNODB;
  
CREATE TABLE Informator (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    Funktion VARCHAR(55) NOT NULL,
    Mossfarg VARCHAR(55) NOT NULL,
    Medalj VARCHAR(55) NOT NULL,
    Antal VARCHAR(55) NOT NULL,
    PRIMARY KEY (Namn , IdNr),
    FOREIGN KEY (Namn , IdNr)
        REFERENCES Tomtenisse (Namn , IdNr)
)  ENGINE=INNODB;
  
CREATE TABLE Avdelning (
    Namn VARCHAR(55) NOT NULL,
    IdNr CHAR(23) UNIQUE NOT NULL,
    CHECK (IdNr LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]-[0-9]-[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]'),
    AvdelningNummer INT(3) NOT NULL,
    PRIMARY KEY (Namn , IdNr),
    FOREIGN KEY (Namn , IdNr)
        REFERENCES Tomtenisse (Namn , IdNr)
)  ENGINE=INNODB;
 
/*Tomtenisse*/
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Anton Karlsson','133737-0205-8-123456789','12','13','1','1');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Gundhe Svan','186547-0505-5-123456239','12','13','1','23');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Peter Petersson','362777-0916-4-123456654','12','13','2','3');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Peter Forsberg','956737-0713-8-123456789','12','13','3','25');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Mika Hakkinen','512737-0611-7-123455439','12','13','1','13');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Speedy Gonzalez','639737-1011-9-123456123','12','13','2','22');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Anders Andersson','123737-1224-6-987654321','12','13','3','17');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Johan Johansson','852737-1231-8-123456123','12','13','1','14');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Anna Brax','456737-1222-7-123456654','12','13','2','35');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Lena Aborre','789737-0507-9-123456453','12','13','2','33');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Henrik Gädda','963737-0103-9-123456956','12','13','1','99');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Lena Öring','654737-0216-6-123456254','12','13','1','55');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Rasmus Rasmusson','133753-0313-5-123456753','12','13','1','53');
insert into Tomtenisse(Namn,IdNr,LonRussin,LonNotter,AdressBarack,AdressSangNr) values ('Daniella Karlsson','123456-0707-7-123456357','12','13','1','12');

/*Byggare*/
insert into Byggare(Namn,IdNr,Kladfarg,Specialitet,Antal,Verktygskostnad) values ('Anton Karlsson','133737-0205-8-123456789','Brun','Dockor','999.999','100.000');
insert into Byggare(Namn,IdNr,Kladfarg,Specialitet,Antal,Verktygskostnad) values ('Gundhe Svan','186547-0505-5-123456239','Brun','Bilar','900.000','900.000');

/*Mellanchef*/
insert into Mellanchef(Namn,IdNr,Skostorlek,Total,AnsvarAvdelning,Teamlista) values ('Peter Petersson','362777-0916-4-123456654','40','2','1','2');
insert into Mellanchef(Namn,IdNr,Skostorlek,Total,AnsvarAvdelning,Teamlista) values ('Peter Forsberg','956737-0713-8-123456789','42','','','');

/*Handläggare*/
insert into Handlaggare(Namn,IdNr,Kategori,Knatoffsar,Andel,Total,Medel) values ('Mika Hakkinen','512737-0611-7-123455439','dockor','3','','','');
insert into Handlaggare(Namn,IdNr,Kategori,Knatoffsar,Andel,Total,Medel) values ('Speedy Gonzalez','639737-1011-9-123456123','bilar','27','','','');

/*Informatör*/
insert into Informator(Namn,IdNr,Funktion,Mossfarg,Medalj,Antal) values ('Anders Andersson','123737-1224-6-987654321','','blå','','');
insert into Informator(Namn,IdNr,Funktion,Mossfarg,Medalj,Antal) values ('Johan Johansson','852737-1231-8-123456123','','grön','','');

/*Avdelning*/
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Anton Karlsson','133737-0205-8-123456789','3');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Johan Johansson','852737-1231-8-123456123','1');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Speedy Gonzalez','852737-1231-8-123456123','1');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Mika Hakkinen','512737-0611-7-123455439','2');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Peter Forsberg','956737-0713-8-123456789','2');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Peter Petersson','362777-0916-4-123456654','3');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Anders Andersson','123737-1224-6-987654321','2');
insert into Avdelning(Namn,IdNr,AvdelningNummer) values ('Gundhe Svan','186547-0505-5-123456239','1');


CREATE USER 'Anton Karlsson'@'localhost' IDENTIFIED BY '133737-0205-8-123456789';

CREATE ROLE r1;
GRANT r1 TO Anton Karlsson@localhost;
GRANT SELECT, INSERT,UPDATE ON db1.* TO r1;


INDEX FOR QUERY SELECT * FROM INVOICEROW WHERE CUSTNO="XXX";       
CREATE INDEX CUSTOMERINVOICES ON INVOICEROW(CUSTNO ASC) USING BTREE;
INDEX FOR QUERY SELECT * FROM CUSTOMER ORDER BY NAME;       
CREATE INDEX CUSTOMERNAMES ON CUSTOMER(NAME ASC) USING BTREE;

CREATE VIEW CUSTOMERINVOICE AS    SELECT CUSTOMER.CUSTNO,CUSTOMER.NAME,CUSTOMER.SSN,CUSTOMER.REGDATE,INVOICEROW.INVOICENO,INVOICEROW.DATEPAID,INVOICEROW.NUMBER,INVOICEROW.PRODUCT,INVOICEROW.COMPANY,INVOICEROW.COST    FROM CUSTOMER,INVOICEROW WHERE CUSTOMER.CUSTNO=INVOICEROW.CUSTNO
UNION
SELECT CUSTOMER.CUSTNO,CUSTOMER.NAME,CUSTOMER.SSN,CUSTOMER.REGDATE,PAIDINVOICEROW.INVOICENO,PAIDINVOICEROW.DATEPAID,PAIDINVOICEROW.NUMBER,PAIDIN

CREATE VIEW PRODUCTSTATISTICS AS
SELECT PRODUCTNAME,AVG(COST) AS AVGCOST
FROM INVOICEROW,PRODUCT
WHERE INVOICEROW.PRODUCT=PRODUCT.PRODUCTCODE
GROUP BY PRODUCT;

 
-- Create a user for the economy system application
CREATE USER 'economysystem"@'localhost" IDENTIFIED BY 'mypass";
-- Gives select access to COMPANY table to the economysystem
GRANT SELECT ON a00leifo.COMPANY TO economysystem;
-- Create a view that excludes the password from the result
CREATE VIEW ECONOMYCUSTOMERS AS SELECT CUSTNO,SSN,NAME,REGDATE FROM CUSTOMER;
-- Gives select on all parts of customer except for password to economysystem
GRANT SELECT ON a00leifo.ECONOMYCUSTOMERS to economysystem;

CREATE VIEW COMPANYCOMMENTS AS                                  
SELECT COMPANYNAME,COMMENT FROM COMPANY,INVOICEROW,INVOICEROWCOMMENT    

CREATE VIEW CHECKCUSTOMER AS SELECT * FROM CUSTOMER WHERE (SSN LIKE '[0-9][0-9][0-9][0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]") WITH CHECK OPTION;
GRANT INSERT ON a00leifo.COMPANY TO economysystem;
