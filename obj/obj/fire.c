#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"����"NOR, ({"fire", "huozhe"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "����һ֧��������Ļ��ۣ����˺ڰ��ĵط�����(use)�����ˡ�\n");
                set("unit", "֧");
             set("value", 100);
        }
}

