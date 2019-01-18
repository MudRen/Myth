// Room: /d/qujing/wudidong/lock.c
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "ʯ��");
  set("long", @LONG
      
̤�����������ް���������ֻ������ǰ�����������䳱ʪ������ù
��֮�����������Զ��ͻȻ����΢�������죬���������ڵ���������
����Ұ�޵��ƣ�����ë��ֱ����
LONG);
  set("exits", ([ /* sizeof() == 2 */
		 "southeast" : __DIR__"houdong",
		 "north" : __DIR__"trap",
		 ]));
  set("no_clean_up", 0);

  setup();
}
int valid_leave(object me, string dir)
{
  int mykar, mycor, factor;

  mycor=(int)me->query_cor();
  mykar=(int)me->query_kar();
  factor=mykar*2-mycor;
  if(factor<1) factor=1;
  if (dir=="southeast")
    {
      me->delete_temp("mark/wudidong_no_hope_of_knowing_trap");
      me->delete_temp("mark/wudidong_aware_of_trap");
    }
  if (me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
      return ::valid_leave(me, dir);
  if (dir =="north")
  {
      if(random(factor)>=5)
	{
	  tell_object(me, CYN "������������Щ���ԣ�Ҳ��֪Ϊʲô���ƺ���ʲô������Ҫ��ȥ��(disarm)��\n" NOR);
	  me->set_temp("mark/wudidong_aware_of_trap", 1);
	}
      else
        {
	  tell_object(me, CYN "������������Щ......\n" NOR);
          me->set_temp("mark/wudidong_no_hope_of_knowing_trap", 1);
	}
    }
  return ::valid_leave(me, dir);
}
