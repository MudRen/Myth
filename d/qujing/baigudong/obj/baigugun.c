//baigugun writted buy smile 12/08/98
#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIW "�׹ǹ�" NOR, ({"baigu stick","stick"}));
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "wood");
                set("wield_msg", "$N���ٺ١���Цһ��,����һ��$n�������С�\n");
        }
        init_stick(50);
        setup();
}

