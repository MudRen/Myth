//负责存放人质

#include <ansi.h>
#include "place.h"
string* guainame=({
        "香兰","xiang lan",
        "阿奴","a nu",
        "月如","yue ru",
        "灵儿", "lin er",
        "坂崎尤莉", "yuri",
        "李香绯", "xiangfei",
        "麻宫雅典娜", "athena",
        "玛丽", "mary",
        "不知火舞", "mai",
        "莉安娜", "leona",
});
        
string* xianname=({
        "香兰","xiang lan",
        "阿奴","a nu",
        "月如","yue ru",
        "灵儿", "lin er",
        "坂崎尤莉", "yuri",
        "李香绯", "xiangfei",
        "麻宫雅典娜", "athena",
        "玛丽", "mary",
        "不知火舞", "mai",
        "莉安娜", "leona",

});
string* prename=({
        "清纯可爱 ",
        "美丽绝伦 ",
        "艳丽动人 ",
        "活泼开朗 ",
        "热情奔放 ",
        });

int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
    mapping girl;
//yudian
//    int t;
//    t=me->query("bad_mudage");

    if(mapp(girl=me->query("girl"))){
        if(me->query("mud_age")-me->query("girl_mudage")<480
          && me->query("mud_age")>me->query("girl_mudage"))
//        if(time()<t+480)
         return ("不是让你替我抓回"+girl["place"]+"的"+girl["name"]+"("+girl["id"]+")么？\n");
        else{
         command("你真是没用，我再给你一次机会！");
//         me->add("office_number",-1);
        }
    }
//yudian 
     if(me->query("mud_age")-me->query("girl_mudage")<60
        && me->query("mud_age")>me->query("girl_mudage"))
//     if(t>0 && time()<t+60)
        return ("嗯，不错，你先休息一下吧！");  
    add_new_yao(me);
    girl=me->query("girl");
    if(girl["type"]=="xian")
       return ("听说"+girl["name"]+"("+girl["id"]+")现在在"+girl["place"]+"一带游山玩水，\n你马上把她给我抓来，嘿嘿！\n"); 
    else
        return ("听说"+girl["name"]+"("+girl["id"]+")现在在"+girl["place"]+"一带游山玩水，\n你马上把她给我抓来，嘿嘿！\n"); 
}

int add_new_yao( object me)
{
    string /*my_id,*/my_cls,type;
    string sname;
    string* yaoname;
    int my_exp,index;
    mapping skill_status;
    mapping girl;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
    if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    girl=(["type" : type]);
    girl+=(["id" : yaoname[index+1] ]);
    sname=prename[random(sizeof(prename))]+yaoname[index];
    
    girl+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
   my_exp=0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&yaoname[index]!="literate")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    girl+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    girl+=(["location" : sname]);
//yudian
    me->set("girl_mudage",me->query("mud_age"));
//    me->set("girl_mudage",time());

    me->set("girl",girl);
  
    if(!(where=find_object(girl["location"])))
             where=load_object(girl["location"]);

    yao=new("/d/obj/npc/girl");
    yao->move(where);
    yaoname=explode(girl["id"]," ");
    yaoname=({girl["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");    
    yao->set_name(me->name()+"的"+girl["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),girl["type"]);
    
    return 1;
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping girl=me->query("girl");
    if(!mapp(girl))return 0;
    loclist=explode(girl["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&girl["id"]==yaoid);     
    return 0;   
}

 
