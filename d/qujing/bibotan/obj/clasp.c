#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(YEL "����" NOR, ({ "clasp" }) );
        set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������೤����������Ů��������ͷ���ġ�\n");
                set("material", "silver");
                set("unit", "��");
                set("value", 300);
                set("armor_prop/armor", 1 );
		set("wear_msg", "$N����Ľ�$n����ͷ���ϡ�\n");
		set("remove_msg", "$N����Ľ�$n��ͷ����ȡ��������\n");
		set("female_only", 1);
        }
        setup();
}

