/* 获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

SELECT emp_no, salary
FROM salaries
WHERE salary=(SELECT salary FROM salaries GROUP BY salary ORDER BY salary DESC LIMIT 1,1);


/* 查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，你可以不使用order by完成吗
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`));
CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

SELECT e.emp_no, s.salary, e.last_name, e.first_name
FROM employees AS e INNER  JOIN salaries AS s
    ON e.emp_no=s.emp_no
where e.emp_no=(SELECT emp_no FROM salaries GROUP BY salary ORDER BY salary DESC LIMIT 1, 1) AND s.to_date='9999-01-01';


SELECT e.emp_no, s.salary, e.last_name, e.first_name
FROM employees AS e INNER  JOIN salaries AS s
    ON e.emp_no=s.emp_no
WHERE s.salary=(SELECT max(salary) FROM salaries WHERE salary < (SELECT MAX(salary) FROM salaries WHERE to_date='9999-01-01'));