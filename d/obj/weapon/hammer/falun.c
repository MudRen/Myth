#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "falun","lun","hammer" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                  set("long", "�����ķ�����ûʲô��ͷ\n");
                set("value", 3000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������л��˼��¡�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_hammer(40);
        setup();
}
