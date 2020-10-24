/* 获取员工其当前的薪水比其manager当前薪水还高的相关信息，当前表示to_date='9999-01-01',
结果第一列给出员工的emp_no，
第二列给出其manager的manager_no，
第三列给出该员工当前的薪水emp_salary,
第四列给该员工对应的manager当前的薪水manager_salary
CREATE TABLE `dept_emp` (
`emp_no` int(11) NOT NULL,
`dept_no` char(4) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));

CREATE TABLE `dept_manager` (
`dept_no` char(4) NOT NULL,
`emp_no` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));

CREATE TABLE `salaries` (
`emp_no` int(11) NOT NULL,
`salary` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`from_date`)); */

/* emp_no	manager_no	emp_salary	manager_salary
 */

SELECT emp.emp_no AS emp_no, manager_no,emp_salary,manager_salary
FROM 
(SELECT dt.dept_no, dt.emp_no, s.salary AS emp_salary
FROM dept_emp AS dt INNER JOIN salaries AS s ON dt.emp_no=s.emp_no
WHERE s.to_date='9999-01-01') AS emp
INNER JOIN 
(SELECT dm.dept_no, dm.emp_no AS manager_no, s.salary AS manager_salary
 FROM dept_manager AS dm INNER JOIN salaries AS s ON s.emp_no=dm.emp_no
 WHERE s.to_date='9999-01-01') AS man
 ON emp.dept_no=man.dept_no
WHERE emp_salary > manager_salary

