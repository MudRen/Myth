// ����ʥ�� by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW "����ʥ��" NOR, ({ "lingyue cloth", "cloth","lingyue" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�����ɽ����е��ɽ���֬�Ƴɵ��·���\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 50);
                set("armor_prop/personality", 5);
                set("dodge", 200);
        }
        setup();
}

