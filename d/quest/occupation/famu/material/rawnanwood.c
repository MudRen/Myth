//nanwood.c ������������--�ľԭľ
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name(HIR"�ľԭľ"NOR,({"raw nanwood", "wood"}));
        set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
                 set("no_put",1);
                set("long", "����һ��ԭľ����Ҫ�����ӹ����ܵõ����õ�ľ�ġ�\n");
        }
        setup();
}
