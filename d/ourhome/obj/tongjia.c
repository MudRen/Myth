// tongjia.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(YEL "��ͭ��" NOR, ({"tong jia","tongjia","jia","armor"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ����Ӳӵ���ͭ�ס�\n");
                set("value", 10000);
                set("material", "iron");
                set("armor_type", "cloth");
                set("armor_prop/armor", 50);
             }
}
