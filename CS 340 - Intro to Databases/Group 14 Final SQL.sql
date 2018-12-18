-- phpMyAdmin SQL Dump
-- version 4.8.1
-- https://www.phpmyadmin.net/
--
-- Host: classmysql.engr.oregonstate.edu:3306
-- Generation Time: Jun 14, 2018 at 05:11 PM
-- Server version: 10.1.22-MariaDB
-- PHP Version: 7.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `cs340_roppjo`
--

-- --------------------------------------------------------

--
-- Table structure for table `ProjectCampsites`
--

CREATE TABLE `ProjectCampsites` (
  `campID` int(5) NOT NULL DEFAULT '-5',
  `cName` varchar(20) DEFAULT 'Camp',
  `cAddress` varchar(20) DEFAULT NULL,
  `cDescription` text,
  `parkID` int(5) NOT NULL DEFAULT '-5',
  `cAvgRating` decimal(3,2) NOT NULL DEFAULT '0.00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectCampsites`
--

INSERT INTO `ProjectCampsites` (`campID`, `cName`, `cAddress`, `cDescription`, `parkID`, `cAvgRating`) VALUES
(12320, 'Jefferson Campsite 1', '456 Main, Jefferson ', 'Amenities: fire pit and bathrooms', 12300, '3.00'),
(12321, 'Sierra Campsite 1', '456 Main, Sierra Par', 'Amenities: fire pit and bathrooms', 12301, '4.25'),
(12322, 'Sierra Campsite 2', '458 Main, Sierra Par', 'Amenities: fire pit and bathrooms', 12301, '4.00'),
(12323, 'Arch Park Campsite 1', '250 Main, Arch Park', 'Amenities: fire pit and bathrooms', 12303, '2.00'),
(12324, 'Arch Park Campsite 2', '252 Main, Arch Park', 'Amenities: fire pit and bathrooms', 12303, '0.50');

-- --------------------------------------------------------

--
-- Table structure for table `ProjectFacilities`
--

CREATE TABLE `ProjectFacilities` (
  `facilityID` int(5) NOT NULL DEFAULT '-5',
  `otherID` int(5) NOT NULL DEFAULT '-5',
  `Ftype` char(1) NOT NULL DEFAULT 'A'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectFacilities`
--

INSERT INTO `ProjectFacilities` (`facilityID`, `otherID`, `Ftype`) VALUES
(10000, 12300, 'p'),
(10001, 12301, 'p'),
(10002, 12302, 'p'),
(10003, 12303, 'p'),
(10004, 12304, 'p'),
(10010, 12310, 't'),
(10011, 12311, 't'),
(10012, 12312, 't'),
(10013, 12313, 't'),
(10014, 12314, 't'),
(10020, 12320, 'c'),
(10021, 12321, 'c'),
(10022, 12322, 'c'),
(10023, 12323, 'c'),
(10024, 12324, 'c');

-- --------------------------------------------------------

--
-- Table structure for table `ProjectHikes&Trails`
--

CREATE TABLE `ProjectHikes&Trails` (
  `htID` int(5) NOT NULL DEFAULT '0',
  `htName` varchar(20) DEFAULT 'Hike or Trail',
  `htDescription` text,
  `htStartAddress` varchar(20) DEFAULT NULL,
  `htEndAddress` varchar(20) DEFAULT NULL,
  `tAvgRating` decimal(3,2) NOT NULL DEFAULT '0.00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectHikes&Trails`
--

INSERT INTO `ProjectHikes&Trails` (`htID`, `htName`, `htDescription`, `htStartAddress`, `htEndAddress`, `tAvgRating`) VALUES
(12310, 'Three Falls Hike', 'This hike features three big waterfalls that are lovely to visit in early Fall.', 'David\'s Trailhead', 'Three Falls Hike Tra', '3.00'),
(12311, 'Creek Adventure', 'This hike features many creeks to explore.', 'Arch Park', 'Arch Park', '4.00'),
(12312, 'Pacific Crest Trail', 'A trail that traverses several states and goes North-South.', 'Southern California ', 'Northern Washington ', '4.50'),
(12313, 'Scenic Views Hike', 'Travel along this hike and discover gorgeous views.', 'Jefferson Park', 'Sierra Park', '2.00'),
(12314, 'Willamette River Tra', 'This trail follows along the Willamette river.', 'Arch Park', 'Jefferson Park', '1.00');

-- --------------------------------------------------------

--
-- Table structure for table `ProjectIsIn`
--

CREATE TABLE `ProjectIsIn` (
  `htID` int(5) NOT NULL DEFAULT '-5',
  `parkID` int(5) NOT NULL DEFAULT '-5'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectIsIn`
--

INSERT INTO `ProjectIsIn` (`htID`, `parkID`) VALUES
(12310, 12303),
(12311, 12303),
(12312, 12301),
(12313, 12300),
(12314, 12303);

-- --------------------------------------------------------

--
-- Table structure for table `ProjectPark`
--

CREATE TABLE `ProjectPark` (
  `parkID` int(5) NOT NULL DEFAULT '-5',
  `pName` varchar(20) NOT NULL DEFAULT 'Park',
  `pDescription` text,
  `pAvgRating` decimal(3,2) NOT NULL DEFAULT '0.00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectPark`
--

INSERT INTO `ProjectPark` (`parkID`, `pName`, `pDescription`, `pAvgRating`) VALUES
(12300, 'Jefferson Park', 'Jefferson Park features lovely views of the Valley. It features a campsite that can be reserved.', '2.00'),
(12301, 'Sierra Park', 'Sierra Park features a fantastic waterfall in late summer to early fall.', '3.50'),
(12302, 'Grant\'s Plateau', 'Grant\'s Plateau has several campsites for reservation. Many hikes end up here for great views.', '4.00'),
(12303, 'Arch Park', 'Arch Park is the ideal location to begin many hikes. It also features picnic tables and campsites for reservation.', '2.50'),
(12304, 'Washington Park', 'Washington Park is a scenic location.', '3.25');

-- --------------------------------------------------------

--
-- Table structure for table `ProjectParkAddress`
--

CREATE TABLE `ProjectParkAddress` (
  `street` varchar(20) DEFAULT NULL,
  `city` varchar(40) DEFAULT NULL,
  `zip` int(10) DEFAULT NULL,
  `state` varchar(2) DEFAULT NULL,
  `parkID` int(5) NOT NULL DEFAULT '-5'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectParkAddress`
--

INSERT INTO `ProjectParkAddress` (`street`, `city`, `zip`, `state`, `parkID`) VALUES
('Park Road 578', 'Grant City', 97502, 'OR', 12300),
('Lake Road', 'Tri Cities', 97505, 'OR', 12301),
('Park Road 480', 'Grant City', 97502, 'OR', 12302),
('Main St', 'Laketon', 97440, 'OR', 12303),
('Murray Highway', 'Lakewoord', 97600, 'OR', 12304);

-- --------------------------------------------------------

--
-- Table structure for table `ProjectRating`
--

CREATE TABLE `ProjectRating` (
  `ratingID` int(5) NOT NULL DEFAULT '-5',
  `score` int(1) DEFAULT NULL,
  `rDescription` text,
  `username` varchar(20) NOT NULL DEFAULT 'User',
  `facilityID` int(5) NOT NULL DEFAULT '-5'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectRating`
--

INSERT INTO `ProjectRating` (`ratingID`, `score`, `rDescription`, `username`, `facilityID`) VALUES
(12340, 5, 'great hike!', 'HikerChick1', 10010),
(12341, 4, 'fun campsite', 'HikerChick1', 10023),
(12342, 4, 'great bird watching', 'birdwather86', 10004),
(12340, 5, 'fun hike', 'garyhikes', 10010),
(12344, 4, 'Arch Park is a great place to start hikes because they have bathrooms and maps!', 'jessie', 10003);

-- --------------------------------------------------------

--
-- Table structure for table `ProjectRoute`
--

CREATE TABLE `ProjectRoute` (
  `instructionNum` int(4) NOT NULL DEFAULT '-5',
  `instruction` text,
  `htID` int(5) NOT NULL DEFAULT '-5'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectRoute`
--

INSERT INTO `ProjectRoute` (`instructionNum`, `instruction`, `htID`) VALUES
(1, 'Three Falls Hike begins at David\'s Trailhead and ends at Three Falls Hike Trailhead. Follow trail 340.', 12310),
(2, 'Follow Arch Park trail 300. Signage is posted along the route.', 12311),
(3, 'Stay along the PCT. There is signage.', 12312),
(4, 'This hike spans two parks in Oregon. Stay on trail 451 between the two parks.', 12313),
(5, 'Begin at Arch Park. Take trail 251 until you reach Jefferson Park and then take Jefferson Park trail 20.', 12314);

-- --------------------------------------------------------

--
-- Table structure for table `ProjectUser`
--

CREATE TABLE `ProjectUser` (
  `username` varchar(20) NOT NULL DEFAULT 'User',
  `email` varchar(40) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  `salt` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectUser`
--

INSERT INTO `ProjectUser` (`username`, `email`, `password`, `salt`) VALUES
('birdwather86', 'teresag@hotmail.com', 'birdsight', NULL),
('carlz', 'carlyjohnson@gmail.com', 'bethray57', NULL),
('garyhikes', 'garylee@hotmail.com', '123leelyfe', NULL),
('HikerChick1', 'janesmith@gmail.com', 'hike4life', NULL),
('jessie', 'jessicahall@google.com', 'jessie1245', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `ProjectVisits`
--

CREATE TABLE `ProjectVisits` (
  `parkID` int(5) NOT NULL DEFAULT '-5',
  `username` varchar(20) NOT NULL DEFAULT 'User'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ProjectVisits`
--

INSERT INTO `ProjectVisits` (`parkID`, `username`) VALUES
(12304, 'birdwather86'),
(12303, 'jessie'),
(12300, 'carlz'),
(12301, 'HikerChick1'),
(12302, 'HikerChick1');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `ProjectCampsites`
--
ALTER TABLE `ProjectCampsites`
  ADD PRIMARY KEY (`campID`),
  ADD KEY `parkID` (`parkID`);

--
-- Indexes for table `ProjectFacilities`
--
ALTER TABLE `ProjectFacilities`
  ADD PRIMARY KEY (`facilityID`);

--
-- Indexes for table `ProjectHikes&Trails`
--
ALTER TABLE `ProjectHikes&Trails`
  ADD PRIMARY KEY (`htID`);

--
-- Indexes for table `ProjectIsIn`
--
ALTER TABLE `ProjectIsIn`
  ADD KEY `parkID` (`parkID`);

--
-- Indexes for table `ProjectPark`
--
ALTER TABLE `ProjectPark`
  ADD PRIMARY KEY (`parkID`);

--
-- Indexes for table `ProjectParkAddress`
--
ALTER TABLE `ProjectParkAddress`
  ADD KEY `parkID` (`parkID`);

--
-- Indexes for table `ProjectRating`
--
ALTER TABLE `ProjectRating`
  ADD KEY `username` (`username`),
  ADD KEY `facilityID` (`facilityID`);

--
-- Indexes for table `ProjectRoute`
--
ALTER TABLE `ProjectRoute`
  ADD KEY `htID` (`htID`);

--
-- Indexes for table `ProjectUser`
--
ALTER TABLE `ProjectUser`
  ADD PRIMARY KEY (`username`);

--
-- Indexes for table `ProjectVisits`
--
ALTER TABLE `ProjectVisits`
  ADD KEY `parkID` (`parkID`),
  ADD KEY `username` (`username`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `ProjectCampsites`
--
ALTER TABLE `ProjectCampsites`
  ADD CONSTRAINT `ProjectCampsites_ibfk_1` FOREIGN KEY (`parkID`) REFERENCES `ProjectPark` (`parkID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `ProjectIsIn`
--
ALTER TABLE `ProjectIsIn`
  ADD CONSTRAINT `ProjectIsIn_ibfk_1` FOREIGN KEY (`parkID`) REFERENCES `ProjectPark` (`parkID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `ProjectParkAddress`
--
ALTER TABLE `ProjectParkAddress`
  ADD CONSTRAINT `ProjectParkAddress_ibfk_1` FOREIGN KEY (`parkID`) REFERENCES `ProjectPark` (`parkID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `ProjectRating`
--
ALTER TABLE `ProjectRating`
  ADD CONSTRAINT `ProjectRating_ibfk_1` FOREIGN KEY (`username`) REFERENCES `ProjectUser` (`username`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ProjectRating_ibfk_2` FOREIGN KEY (`facilityID`) REFERENCES `ProjectFacilities` (`facilityID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `ProjectRoute`
--
ALTER TABLE `ProjectRoute`
  ADD CONSTRAINT `ProjectRoute_ibfk_1` FOREIGN KEY (`htID`) REFERENCES `ProjectHikes&Trails` (`htID`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `ProjectVisits`
--
ALTER TABLE `ProjectVisits`
  ADD CONSTRAINT `ProjectVisits_ibfk_1` FOREIGN KEY (`parkID`) REFERENCES `ProjectPark` (`parkID`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `ProjectVisits_ibfk_2` FOREIGN KEY (`username`) REFERENCES `ProjectUser` (`username`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
