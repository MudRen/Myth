#include <weapon.h>
#include <ansi.h>
inherit THROWING;
void create()
{
        set_name("����", ({ "tie" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                       set("material", "iron");
 set("long", "������������Ķ��Ű����������нǣ��������һ�㣬�����������ι�о綾�������ޱȡ�\n");
                  }
           setup();
}
