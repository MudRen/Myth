//Cracked by Roath

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��ǰ����һ����̨���Ʒ��ƽʱ�������Ǹ��ط�����ʩ�
��Ҳ������С������������飬�г�һ���Լ�Ҳ�����ɵ�
����
LONG);

  set("exits", ([
        "north"   : __DIR__"in3",
        "south": __DIR__"in1",
      ]));
      set("objects",([
        __DIR__"npc/yaojing.c":2,
      ]));
  setup();
}
void init()
{	object obj;
        object ob = this_player();
	string dan= "dingfeng dan";
	
       if (! ob->query_temp("apply/name") 
	||ob->query_temp("apply/name")[0] != "[31m��������[m"
	||!objectp(obj = present(dan, ob)))
        {
		
        message_vision(HIY"��Ȼ�Ʒ�ִ�һ������ôû��������ˣ�\n"NOR,ob);
        message_vision(HIY"ֻ���Ʒ�ִ���һ�ģ�������������硣\n"NOR,ob);
        message_vision(HIY"ֻ��$N�����еķ�ɳһ����������ա�\n"NOR,ob);
        ob->apply_condition("eyeill",50);
	ob->unconcious();
	ob->set_temp("winded",1);
	
	if( ob->query_temp("lingji1_done") == "yes" )
	{
	ob->move("/d/qujing/huangfeng/shanlu2");
        return;
	}
	ob->move("/d/qujing/huangfeng/shanlu2new");
	}
        return;
}
