//pomelowood.c ������������--��ľ
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name(GRN"��ľ"NOR,({"pomelo wood", "wood"}));
        set_weight(20000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
                set("long", "����һ����ľ��\n");
        }
        setup();
}

