// axe.c

inherit ITEM;
inherit F_UNIQUE;

#include <ansi.h>

void create()
{
        set_name(HIR"��"NOR, ({"shen fu", "fu", "axe"}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
WHT"һ�Ѻ�����ĸ��ӣ���˵���Կ���ٵأ�����û����֪����������������\n"NOR);
                set("value", 0);
                set("material", "iron");
                set("no_drop", "���������������ⶪ����\n");
                set("no_give", HIR"��"NOR+"��������ˣ� \n");
                set("no_get", "��ʲô�������񣿼������Ķ�û���ڿ죡 \n");
                set("no_put",1);
        }

        setup();
}

