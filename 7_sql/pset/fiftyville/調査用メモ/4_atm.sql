select id, account_number,amount from atm_transactions
where year = 2020 and month = 7 and day = 28
and atm_location = 'Fifer Street'
and transaction_type = 'withdraw'
order by id;