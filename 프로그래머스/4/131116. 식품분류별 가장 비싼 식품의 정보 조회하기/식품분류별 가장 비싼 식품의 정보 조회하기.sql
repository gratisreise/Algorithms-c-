SELECT a.CATEGORY, MAX(a.PRICE) AS MAX_PRICE,
       (SELECT PRODUCT_NAME
        FROM FOOD_PRODUCT 
        WHERE CATEGORY = a.CATEGORY
        ORDER BY PRICE DESC
        LIMIT 1) AS PRODUCT_NAME
FROM FOOD_PRODUCT a
WHERE CATEGORY IN ('과자', '국', '김치', '식용유')
GROUP BY CATEGORY
ORDER BY MAX_PRICE DESC