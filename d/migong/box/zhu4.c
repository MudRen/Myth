#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"����"NOR, ({ "jobzhu4" }) );
    set_weight(1);
    set("no_put", 1);
    set("value", 0);
    if( clonep() )
            set_default_object(__FILE__);
    else {
               
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 0);
            set("unit", "��");
            set("material", "paper");
            set("long", "��������֮һ��\n");
          }

    setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        me->add("combat_exp", 800);
        me->add("daoxing",800);
        me->add("potential",150);        
        
        message_vision(HIG "$N�����������ȥ��ֻ����ȫ������˲��٣�\n" NOR, me);
        
        destruct(this_object());
        return 1;
}

