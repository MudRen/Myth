#include <ansi.h>
#include <room.h>

inherit HELL_ROOM;//注意是MROOM

void create (int level,int num)
{
  set ("short", HIG "毒蛇洞口" NOR);
  set ("long", @LONG
你从厚厚的苔藓中钻了出来，赫然发现自己原来进入了[毒蛇洞]内。
    深处的寒冰隐隐发出冷光。来到这里，你能感觉从旁边更深的洞里
散发出的难忍的阵阵腥臭味道。
LONG);
     level=10; num=random(2)+1;
    set("exits", ([
              "east" : __DIR__"dushedong",
              "out" : "/d/hellfire/hellfire1/bing17.c",
              "northeast" : __DIR__"dushedong9",
              "southeast" : __DIR__"dushedong7",

                 ]));
        set("level",level);//自己可以设定！
      set("alternative_die",1); 
       set("hellfireroom",1); 
        set("npc_npc",num);//自己可以设定！
    set("objects",([
         "/d/hellfire/npc/guai3" : num,
                  
                 ]));

  setup();
  setup2();
   
}
void init2()
{
}
/*
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIW "\n\n你被冰冻得动弹不得。\n\n" NOR);
 ob->start_busy(3);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
*/
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
  object obj = present ("monsters",where);



  if (obj)
    return notify_fail ( obj->name()+"露出两眼凶光要吃了你。\n");

  return ::valid_leave (who, dir);
}

