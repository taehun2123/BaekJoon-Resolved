-- 문제 구조를 살펴보면, 7월에는 아이스크림 주문량이 많아 같은 아이스크림에 대하여
-- 서로 다른 두 공장에서 아이스크림 가게로 출하를 진행하는 경우가 있다고 한다.
-- 즉 shipment를 JOIN 키로 사용하는 것이 아닌 다른 것으로 사용해야한다는 힌트.
-- 따라서 FIRST_HALF의 기본 키인 FLAVOR을 JOIN.
-- 또, 서로 다른 공장에서 출하하므로, 서로의 주문량 합계를 더하여 
-- 가장 많은 주문량 상위 3가지를 뽑아내야한다.
-- JOIN 테이블을 서브쿼리를 이용하여 다른 테이블의 정보를 가져오고, 
-- 그것들을 JOIN하고 ORDER BY에서 합쳐주는 과정을 이용한다.
SELECT h.FLAVOR
FROM FIRST_HALF h 
JOIN (SELECT FLAVOR, SUM(TOTAL_ORDER) TOTAL
     FROM JULY
     GROUP BY FLAVOR) j
ON j.FLAVOR = h.FLAVOR
ORDER BY h.TOTAL_ORDER + j.TOTAL DESC LIMIT 3