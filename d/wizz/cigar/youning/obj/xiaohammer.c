// xiaohammer.c 

#include <weapon.h>
inherit HAMMER;

void create()
{
        set_name("С���Ǵ�", ({ "xiao liuxing hammer", "xiaohammer" }));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��С���Ǵ����ǴӴ��л���֮�\n");
                set("material", "iron");
                set("wield_msg", "$N��С���Ǵ��������������У�����˳�֡�\n");
                set("unwield_msg", "$N�����е�$n���ڱ��ϡ�\n");
        }
        init_hammer(100);
        setup();
}
