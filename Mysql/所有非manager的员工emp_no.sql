/* 获取所有非manager的员工emp_no
CREATE TABLE `dept_manager` (
`dept_no` char(4) NOT NULL,
`emp_no` int(11) NOT NULL,
`from_date` date NOT NULL,
`to_date` date NOT NULL,
PRIMARY KEY (`emp_no`,`dept_no`));
CREATE TABLE `employees` (
`emp_no` int(11) NOT NULL,
`birth_date` date NOT NULL,
`first_name` varchar(14) NOT NULL,
`last_name` varchar(16) NOT NULL,
`gender` char(1) NOT NULL,
`hire_date` date NOT NULL,
PRIMARY KEY (`emp_no`)); */

//not in 查询
SELECT emp_no
FROM employees
WHERE emp_no NOT IN(SELECT emp_no from dept_manager);

//左外联查询
SELECT e.emp_no 
FROM employees AS e LEFT JOIN dept_manager AS d ON e.emp_no = d.emp_no
WHERE d.dept_no IS NULL;

