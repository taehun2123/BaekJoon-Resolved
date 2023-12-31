-- 코드를 입력하세요
SELECT a.FOOD_TYPE, a.REST_ID, a.REST_NAME, a.FAVORITES
FROM REST_INFO a JOIN (SELECT FOOD_TYPE, MAX(FAVORITES) MAXIMUM FROM REST_INFO GROUP BY FOOD_TYPE) b
ON a.FAVORITES = b.MAXIMUM AND a.FOOD_TYPE = b.FOOD_TYPE
GROUP BY FOOD_TYPE
ORDER BY FOOD_TYPE DESC