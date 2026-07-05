-- Write your query below
WITH placed AS (
  SELECT DISTINCT customer_id from orders
)

select name from customers where id not in (select * from placed);