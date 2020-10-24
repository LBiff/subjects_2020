/* 对所有员工的当前(to_date='9999-01-01')薪水按照salary进行按照1-N的排名，相同salary并列且按照emp_no升序排列
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

/* emp_no	salary	rank */


//知识点：窗口函数

SELECT emp_no, salary, dense_rank() over (ORDER BY salary DESC) AS rank
FROM salaries
WHERE to_date='9999-01-01'
ORDER BY rank, emp_no

