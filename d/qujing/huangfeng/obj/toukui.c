// created by angell 1/1/2001
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"�ƽ�ս��"NOR, ({ "golden bonnet", "bonnet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���ƽ���ƶ��ɵ�ͷ�����������⡣\n");
                set("material", "gold");
                set("value", 10000);
                set("armor_prop/armor", 20);
        }
        setup();
}

