// bianshi dan.c ��ʬ��
#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();
void init()
{
    if(this_player()==environment())
      add_action("do_eat", "eat");
}
void create()
{
set_name("��ʬ��", ({"bianshi dan","dan"}));
set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
  set("long", "����������ħǱ�����͵Ĺ�ҩ,��ʳ���棬�������gold�������!\n");
set("unit", "��");
 set("value", 0);
              set("is_monitored",1); 
        }
}
int do_eat(string arg)
{
  object me = this_player();

           log_file("player/dcityobjd",
                   sprintf("%s(%s) eat dan on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) ); 
//me->add("combat_exp", 10000 );
me->add("potential", -50000 );
//me->add("daoxing", 30000 );
me->delete("balance");
// 34  me->add("MKS",10);
//me->add("mieyao/number",30);
//me->add("mud_age",3600);
message_vision("$N������һ�ű�ʬ��,ʱ����˿��ܻ�����Ϊ��ʬ��\n", me);
tell_object(me,HIR + BLINK+ "���Ȼ֪����������⣬�����ٱ���ʦ����ʱ��һ��С�ĳͷ���\n"NOR); 
tell_object(me,HIG+BLINK "����ʧ�����д�\n�㶪ʧ������Ǳ�ܣ�\n���Ҽ�¼�ڰ��Ⱥ���ʦ����\n"NOR); 
  destruct(this_object());
  return 1;
}
