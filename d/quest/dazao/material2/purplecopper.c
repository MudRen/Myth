//purplecopper.c ������������--��ͭ
// Created by kuku@sjsh 2003.2.13

#include <ansi.h>
inherit ITEM;  
void create() 
{
         set_name(MAG"��ͭ"NOR,({"purple copper", "metal"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_drop","��Ҫ�Ҷ����ⶫ������ʹ��\n");
                set("long", "����һ����ͭ��\n");
        }
        setup();
}


