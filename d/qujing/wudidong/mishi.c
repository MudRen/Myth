// /d/qujing/wudidong/mishi.c
// created by mes, updated 6-20-97 pickle

#include <room.h>
inherit ROOM;

void reset();

void create()
{
  set ("short", "����");
  set ("long", @LONG

������޵׶���һ��֧����Ҳ�����󾫵�����������������֮�⣬
�����������˽��������䲼�õ�ʮ�ּ򵥣��������������һ��
ʮ����Ŀ����̨(tai)��
LONG);
  set("item_desc",([
		    "tai" : "
����һ���������ϼ���������ɵ���̨������͸�ޡ���������������
��֮�á�̨�Ͽ��ż������Ĵ��֣�

\t\t\t��ħ��\n\n
\t\t  ������������ٲ���
\n",
		    ]));
  set("exits", ([ /* sizeof() == 2 */
		 "out" : __DIR__"gongshi",
		 ]));
  set("no_clean_up", 1);
  set("if_bed", 1);
  set("sleep_room", 1);
  set("outdoors", 0);
  setup();
}       
void init()
{
  add_action("do_climb", "climb");
  add_action("do_climb", "pa");
  add_action("do_lian", "lianxi");
  add_action("do_lian", "xiuxing");
}
int do_climb(string arg)
{
  object me=this_player();
  if ( !arg || (arg !="tai" && arg != "off" && arg != "down" && arg!="xia") )
    return notify_fail("��Ҫ��ʲô��\n");
  if (arg == "tai")
    {
      if ((int)me->query_temp("mark/�޵׶���ħ̨climbed"))
	return notify_fail("���Ѿ�����̨���ˣ����������Ķ�ȥ��\n");
      message_vision("$N����һԾ��������ħ̨ȥ�ˡ�\n", me);
      me->set_temp("mark/�޵׶���ħ̨climbed", 1);
      return 1;
    }
  if(!(int)me->query_temp("mark/�޵׶���ħ̨climbed"))
    return notify_fail("�㲻��̨�ϡ�\n");
  message_vision("$N��̨������������\n", me);
  me->delete_temp("mark/�޵׶���ħ̨climbed");
  return 1;
}
int do_lian()
{
  object me=this_player();
  int myspells, myspi, learned, sencost;
  if ((int)me->query_temp("mark/�޵׶���ħ̨climbed") != 1)
    return notify_fail("ֻ��������ħ̨�ſ�������\n");
  if((  (int)me->query_skill("dao", 1)>50
     || (int)me->query_skill("taiyi",1)>50
     || (int)me->query_skill("gouhunshu", 1)>50
     || (int)me->query_skill("moonshentong", 1)>50
     || (int)me->query_skill("buddhism", 1)>50
     || (int)me->query_skill("dengxian-dafa", 1)>50
     || (int)me->query_skill("baguazhou", 1)>50)
     && !wizardp(me))
    return notify_fail("��֪Ϊ���������������������ħ̨��ħ�꽻�ϣ�Ҳ��
�����еķ�����ѧ��̫���ˡ�\n");
  myspells=(int)me->query_skill("spells", 1);			
  if(me->query_skill("yaofa", 1)>=myspells)
    return notify_fail("��Ļ���������Ϊ���������������ħ̨��ħ�꽻�ϡ�\n");
  myspi=(int)me->query_spi();
  learned=(myspells+myspi)/6;

  if( myspells < 100 )
  	sencost = 30+(myspells/10);
  else  
 	sencost = 30+(myspells/5);

  if ((int)me->query("sen")<=sencost)
      return notify_fail("�����ǲ��壬������ȥ����Σ�յģ�\n");
  if(me->query("mana")<=(sencost/2))
      return notify_fail("��ķ������㣬�����������������\n");
  me->delete_temp("spellslevel");
  me->delete_temp("d_mana");
  me->delete_temp("apply/name");
  me->delete_temp("apply/id");
  me->delete_temp("apply/short");
  me->delete_temp("apply/long"); 
  me->receive_damage("sen", sencost);
  me->add("mana", -(sencost/2));
  tell_object (me, "��ġ����������н�չ��\n");
  me->improve_skill("yaofa",learned);
  if (random(100+me->query_kar()*10)<10)
  //mon 1/23/98. old formula was <1, I changed to <10.
  //don't know exactly, but <1 seems impossible.
  {
    message_vision("$N����˯�˹�ȥ��\n", me);
    me->delete_temp("mark/�޵׶���ħ̨climbed");
    me->move("/d/ourhome/honglou/main");
    if (random(40-me->query_kar())<10)
	me->set("dream_place", "/d/qujing/wudidong/mishi");
  }
  return 1;
}

int valid_leave(object me, string dir)
{
  if(dir=="out" && (int)me->query_temp("mark/�޵׶���ħ̨climbed")==1)
    return notify_fail("�ȴ�̨������ȥ�ɣ�\n");
  return ::valid_leave(me, dir);
}
