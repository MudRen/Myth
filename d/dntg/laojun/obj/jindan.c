
#include <ansi.h>
#define ONEDAY 86400

inherit ITEM;

void create()
{
  set_name( HIY"��ת��"NOR , ({"jiuzhuan jindan", "jindan","dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ�Ž���������ɵ�������̫���Ͼ�Ϊ��۵ĵ�Ԫ����ر����ƶ��ɣ���֮�������١�\n");
    set("value", 800000);
    set("no_sell", 1);
    set("no_drop","����ã�\n");
    set("no_give","����ã�\n");
    set("drug_type", "��Ʒ");
  }
  setup();
  call_out("self_dest",600);
}

void self_dest()
{
    object env;
    if(this_object()) {
        if(env=environment(this_object()))
            tell_object(env,name()+"���ڵ��ϲ����ˡ�\n");
        destruct(this_object());
    }
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int food,water;
  object me = this_player();
  int r=me->query_kar();
  if (arg!="jindan" && arg!="dan") 
    return 0;
  
  if (environment()!=me) {
     write("������û�н𵤡�\n");
     return 1;
  }
  if (r<30) r=30;

  message_vision(HIG "$N������ͽ���������������ˡ�\n" NOR, me);
  me->set("dntg/laojun","done");
  if (time()-me->query("jindan_last_eaten")<ONEDAY) return 1;
  if (random(r)>28) {
    tell_object(me, HIG"���ʱ���������彡��ƮƮ���ɣ�\n"NOR);
    me->add("life/life_time",1);
    MONITOR_D->report_system_object_msg(me," eats jindan and gets 1 year life time.\n" );
  me->set("jindan_last_eaten",time());
  } else {
      tell_object(me,HIR"��ͻȻ����ͷ���ۻ�����֫������������Ż��ԭ�����޸������ɵ���Ǧ���ж��ˡ�\n"NOR);
  me->add("bad_jindan",1);
  if (me->query("bad_jindan")>40) {
    me->delete("bad_jindan");
    me->set_temp("death_msg","��ʳ��ʯ�ɵ��������ж�������\n");
    me->die();
    me->delete_temp("death_msg");
    return 1;
  }
      if (!random(3)) {
        tell_object(me,HIR"���͵���������������ҩ��һ���غ������£������ŵ��ĵ����ѣ������ɢ��\n"NOR);
        me->unconcious();
      }
  }
  destruct(this_object());
  return 1;
}
