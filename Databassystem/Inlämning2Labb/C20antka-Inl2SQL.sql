drop database c20antka;
create database c20antka;
use c20antka;

CREATE TABLE skidakare (
    namn VARCHAR(30),
    vikt INT(2),
    PRIMARY KEY (namn)
)  ENGINE=INNODB;


CREATE TABLE tavling (
    namn VARCHAR(30),
    datum DATE,
    PRIMARY KEY (namn)
)  ENGINE=INNODB;

CREATE TABLE vader (
    typ VARCHAR(20),
    temp INT,
    PRIMARY KEY (typ)
)  ENGINE=INNODB;

CREATE TABLE sno (
    typ VARCHAR(20),
    luftfuktighet VARCHAR(4),
    PRIMARY KEY (typ)
)  ENGINE=INNODB;

CREATE TABLE valla (
    namn VARCHAR(30),
    typ VARCHAR(30),
    PRIMARY KEY (namn)
)  ENGINE=INNODB;

CREATE TABLE struktur (
    namn VARCHAR(30),
    grovlek VARCHAR(10),
    PRIMARY KEY (namn)
)  ENGINE=INNODB;

CREATE TABLE skidor (
    nr INT NOT NULL,
    skidakareNamn VARCHAR(30),
    fabrikat VARCHAR(30),
    spann VARCHAR(30),
    snoTyp VARCHAR(20),
    vaderTyp VARCHAR(20),
    strukturNamn VARCHAR(30),
    PRIMARY KEY (nr , skidakareNamn)
)  ENGINE=INNODB;

CREATE TABLE rillverktyg (
    fabrikat VARCHAR(30),
    kommentar VARCHAR(50),
    strukturNamn VARCHAR(30),
    PRIMARY KEY (fabrikat)
)  ENGINE=INNODB;

CREATE TABLE deltagare (
    tavlingNamn VARCHAR(30),
    skidakareNamn VARCHAR(30),
    PRIMARY KEY (tavlingNamn , skidakareNamn)
)  ENGINE=INNODB;

CREATE TABLE tavlingSno (
    tavlingNamn VARCHAR(30),
    snoTyp VARCHAR(20),
    PRIMARY KEY (tavlingNamn , snoTyp)
)  ENGINE=INNODB;

CREATE TABLE tavlingVader (
    tavlingNamn VARCHAR(30),
    vaderTyp VARCHAR(20),
    tid TIME,
    PRIMARY KEY (tavlingNamn , vaderTyp)
)  ENGINE=INNODB;

CREATE TABLE skidValla (
    vallaNamn VARCHAR(20) NOT NULL,
    skidNr INT NOT NULL,
    skidakareNamn VARCHAR(30) NOT NULL,
    PRIMARY KEY (vallaNamn , skidNr , skidakareNamn)
)  ENGINE=INNODB;


/*skidåkare*/
insert into skidakare(namn,vikt) values ('Therese Johaug','46'); 
insert into skidakare(namn,vikt) values ('Charlotte Kalla','60');
insert into skidakare(namn,vikt) values ('Anna Haag','62');
insert into skidakare(namn,vikt) values ('Stina Nilsson','64');
insert into skidakare(namn,vikt) values ('Emma Wikén','64');
insert into skidakare(namn,vikt) values ('Marit Björgren','52');
insert into skidakare(namn,vikt) values ('Blixten McQueen','65');
insert into skidakare(namn,vikt) values ('Anton Karlsson','100');
insert into skidakare(namn,vikt) values ('Okki Skidonen','70');

/*skidor*/
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('3','Markus Hellner','Fischer','Klisterskida','Slask','regnigt','Grov Julgran');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('10','Anna Haag','Fischer','Lågt','Hård snö','Kallt','Snedskuren');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('4','Stina Nilsson','Salomon','Högt','Lös snö','klart','Klister');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('5','Emma Wikén', 'Rosignol','Medel','Blandsnö','mulet','Klister');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('7','Charlotte Kalla','Fischer','Klisterskida','Slask','regnigt','Grov Julgran');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('1', 'Anton Karlsson', 'Salomon', 'Lågt', 'Hård snö', 'Kallt', 'Snedskuren');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('2', 'Blixten McQueen', 'Rosignol', 'Högt', 'Lös snö','klart', 'Rakskuren');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('3', 'Marit Björgren', 'Madhus', 'lågt', 'Medel kallt','klart', 'Snedskuren');
insert into skidor(nr,skidakareNamn,fabrikat,spann,snoTyp,vaderTyp,strukturNamn) values ('2','Markus Hellner','Fischer','Klisterskida','Slask','Varmt','Grov Julgran');


/*Tävling*/
insert into tavling(namn,datum) values ('Mördarbacken','2016-01-10'); 
insert into tavling(namn,datum) values ('Oberstdorf','2016-01-05');
insert into tavling(namn,datum) values ('Lenzerheide','2016-01-27');
insert into tavling(namn,datum) values ('Storkuppen', '2016-12-12');
insert into tavling(namn,datum) values ('Julsprinten', '2016-12-24');
insert into tavling(namn,datum) values ('Vasaloppet', '2017-02-20');
insert into tavling(namn,datum) values ('Vasarejset','2021-02-20');

/*Deltagare*/
insert into deltagare(tavlingNamn,skidakareNamn) values ('Mördarbacken','Charlotte Kalla');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Lenzerheide','Marit Björgren');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Mördarbacken', 'Anna Haag');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Vasaloppet', 'Markus Hellner');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Vasaloppet', 'Anton Karlsson');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Vasaloppet', 'Blixten McQueen');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Julsprinten', 'Blixten Mcqueen');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Julsprinten', 'Anton Karlsson');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Mördarbacken', 'Emma Wikén');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Lenzerheide', 'Charlotte Kalla');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Lenzerheide', 'Okki Skidonen');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Oberstdorf', 'Charlotte Kalla');
insert into deltagare(tavlingNamn,skidakareNamn) values ('Oberstdorf', 'Anton Karlsson');


/*Struktur*/
insert into struktur(namn,grovlek) values ('Grov Julgran','2mm');
insert into struktur(namn,grovlek) values ('Snedskuren','5mm');
insert into struktur(namn,grovlek) values ('Klister','1mm');
insert into struktur(namn,grovlek) values ('Rakskuren','7mm');

/*tavlingVader*/
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Oberstdorf','Extremt kallt','08:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Lenzerheide','Soligt','07:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Lenzerheide','Spöregn','09:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Mördarbacken','Medel kallt','10:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Julsprinten','Klart','11:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Vasaloppet','Spöregn','10:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Vasaloppet','Medel kallt','12:00');
insert into tavlingVader(tavlingNamn,vaderTyp,tid) values ('Lenzerheide','Varmt','12:00');


/*valla*/
insert into valla(namn,typ) values ('Swix KX35','Klister') ;
insert into valla(namn,typ) values ('Swix HF8','Glid');
insert into valla(namn,typ) values ('Swix KX45','Fäst');
insert into valla(namn,typ) values ('Skigo HF-GUL','Glid');
insert into valla(namn,typ) values ('Zuperznabb','Superglid');

/*väder*/
insert into vader(typ, temp) values ('Extremt kallt','-20');
insert into vader(typ, temp) values ('Soligt', '+5');
insert into vader(typ, temp) values ('Spöregn', '+0');
insert into vader(typ, temp) values ('Extremt varmt','+15');
insert into vader(typ, temp) values ('Medel kallt', '-10');
insert into vader(typ, temp) values ('Klart', '+2');

/*rillverktyg*/
insert into rillverktyg(fabrikat,kommentar,strukturNamn) values ('Swix','Helt otroligt snabb i kallföre','Snedskuren'); 
insert into rillverktyg(fabrikat,kommentar,strukturNamn) values ('Skigo','Skit bra i varm blötsnö','Rakskuren');
insert into rillverktyg(fabrikat,kommentar,strukturNamn) values ('Rillmästaren','Bra i slask', 'Klister');
insert into rillverktyg(fabrikat,kommentar,strukturNamn) values ('Rillking','Dålig i blöttväder','Grov Julgran');
insert into rillverktyg(fabrikat,kommentar,strukturNamn) values ('Ril','Dalig','Grov Julgran');

/*Skidavalla*/
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Swix KX35','4','Stina Nilsson');
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Swix KX35','5','Emma Wikén');
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Swix HF8','7','Charlotte Kalla');
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Swix KX45','7','Charlotte Kalla');
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Swix KX35','3','Marcus Hellner');
insert into skidValla(vallaNamn,skidNr,skidakareNamn) values ('Skigo HF-GUL','6','Marit Björgren');



/*TävlingSnö*/
insert into tavlingSno(tavlingNamn,snoTyp) values ('Lenzerheide','stenhård');
insert into tavlingSno(tavlingNamn,snoTyp) values ('Lenzerheide','mjuk');
insert into tavlingSno(tavlingNamn,snoTyp) values ('Mördarbacken','hård');
insert into tavlingSno(tavlingNamn,snoTyp) values ('Julsprinter', 'kramsnö');
insert into tavlingSno(tavlingNamn,snoTyp) values ('Vasaloppet', 'blöt');

/*Snö*/
insert into sno(typ,luftfuktighet) values ('slask','100%');
insert into sno(typ,luftfuktighet) values ('blöt','80&');
insert into sno(typ,luftfuktighet) values ('kramsnö','60%');
insert into sno(typ,luftfuktighet) values ('hård', '20%');

/*Fråga 1 Frågespråk*/
SELECT 
    vikt
FROM
    skidakare
WHERE
    namn = 'Therese Johaug';
    
/*Fråga 2 Frågespråk*/
SELECT 
    *
FROM
    tavling
WHERE
    namn = 'Mördarbacken';
    
/*Fråga 3 Frågespråk*/
SELECT
     skidakare.vikt 
FROM
     skidakare,tavling,deltagare
WHERE
   skidakare.namn=skidakareNamn AND deltagare.tavlingNamn=tavling.namn AND tavling.datum = "2016-01-05";
   
/*Fråga 4 Frågespråk*/
SELECT 
    skidakareNamn
FROM
    skidor
WHERE
    fabrikat = 'madhus' AND nr = '3'
        AND strukturNamn = 'Snedskuren';
        
/*Fråga 5 Frågespråk*/
SELECT 
    *
FROM
    tavlingVader
WHERE
    tavlingVader.tavlingNamn = 'Lenzerheide'
        AND tavlingVader.tid = '12:00';
/*Tar reda på tävlingensväder för att sedan använda det som condition i nästa sökning, delar upp problemet för att enklare lösa det*/
SELECT 
    skidor.nr, skidor.skidakareNamn, skidor.vaderTyp
FROM
    skidor
WHERE
    skidor.vaderTyp = 'Varmt'
        AND skidor.nr = '2';

 /*Fråga 6 Frågespråk*/ 
SELECT 
    A.vikt, A.namn AS namn1, B.namn AS namn2
FROM
    skidakare A
        INNER JOIN
    skidakare B ON A.namn > B.namn AND A.vikt = B.vikt;
    
/*Fråga 7 Frågespråk */
SELECT 
    skidakare.namn
FROM
    skidakare
WHERE
    NOT EXISTS( SELECT 
            *
        FROM
            deltagare
        WHERE
            skidakare.namn = deltagare.skidakareNamn); 
            
/*Fråga 8 Frågespråk EJ KLAR*/
SELECT *
FROM tavlingVader
WHERE NOT EXISTS (SELECT * FROM vader
WHERE NOT EXISTS (SELECT * FROM tavling
WHERE vader.typ=tavlingVader.typ and
T=person.pnr));


/*Fråga 9 Frågespråk */
SELECT 
    snoTyp
FROM
    tavlingSno;

/*Fråga 10 Frågespråk EJ KLAR */
SELECT 
    COUNT(deltagare.skidakareNamn)
FROM
    deltagare
GROUP BY skidakareNamn;

/*Fråga 11 Frågespråk*/
SELECT 
    *
FROM
    valla
ORDER BY valla.namn DESC;

/*Fråga 12 Frågespråk*/
SELECT 
    AVG(skidakare.vikt)
FROM
    skidakare;

/*Fråga 13 Frågespråk*/
SELECT 
    AVG(skidakare.vikt)
FROM
    skidakare,
    deltagare,
    tavling
WHERE
    skidakare.namn = deltagare.skidakareNamn
        AND deltagare.tavlingNamn = tavling.namn
GROUP BY tavling.namn;

/*Fråga 14 Frågespråk*/
SELECT 
    fabrikat
FROM
    rillverktyg
WHERE
    fabrikat LIKE 'S%';
   
/*Fråga 15 Frågespråk*/
SELECT 
    fabrikat
FROM
    rillverktyg
WHERE
    kommentar LIKE '_____';

/*Frågespråk*/
SELECT 
    MIN(typ)
FROM
    vader;

/*Fråga 17 Frågespråk*/
SELECT 
    MAX(datum)
FROM
    tavling;
-----------------------------
SELECT 
    tavling.namn
FROM
    tavling
WHERE
    datum = '2017-02-20';

/*Fråga 18 Frågespråk curdate för dagens datum -1 för gårdagen, skriven 2021-02-21*/
SELECT 
    *
FROM
    tavling
WHERE
    datum = CURDATE() - 1;

/*Fråga 19 Frågespråk*/
UPDATE skidakare 
SET 
    vikt = vikt * 1.1
WHERE
    vikt BETWEEN '50' AND '60';

/*Fråga 20 Frågespråk*/
DELETE FROM skidakare 
WHERE
    namn = 'Anna Haag';
DELETE FROM deltagare 
WHERE
    skidakareNamn = 'Anna Haag';
DELETE FROM skidor 
WHERE
    skidakareNamn = 'Anna Haag';

/*Fråga 21 Frågespråk*/
DELETE FROM skidor 
WHERE
    nr = '2'
    AND skidakareNamn = 'Markus Hellner';
    




     
  











    