// jiuzhouxue.c
// icecream 2001/4/8
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("����ѩ", ({"jiuzhou xue", "xue", "cloth"}));
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3000);
                set("material", "cloth");
                set("armor_prop/armor", 90);
                set("armor_prop/dodge", 5);
                set("armor_prop/armor_vs_spells", 20);
                set("armor_prop/armor_vs_force", 20);
                set("wear_msg", "$N���Ͼ���ѩ��ֻ�������Ʈ��������ѩ����\n");
               }
        setup();
}


