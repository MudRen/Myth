#include <ansi.h>
inherit F_AUTOLOAD;  
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIC "�߿�С��ˮ���ʹ�" NOR , ({ "shuijing guan", "guan", "gold hat" }) );

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�������ʯ����Өˮ����ʯ��ڣ��߿�վվ��С���ͷ�ڡ�\n");

                set("material", "steel");
                set("value", 400);
                set("no_sell", 1);
                set("no_drop", 1);
                set("monitord", 1);
                set("no_give", 1);

                set("no_get", 1);

                set("armor_prop/armor", 20);
//                set("armor_prop/intelligence", 10);
                set("armor_prop/intelligence", 15);
                set("armor_prop/personality", 25);

        }
        setup();
}

int query_autoload() { return 1; }
