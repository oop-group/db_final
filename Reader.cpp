#include "Reader.h"
#include "utils.h"
#include<iostream>
#include<string>
#include<sstream>
#include<cassert>
#include<algorithm>
using namespace utils;
using namespace std;

shared_ptr<Instruction> Reader::read(istream& fin){
    static istringstream ss;
    static string info;
    getline(fin,info,';');
    ss.str(info);
    ss.clear();
    string mark1,mark2;
    ss>>mark1>>mark2;
    mark1=tolower(mark1);
    mark2=tolower(mark2);
    if(mark1=="create"&&mark2=="database"){
        //create database
        return make_shared<CreateDataBaseInst>(info);
    }else if(mark1=="drop"&&mark2=="database"){
        //drop database
        return make_shared<DropDataBaseInst>(info);
    }else if(mark1=="use"){
        //use
        return make_shared<UseInst>(info);
    }else if(mark1=="show"&&mark2=="databases"){
        //show databases
        return make_shared<ShowDataBasesInst>(info);
    }else if(mark1=="create"&&mark2=="table"){
        //create table
        return make_shared<CreateTableInst>(info);
    }else if(mark1=="drop"&&mark2=="table"){
        //drop table
        return make_shared<DropTableInst>(info);
    }else if(mark1=="show"&&mark2=="tables"){
        //show tables
        return make_shared<ShowTablesInst>(info);
    }else if(mark1=="show"&&mark2=="columns"){
        //show columns from
        return make_shared<ShowColumnsFromInst>(info);
    }else if(mark1=="insert"){
        //insert into
        return make_shared<InsertIntoInst>(info);
    }else if(mark1=="delete"){
        //delete from
        return make_shared<DeleteFromInst>(info);
    }else if(mark1=="update"){
        //update
        return make_shared<UpdateInst>(info);
    }else if(mark1=="select"){
        //select
        return make_shared<SelectInst>(info);
    }else{
        return NULL;
    }
}

