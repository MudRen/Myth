#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC "�����̺�" NOR, ({ "biyan hu", "biyan", "biyan"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", HIC "�մ��յñ������һ�㣬�Դ��մ����Ƶı��̺���\n" NOR);
                set("value", 15000);
        }
}

