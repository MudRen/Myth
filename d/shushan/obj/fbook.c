//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIR"��ֵ���"NOR, ({"fbook"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ֵ��飬���̲�ס��򿪿�һ�¡�\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  add_action("do_open", "open");
}

int do_open(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="book")   return 0;
        if(me->query_temp("shushan/open_book",1))
        return 0;
  ob = new("/d/shushan/npc/b_fairy");
        ob->move(environment(me));
        message_vision(CYN"$N�����Ǳ���ֵ��飬��Ȼ������ǰ������һλ�׷����ˡ�\n",me);  
        write("�׷����˵�������˭�����ҿ��飿��\n");
        write("�׷����˵�����ԭ���Ǹ�С����Ӧ�ý���...����(answer)�𣿡�\n"NOR);
        me->set_temp("shushan/open_book",1);
        destruct(this_object());
        return 1;
}


