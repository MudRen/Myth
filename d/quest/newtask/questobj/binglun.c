#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIC"�������"NOR, ({ "qingyu binglun" }) );
        set_weight(30); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                       set("material", "iron");
 set("long", "����ľ������������������ɵ����ű�����\n");
                       }
        setup();
}
