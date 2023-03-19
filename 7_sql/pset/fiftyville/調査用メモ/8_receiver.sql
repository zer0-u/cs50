-- 泥棒の電話番号
select phone_number from people
    where license_plate in
        (select license_plate from courthouse_security_logs
            where year = 2020 and month = 7 and day = 28 and hour = 10
            and minute between 10 and 25
            and activity = 'exit'
        )
    and passport_number in
        (select passport_number from passengers where flight_id = 36)
    and phone_number in
        (select caller from phone_calls
            where year = 2020 and month = 7 and day = 28
            and duration < 60
        )
;

-- (996) 555-8899
-- (892) 555-8872
-- (375) 555-8161
select * from people
    where phone_number in ('(996) 555-8899','(892) 555-8872','(375) 555-8161');