#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("ԧ�쵨", ({ "yuanyang dan" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                       set("material", "iron");
 set("long", "���ű����Ǿ��Ķ��Ű���������һ˫��\n");
                  }
           setup();
}
