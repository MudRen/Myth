// created by angell 1/1/2001
// room: /d/qujing/huangfeng/zhuzitop.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_pick(string arg);
int  timer_pick(object ob);

void create ()
{
	set ("short", "��������");
	set ("long", @LONG

�������ſ�������ǷŹ��ԭ����һ�ź��Ҵ�С������(ming zhu)��

LONG);

	set("item_desc", ([ /* sizeof() == 1 */
  		"ming zhu" : "һ�Ż�Բ�����ӣ������Ƕ�������ϣ����ӷ��������Ĺ��Σ�
����ȥ�������ʵģ��㲻�����ֹ�ȥ�������ȡ������
",
]));

	set("exits", 
	([ //sizeof() == 1
        "down" : __DIR__"yuan",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));

	set("outdoors", __DIR__);

	setup();
}

void init()
{
   add_action("do_bite","bite");
   add_action("do_bite","yao");
   add_action("do_get","get");
}

int do_bite(string arg)
{
   object me=this_object();
   object who=this_player();
   object ob;
   string realzhu="/d/qujing/huangfeng/obj/dingfengzhu.c";

   if(!arg||(arg!="zhu"&&arg!="����"&&arg!="ming zhu"&&arg!="��" && arg!="mingzhu"))
     return notify_fail("��Ҫҧ˭��\n");

   if(me->query("no_zhu")==0)
       {
       if(realzhu->in_mud())
             ob=new(realzhu->query("replace_file"));
       else ob=new(realzhu);
   
       ob->move(who);
    me->set("no_zhu",1);
    remove_call_out("timer_pick");
    call_out("timer_pick",900,me);
  message_vision(HIC"ֻ��һ��ϼ�������������ǰ��ʱһ����\n"NOR,who);
  message_vision(HIC"$N�ſ��죬����ҧ��һ�����������飡\n"NOR,who);
  who->set_temp("obstacle/huangfeng_zhu_getted",1);
     }
else   message_vision(HIY"$N����ȥҧ�����飬ͻȻ��ǰһ���������ٿ�ʱ����ã��ɢ������ʲô��û�У�\n"NOR,who);
  return 1;
}

int timer_pick(object ob)
{
  ob->delete("no_zhu"); 
  return 0;
}

int do_get(string arg)
{
object who=this_player();
  message_vision(HIC"$N�����α���������Ψ��һ����С�ĵ���ȥ�����������ڲ��������ö����ˣ�\n"NOR,who);
return 1;
}
