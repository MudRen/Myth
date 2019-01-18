// dragon-ring.c
// Modified By Longer

#include <armor.h>
#include <ansi.h>

inherit FINGER;
inherit F_UNIQUE;

void init();
void create()
{
        set_name(RED"����"MAG"���ƽ�" NOR, ({ "ziyun ring", "ring", "jiezhi" }) );
        set("long", "һö����ɽ����ʯ��̳�������״�Ľ�ָ��\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/intelligence", 15);
                set("value", 200);
        }
        setup();
}
// ����ʱ������
void init()
{
        if( (int)this_object()->query("created") != 1 )
        {
                this_object()->set("created", 1);
                remove_call_out ("destroy_ring");
                call_out ("destroy_ring", 18000);//5 hours

        }
}

void destroy_ring()
{
        message_vision(HIC"���ϴ�������������"NOR + (string)this_object()->query("name") + HIY"����һ��������ֱ��������ȥ��\n"NOR, environment(this_object()));
        destruct(this_object());
}

