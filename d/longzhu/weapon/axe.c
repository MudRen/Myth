// ������ by Cigar

#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(HIW"������"NOR, ({"guixian axe", "fu", "axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                      "�˸��ǹ��ɵ�����ר��,�ǰ��񸫡�n");
                set("value", 30000);
                 set("material", "gold");
                set("wield_msg",
                           "$N�ó�һ��$n�������У���ǰ����һ�����⣬����Ϊ֮��ɫ��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

   init_axe(120);
        setup();
}

