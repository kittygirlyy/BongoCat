# BongoCat

Explication:

- Client-Side en C++

- Server-Side en Python

- Chiffrement XOR des strings

- Supporte HTTP

- Pannel web

---

HTTPRequest doc:
https://github.com/elnormous/HTTPRequest/blob/master/include/HTTPRequest.hpp

Serv documentation:
https://flask-fr.readthedocs.io

pense bete pr moi:
https://www.cprogramming.com/tutorial/xor.html

---

Panel pour le serv:

- Stats: cle generer, webhooks, identification par UiD
- Bdd: MySQL

Bdd setup:

CREATE TABLE `bongocat`.`infected` (
  `attaquant` INT NULL,
  `victime` INT NULL,
  `ip` VARCHAR(45) NULL,
  `key` VARCHAR(45) NULL)
COMMENT = 'We ak like cats';



CREATE TABLE `bongocat`.`keygen` (
  `IP` VARCHAR(45) NULL,
  `KEY` VARCHAR(45) NULL)
COMMENT = 'Brrr my cat love this';


---

BongoCat packer:

A FAIRE
