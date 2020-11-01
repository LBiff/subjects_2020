/* 请你写一个sql语句查询各个岗位分数的平均数，并且按照分数降序排序，结果保留小数点后面3位(3位之后四舍五入): */
/* (注意: sqlite 1/2得到的不是0.5，得到的是0，只有1*1.0/2才会得到0.5，sqlite四舍五入的函数为round) */

/* id job score
输出 job avg */


SELECT job, round(AVG(score),3) AS avg
FROM grade
GROUP BY job
ORDER BY avg DESC;


