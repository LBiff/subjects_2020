/* 写一个sql语句查询用户分数大于其所在工作(job)分数的平均分的所有grade的属性，并且以id的升序排序 */

SELECT grade.*
FROM grade INNER JOIN (SELECT job, round(SUM(score) * 1.0 / count(id), 3) AS avg
     FROM grade
     GROUP BY job) AS t
     ON grade.job=t.job
WHERE grade.score > t.avg
ORDER BY id;
