#include <ansi.h>
#include <room.h>
inherit HELL_ROOM;//ע����MROOM
#include "long.h"
string random_long()
{
        string s_key,strn,str;
        int i,j,k;
        s_key="";str="";
        for(i=0;i<sizeof(add_long);i++) s_key =s_key+i;
         
        j=random(sizeof(add_long));
        
        strn=s_key[(j-2)..j];
        for(i=0;i<=3;i++)
        {
               k= atoi(strn[i..i]);
                str +=add_long[k];
        } 
      return str;
}
        
        
        
void create (int level,int num)
{
        string str;
       object obj;
       int i;
  set ("short", HIW "ħ�߶���" NOR);
/*
  set ("long", @LONG

LONG);
*/
      level=10; num=random(3)+1;
        set("exits", ([
                      "west" : __DIR__"dong10",
                      "south" : __DIR__"dong8",
        
                        ]));
        set("level",level);//�Լ������趨��
        set("alternative_die",1);
        set("hellfireroom",1);
        set("npc_npc",num);//�Լ������趨��
/*
        set("objects",([
                       __DIR__"npc/guai" : num,
   
                        ]));
*/
        str=random_long();
        set("long",str);
// 56          for(i<0;i<num;i++) {
        for(i=0;i<=num;i++) {
         obj=new("/d/hellfire/npc/guai");
       obj->set_name(obj->name(),({"mo guai","evil","shoudong zhe",}));
     obj->add("hell_exp",20000*(random(5)+1));
       obj->move(this_object());
         }
     setup();
     setup2();

}
void init2()
{
}

void reset()
{
        object guai;
        int i,level;

        this_object()->add_temp("npc_times",1);
       if (this_object()->query_temp("npc_times")>10)
       {
        this_object()->set_temp("npc_times",1);
       if(this_object()->qurey("npc_number")> 1){
          for(i=0;this_object()->query("npc_number");i++) {

                guai=new("/d/hellfire/npc/guai");
                level=this_object()->query("level");
                 guai->create(level,level);
                guai->move(this_object());
                                           }
                                              }
         }
        ::reset();
}


int valid_leave (object who, string dir)
{
  object where = this_object ();
  object obj = present ("shoudong zhe",where);
 

  
  if (obj)
    return notify_fail ( obj->name()+"¶�������׹��ƺ�������Ź��㡣\n");

  return ::valid_leave (who, dir);
}

