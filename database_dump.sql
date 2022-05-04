-- MySQL dump 10.13  Distrib 8.0.27, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL AUTO_INCREMENT,
  `Nimi` varchar(45) DEFAULT NULL,
  `Lahiosoite` varchar(45) DEFAULT NULL,
  `Puhelinnumero` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idAsiakas`),
  UNIQUE KEY `Nimi_UNIQUE` (`Nimi`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Teppo Testimies','Testitie 1','111222333'),(2,'Teukka Testimies','Pöllökuja 2','111225511'),(3,'Theodor Testaaja','Tulitie 52','3959123');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idKortti` int NOT NULL,
  `Korttinumero` int DEFAULT NULL,
  `PIN` varchar(255) DEFAULT NULL,
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`idKortti`),
  KEY `fk_kortti_asiakas1_idx` (`idAsiakas`),
  KEY `fk_kortti_tili1_idx` (`idTili`),
  CONSTRAINT `fk_kortti_asiakas1` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`) ON UPDATE CASCADE,
  CONSTRAINT `fk_kortti_tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (1,123123,'$2a$10$45jjMHk03l602NGtZHMwSOzvL7OQ9l8RSXiclp5J9XU8C0BZRP6Hq',1,1),(2,123456,'$2a$10$DVOGlXj63Rdk98Ny9H4zF.rSnnWmS.AIPZmpQ2ULcxJ.aQzIakOjC',2,2),(3,121212,'$2a$10$l0cEpuV3vRfWctkwKON/gOAwvwvWZWjpUjT4XRfweX4bEIlOAIX6C',3,3),(4,54321,'$2a$10$HPCaxaWqF1jSWrdAXcLAEuYEA54ap33XuRw71d22GQbELQXS/G1w2',1,4);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL AUTO_INCREMENT,
  `Tilinumero` varchar(45) DEFAULT NULL,
  `Saldo` float DEFAULT NULL,
  `amount` int DEFAULT NULL,
  PRIMARY KEY (`idTili`),
  UNIQUE KEY `idTili_UNIQUE` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (1,'12345',52421,100),(2,'242424',52505,NULL),(3,'123456789',525212,NULL),(4,'54321',6992,NULL);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili_asiakas`
--

DROP TABLE IF EXISTS `tili_asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili_asiakas` (
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`idAsiakas`,`idTili`),
  KEY `fk_Tili_asiakas_tili1_idx` (`idTili`),
  CONSTRAINT `fk_Tili_asiakas_asiakas` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`) ON UPDATE CASCADE,
  CONSTRAINT `fk_Tili_asiakas_tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili_asiakas`
--

LOCK TABLES `tili_asiakas` WRITE;
/*!40000 ALTER TABLE `tili_asiakas` DISABLE KEYS */;
INSERT INTO `tili_asiakas` VALUES (1,1);
/*!40000 ALTER TABLE `tili_asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL,
  `Paivays` datetime DEFAULT NULL,
  `Tapahtuma` varchar(45) DEFAULT NULL,
  `Summa` float DEFAULT NULL,
  `idTili` int NOT NULL,
  `idKortti` int DEFAULT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  KEY `fk_tilitapahtumat_tili1_idx` (`idTili`),
  CONSTRAINT `fk_tilitapahtumat_tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`) ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (1,'2024-06-20 00:00:00','Opintotuki',69.69,1,2),(2,'2021-01-02 01:02:03','Lomaraha',520,1,2),(3,NULL,'Ruokaraha',100,3,3),(4,NULL,'Veronpalautus',300,4,4);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-05-04 22:46:10
