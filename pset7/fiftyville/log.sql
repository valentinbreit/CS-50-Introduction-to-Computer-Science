-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT id, description FROM crime_scene_reports WHERE "day" = 28;
-- Now i know that the id from the crime is 295
SELECT * FROM crime_scene_reports WHERE "id" = 295;
-- This is all information that the police has:
-- 295 | 2020 | 7 | 28 | Chamberlin Street 
--| Theft of the CS50 duck took place at 10:15am at the Chamberlin Street 
--courthouse. Interviews were conducted today with three witnesses who 
--were present at the time — each of their interview transcripts mentions 
-- the courthouse.
SELECT id, transcript FROM interviews WHERE "day" = 28 AND "month" = 7 AND "year" = 2020;
-- This is all relevant information of the invterview: 
-- I saw the thief get into a car in the courthouse parking lot and drive away
-- ten minutes
-- I was walking by the ATM on Fifer Street and saw the thief there 
-- withdrawing some money.
-- they were planning to take the earliest flight out of Fiftyville tomorrow
-- they bouth fligth tickets
-- ID = from 158 to 163

-- Going to investigate first the parking lot -10 minutes the interview was made
SELECT DISTINCT(name) FROM people JOIN courthouse_security_logs ON (courthouse_security_logs.license_plate = people.license_plate) WHERE courthouse_security_logs.day = 28 AND courthouse_security_logs.month = 7 AND courthouse_security_logs.year = 2020;
-- This where the names that i care for the time:
-- Alice Peter Rachel Debra Wayne Jordan Elizabeth Ernest George Michael Madison Andrew Russell Ralph Evelyn Joshua Carolyn Berthold Donna Martha Danielle Patrick Amber Roger Brandon Sophia Denise Thomas Jeremy Judith Mary Vincent Daniel Frank Amanda John Ethan

-- Now i can investigate the phone call:
SELECT name FROM people JOIN phone_calls ON (people.phone_number = phone_calls.caller) WHERE (phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60); 

-- Suspects now:
-- Roger Evelyn Ernest Madison Russell Kimberly Bobby Victoria

-- Now i can investigate the ATM Transaction:
SELECT DISTINCT(name) FROM people JOIN bank_accounts ON (people.id = bank_accounts.person_id) JOIN atm_transactions ON (bank_accounts.account_number = atm_transactions.account_number) WHERE "day" = 28 AND "month" = 7 AND "year" = 2020;
-- suspects: Madison Ernest Arthur

-- Now i have to investigate the fligths
-- first i need to find the id airport:
SELECT full_name, city FROM airports;
SELECT destination_airport_id, hour, minute FROM flights JOIN airports ON  airports.id = flights.origin_airport_id AND airports.city = "Fiftyville" ORDER BY flights.hour;
-- this is the information of the flight nearest the time:
SELECT name FROM people JOIN passengers ON (passengers.passport_number = people.passport_number) WHERE passengers.flight_id = (SELECT id FROM flights WHERE "day" = 29 AND "month" = 7 AND "year" = 2020 ORDER BY hour, minute LIMIT 1);
-- names: Doris Roger Ernest Edward Evelyn Madison Bobby Danielle

--priority suspects: Ernest - Madison - Evelyn - Bobby

-- Now i have to with the callers and plate who´s the thief
SELECT * FROM people WHERE "name" = "Ernest";
-- This is the person that matchets with all the information:
-- 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X

-- Ultimate step to find the thief:
SELECT name FROM people JOIN phone_calls ON (people.phone_number = phone_calls.caller) WHERE phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020 AND phone_calls.duration < 60;
-- Roger Evelyn Ernest Madison Russell Kimberly Bobby Victoria

-- Now i have to find where Ernest escape to:

SELECT id, destination_airport_id FROM flights JOIN passengers ON (passengers.flight_id = flights.id) WHERE (passengers.passport_number = "1988161715");
-- he flight to:
SELECT city, full_name FROM airports WHERE "id" = 4;
-- London | Heathrow Airport


SELECT name FROM people JOIN phone_calls ON (people.phone_number = phone_calls.receiver) WHERE phone_calls.day = 28 AND phone_calls.month = 7 AND phone_calls.year = 2020 AND phone_calls.duration < 60 AND phone_calls.caller = "(367) 555-5533";

-- His partnert is:Berthold