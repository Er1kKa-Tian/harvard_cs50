-- Keep a log of any SQL queries you execute as you solve the mystery.

/* Read crime scene reports */
/*
SELECT * FROM crime_scene_reports;
*/

/* Only read theft crime*/
/*
SELECT *
FROM   crime_scene_reports
WHERE  description LIKE '%theft%';
*/
-- the case id we are looking for is 295

/* Read the CS50 duck case report*/
/*
SELECT *
FROM   crime_scene_reports
WHERE  id = 295;
*/
/*
| 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
*/
/* Explore intervies */
/*
SELECT * FROM interviews
WHERE year = 2021
AND   month = 7
AND   day = 28
*/
/*
    | 161 | Ruth    | 2021 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
    | 162 | Eugene  | 2021 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
    | 163 | Raymond | 2021 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
*/

/* Explore bakery security logs */
/*
SELECT *
FROM   bakery_security_logs
WHERE year = 2021
AND   month = 7
AND   day = 28
*/

/* Combine information:
    1. thief parked a car
    2. thief withdraw money from an ATM on Leggett Street
    3. thief had a phone call (less than a minute) and asked the person on the other end of the phone to purchase the flight ticket of the earliest flight out of Fiftyville tomorrow
*/

/* Explore transactions */
/*
SELECT * FROM atm_transactions WHERE atm_location LIKE '%leggett%' LIMIT 10;
*/

/* Explore phonecall */
/*
SELECT * FROM phone_calls LIMIT 10;
*/
/* Try to find the thief using info 1 and 2 */
/*
SELECT name, license_plate, phone_number
FROM people
WHERE
     -- lincense place
     license_plate IN (
        SELECT license_plate
        FROM   bakery_security_logs
        WHERE  year = 2021
        AND    month = 7
        AND    day = 28
     )
AND
     -- money withdraw
     id IN (
        SELECT person_id
        FROM   bank_accounts
        WHERE  account_number IN (
            SELECT account_number
            FROM   atm_transactions
            WHERE  year = 2021
            AND    month = 7
            AND    day = 28
            AND    atm_location = 'Leggett Street'
            AND    transaction_type = 'withdraw'
        )
     )
AND
     -- phone call
     phone_number IN
        (
            SELECT caller
            AS     individual
            FROM   phone_calls
            WHERE  year = 2021
            AND    month = 7
            AND    day = 28
            AND    duration < 60
            UNION
            SELECT receiver
            AS     individual
            FROM   phone_calls
            WHERE  year = 2021
            AND    month = 7
            AND    day = 28
        )
AND
     -- flight
     passport_number IN
     (
        SELECT passport_number
        FROM   passengers
        WHERE
            flight_id IN (
            SELECT id
            FROM   flights
            WHERE  origin_airport_id IN
            (
                SELECT id
                FROM   airports
                WHERE  city = 'Fiftyville'
            )
            AND    year = 2021
            AND    month = 7
            AND    day = 29
            ORDER BY hour ASC, minute ASC
            LIMIT 1
        )
     )
;
*/
/* Potential:
+--------+---------------+
|  name  | license_plate |
+--------+---------------+
| Taylor | 1106N58       |
| Luca   | 4328GD8       |
| Bruce  | 94KL13X       |
+--------+---------------+
*/

/* Explore bakery security logs again*/
/*
SELECT *
FROM   bakery_security_logs
WHERE year = 2021
AND   month = 7
AND   day = 28
AND   (license_plate = '1106N58' OR license_plate = '4328GD8' OR license_plate = '94KL13X')
;
*/
-- Luca or Bruce

/**/


-- Flight id: 36; dest: 4
/*
SELECT id, destination_airport_id
FROM   flights
WHERE  origin_airport_id IN
(
    SELECT id
    FROM   airports
    WHERE  city = 'Fiftyville'
)
AND    year = 2021
AND    month = 7
AND    day = 29
ORDER BY hour ASC, minute ASC
LIMIT 1
;
*/

-- Destination airport
SELECT city FROM airports WHERE id = 4;

-- Accomplice

SELECT name FROM people
WHERE phone_number =
    (SELECT receiver
        FROM phone_calls
        WHERE caller = "(367) 555-5533"
        AND year = 2021
        AND month = 7
        AND day = 28
        AND duration <= 60);
