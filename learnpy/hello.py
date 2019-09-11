# -*- coding: utf-8 -*-
from operator import sub
import random
import time
import re

def demo_string():
    stra = " \nhello world\n".lstrip().rstrip()
    print(stra)
    print(stra.capitalize())
    print(stra.replace('world','me'))
    print(stra.startswith('hello'))
    print(stra.endswith('s'))
    print(len(stra))
    print('_'.join(['a','b','c']))
    print(stra+'_'.join(['a','b','c']))
    pass

def demo_operator():
    print(1+2)
    print(1>2)
    print(not 1>2)
    print(1<<3)
    print(type(3),type(4.0),type(True),type(''),type(demo_string))
    x = 9
    y = 8
    x , y = y , x
    print(x,y)
    print(max(x,y))
    print(len([1,2,3,4,5]))
    print(abs(-23))
    for i in range(0,10,2):
        print(i)
    print(range(0,10,2))
    print(dir(list))
    print(dir(dict))
    print(dir(tuple))
    print(dir(set))
    print(dir(str))

def demo_controlflow():
    score = 68
    if score>85:
        print('B')
    elif score>70:
        print('C')
    else:
        print('D')

    while score<100:
        score+=10;
        print(score)

def demo_list():
#     list tuple set dic
#     vector ArrayList
    lista = [1,3,4,5,8,0]
    print(lista)
    listb = ['a','b','c']
    print(listb)
    print(lista+listb)
    lista.extend(listb)
    print(lista)
    lista.append('last')#as stack
    print(lista)
    lista.pop()
    print(lista)
    lista.insert(0,'first')#as queue
    print(lista)
    print([[0 for j in range(7)] for i in range(8)][7][6])
    listc = (2,3,5,7,7)#tuple
    print(listc)
    print(listc.count(7))

def demo_dic():
    dicta = {1:1,2:4,4:16,9:81}
    print(dicta)
    print(dicta.keys())
    print(dicta.values())
    print(dicta.get(3))
    for key,value in dicta.items():
        print(key,':',value)
    dictb = {'+':lambda a,b:a+b,'-':sub}
    print(dictb['+'](2,3))
    print(dictb['-'](7,9))
    del dictb['-']
    print(dictb)
    dictb.pop('+')
    print(dictb)
    dictb['x'] = 'X'
    print(dictb)

def demo_set():
    s = set([2,3,4,4])
    s2 = set([1,2])
    s3 = set([10])

    print(s & s2)
    print(s | s2)
    print(s - s2)
    print(s.union(s2))
    print(s.intersection(s2))
    print(s.isdisjoint(s3))

class Person:
    def __init__(self,firstname,lastname):
        self.firstname = firstname
        self.lastname = lastname
        pass
    def __repr__(self):
        return self.firstname+' '+self.lastname

class Student(Person):
    def __init__(self,firstname,lastname,uid):
        Person.__init__(self,firstname,lastname)
        self.uid = uid

    def __repr__(self):
        return str(self.uid)+' '+self.firstname + ' ' + self.lastname

def demo_oop():
    person = Student('XK','Guo',101);
    print(person)

def demo_exception():
    try:
    #     1/0
        age = 9;
        if age<10:
            raise Exception('too young')
    except Exception as e:
        print(e)
    finally:
        print('final')

def demo_random():
    random.seed(time.time())
    print(random.randint(1,888))
    lista = list(range(1,10,2))
    print(random.choice(lista))
    print(lista)
    random.shuffle(lista)
    print(lista)

def demo_regexp():
    stra = '_12add45tyu0www@gmail.com'
    pt = re.compile('\d+')
    pt2 = re.compile('[\w]+@[\w]+\.com')
    print(pt2.findall(stra))
    print(pt2.fullmatch(stra))



if __name__ == '__main__':
    # demo_string()
    # demo_operator()
    # demo_controlflow()
    # demo_list()
    # demo_random()
    demo_regexp()