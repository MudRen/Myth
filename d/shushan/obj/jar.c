//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"��ֵ�ƿ��"NOR, ({"jar"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ֵ��飬����������ס��ʲô����������Դ���(dapo)����\n");
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
  add_action("do_dapo", "dapo");
}

int do_dapo(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="jar")   return 0;
  ob = new("/d/shushan/npc/guiwang");
        ob->move(environment(me));
        message_vision(CYN"$N����ƿ�ӣ���Ȼ������ǰ������һ��������\n",me);  
        write("������������������ң��Ҿ��ǹ�����Ϊ�˱�����...��\n");
        write("������������...��...��...��...�㣡����\n"NOR);
        destruct(this_object());
        return 1;
}

