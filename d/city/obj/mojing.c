/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Creaty by waiwai@2001/06/23

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIB"ī ��"NOR, ({ "mo jing", "jing"  }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��");
		set("long", HIC"һ��������ĺ�ק��ī����\n"NOR);
              set("material", "steel");
		set("task_give", 1);
		set("no_put", 1);
		set("npc_only", 1);
              set("armor_prop/armor", 5);
              set("armor/max_armor", 5);//By waiwai@2001/07/29 added.
		set("armor_prop/intelligence", 5);
		set("armor_prop/personality", 2);
        }
        setup();
}

