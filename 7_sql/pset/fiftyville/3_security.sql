select id, minute, license_plate from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28 and hour = 10
    and minute between 10 and 25
    and activity = 'exit'
    order by minute;

    select id,hour, minute, activity, license_plate from courthouse_security_logs
    where year = 2020 and month = 7 and day = 28 and hour = 10

    order by hour,minute;