#include <ansi.h>
#include <room.h>

inherit HELL_ROOM;//ע����HELL_ROOM ��ROOM

void create (int level,int num)
{
  set ("short", HIW "��������" NOR);
  set ("long", @LONG
�������������沼����ɫ�����������������亮�⡣
    ��������©��һ��΢���Ĺ⡣
LONG);
     level=10;num=3;
//
//level �ǹֵļ���10-30, num �ǹֵ���Ŀ
    set("exits", ([
 /*              "east" : __DIR__"luohun",
               "west" : __DIR__"dilie",
               "north" : __DIR__"huaxue",
               "south" : __DIR__"fenghou",
  */
               "south" : __DIR__"bing20",
                 ]));
        set("level",level);//�Լ������趨��
// �����Ժ�ֵĵĵȼ�
      set("alternative_die",1); 
       set("hellfireroom",1); 
//������������־��cmds npc �ж����裡
//
        set("npc_num",num);//�Լ������趨��
// �����Ժ�ֵĵ���Ŀ
    set("objects",([
         "/d/hellfire/npc/guai" : num,
                  
                 ]));

  setup();
  setup2();
// setup2();������
   
}
void init2()
{
     add_action("do_up","up");
     add_action("do_up","u");
}
/*
int blowing(object ob)
{
 int i;
 int damage;
        if(  ob && environment(ob) == this_object())
{
 tell_object(this_object(), HIW "\n\n�㱻�����ö������á�\n\n" NOR);
 ob->start_busy(3);
 if( environment(ob) == this_object())
 call_out("blowing",random(30)+1, ob);
}
 else
 return 1;
}
*/
/* �����Ǹ���ʱ�䡢 ���ݵ��趨*/
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

int valid_leave (object me, string dir) 
{ 
       me=this_player();
  
  if( dir == "up"){if (!userp(me) ) return notify_fail("ͻȻð��һ��������ֹ�˹���ǰ����\n");}
 
  
           return 1;
} 


int do_up()
{
      object me=this_player();
//
       if(userp(me)) me->move("/d/city/kezhan");
      return 1;
}
