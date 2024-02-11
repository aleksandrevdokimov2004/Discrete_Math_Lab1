# ЛАБОРАТОРНАЯ РАБОТА №1. МАТРИЧНЫЕ СПОСОБЫ ПРЕДСТАВЛЕНИЯ ГРАФОВ
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-5C2D91.svg?style=for-the-badge&logo=visual-studio&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
## Цель работы
Изучение матричных способов представления графов 
## ОСНОВНЫЕ ОПРЕДЕЛЕНИЯ
Граф G задается множеством точек или вершин x1,x2,...,xn (которое обозначается через X) и множеством линий или ребер a1,a2,…,an (которое обозначается символом А), соединяющих между собой все или часть этих точек. Таким образом, граф G полностью задается (и обозначается) парой (X, А).

Если ребра из множества А ориентированы, что обычно показывается стрелкой, то они называются дугами, и граф с такими ребрами называется ориентированным графом. Если ребра не имеют ориентации, то граф называется неориентированным (рисунок 1(б)). В случае когда G=(X, А)  является ориентированным графом и мы хотим пренебречь направленностью дуг из множества А, то неориентированный граф, соответствующий G, будем обозначать как G=(X, А).
## ПОРЯДОК ВЫПОЛНЕНИЯ РАБОТЫ
 - Получить задание у преподавателя в виде одного из двух способов матричного представления графа: а) матрица смежности; б) матрица инцидентности
 - Составить алгоритм программы, реализующей перевод из заданного способа матричного представления графа в другой, учитывая при этом исходный тип графа (неориентированный, ориентированный, смешанный). 
 - Создать программу, реализующую перевод из заданного способа матричного представления графа в другой. Предусмотреть консольный ввод исходных данных и вывод результатов работы программы на экран.