// tongjia.c
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("��ͭ��", ({"bronze armor","tongjia","jia","armor"}));
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ����Ӳӵ���ͭ�ס�\n");
                set("value", 4000);
                set("material", "steel");
                set("armor_prop/armor", 45);
		set("armor_prop/dodge", -10);
             }
			 setup();
}
