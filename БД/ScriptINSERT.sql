

INSERT INTO author
VALUES(1,'Metallica');
INSERT INTO author
VALUES(2,'JASSartist');
INSERT INTO author
VALUES(3,'POPidol');
INSERT INTO author
VALUES(4,'RnBmaster');

INSERT INTO genre
VALUES(1,'Rock');
INSERT INTO genre
VALUES(2,'Jass');
INSERT INTO genre
VALUES(3,'Pop');

INSERT INTO trek 
VALUES (1,'trek1','00:01:00.1');
INSERT INTO trek 
VALUES (2,'trek2','00:02:00.1');
INSERT INTO trek 
VALUES (3,'trek3','00:03:00.1');
INSERT INTO trek 
VALUES (4,'trek4','00:04:00.1');
INSERT INTO trek 
VALUES (5,'trek5','00:05:00.1');
INSERT INTO trek 
VALUES (6,'trek6','00:06:00.1');

INSERT INTO album 
VALUES (1,'First album');
INSERT INTO album 
VALUES (2,'Second album');
INSERT INTO album 
VALUES (3,'Third album');

INSERT INTO collection 
VALUES (1,'collection1', '2001-01-01');
INSERT INTO collection 
VALUES (2,'collection2', '2003-01-01');
INSERT INTO collection 
VALUES (3,'collection3', '2004-01-01');
INSERT INTO collection 
VALUES (4,'collection4', '2005-01-01');

INSERT INTO author_album (album_id,author_id) VALUES (1,1);
INSERT INTO author_album (album_id,author_id) VALUES (1,2);
INSERT INTO author_album (album_id,author_id) VALUES (1,3);
INSERT INTO author_album (album_id,author_id) VALUES (1,4);
INSERT INTO author_album (album_id,author_id) VALUES (2,1);
INSERT INTO author_album (album_id,author_id) VALUES (2,2);
INSERT INTO author_album (album_id,author_id) VALUES (2,3);
INSERT INTO author_album (album_id,author_id) VALUES (2,4);
INSERT INTO author_album (album_id,author_id) VALUES (3,1);
INSERT INTO author_album (album_id,author_id) VALUES (3,2);
INSERT INTO author_album (album_id,author_id) VALUES (3,3);
INSERT INTO author_album (album_id,author_id) VALUES (3,4);


INSERT INTO genre_author  (genre_id ,author_id) VALUES (1,1);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (1,2);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (1,3);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (1,4);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (2,1);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (2,2);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (2,3);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (2,4);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (3,1);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (3,2);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (3,3);
INSERT INTO genre_author  (genre_id ,author_id) VALUES (3,4);

INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,1);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,2);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,3);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,4);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,5);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (1,6);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,1);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,2);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,3);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,4);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,5);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (2,6);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,1);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,2);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,3);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,4);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,5);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (3,6);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,1);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,2);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,3);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,4);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,5);
INSERT INTO collection_trek  (collection_id  ,trek_id) VALUES (4,6);

SELECT * FROM collection_trek;



